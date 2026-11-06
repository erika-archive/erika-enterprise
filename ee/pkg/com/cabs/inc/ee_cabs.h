/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2016  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation, 
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

/** \file	ee_cabs.h
 *  \brief	Cyclic Asynchronous Buffers (CABs) for the E.R.I.K.A. Project.
 *
 *  CABs are a way to exchange data between different threads.
 *
 *  In particular, every thread always read the latest version of the data
 *  that has been put in the CAB.
 *
 *  The number of buffers that have to be allocated into the CAB are given
 *  by the following formula:
 *
 *  1 + number of readers + number of writers
 *
 *  -------------------------------------------------------------
 *
 *  To limit the overall usage of RAM memory, the CAB descriptor 
 *  has been divided in two parts:
 *
 *  - ROM descriptor
 *  	That contains the minimum set of references to the RAM data,
 *  	plus the informations on the dimension and the number of buffers
 *  - RAM descriptor
 *  	That is composed by a set of arrays that contains the data to be
 *  	exchanged, and of a few other variables to store the CAB status.
 *
 *  -------------------------------------------------------------
 *
 *  Usage:
 *
 *  First, the CAB types have to be defined. These types are:
 *  - <b>EE_CAB_INDEX</b>:	An integer type that is used to index a single
 *  				buffer in the CAB
 *  - <b>EE_CAB_DATA</b>:	A type used for storing data; usually it is a
 *  				WORD
 *
 *  Every CAB buffer must be defined.
 *
 *  There are two ways to define the CAB buffer:
 *
 *  - using the macro DEFINE_CAB
 *  	That macro can be used to declare all the data structures needed.
 *  	Note that after defining it, it must be initialized calling
 *  	cab_init()
 *  - statically initializing the data structure
 *  	At the end of the development process, the macro can be substituted
 *  	with its preprocessor initialization, allowing a proper separation
 *  	between ROM and RAM parts; this way of initializing a CAB do not need
 *  	the call to cab_init, since the data structures can be initialized
 *  	inline.
 *
 *  Then you can use the cabs with the two pairs of functions that can be used
 *  to write message in the buffer / read the message in the buffer.
 *
 *  -------------------------------------------------------------
 *
 *  Compiling
 *
 *  To compile the CABS you should add EE_CABS__ in the EE_OPT variable of the
 *  conf.oil.
 *
 *  -------------------------------------------------------------
 *
 *  Optimized implementations:
 *
 *  Optimized implementations can be done. As usual, for each optimized version
 *  the corresponding symbol should be defined.
 *
 *  Valid symbols are:
 *  - <b>EE_PRIVATE_CAB_INIT__</b>
 *  - <b>EE_PRIVATE_CAB_RESERVE__</b>
 *  - <b>EE_PRIVATE_CAB_PUTMES__</b>
 *  - <b>EE_PRIVATE_CAB_GETMES__</b>
 *  - <b>EE_PRIVATE_CAB_UNGET__</b>
 *
 *  -------------------------------------------------------------
 *
 *  Multicore Environment:
 *
 *  - Multiple defining MACROs
 *  - SpinLocks Needed.
 *
 *  -------------------------------------------------------------
 *
 *  Memory Protection Environment:
 *
 *  They must be used by TRUSTED OS Applications.
 *
 *  -------------------------------------------------------------
 *
 * \author Paolo Gai
 * \date   2012
 * \author Giuseppe Serano
 * \date   2016
 */

#ifndef	EE_CABS_H
#define	EE_CABS_H

#include "ee.h"

/*
 * types
 */

/** \brief	CAB Buffer Index.
 *
 *  An integer type that is used to index a single buffer in the CAB
 */
#ifndef	EE_CAB_INDEX
#define	EE_CAB_INDEX	EE_UREG
#endif

/** \brief	CAB Data.
 *
 * A type used for storing data; usually it is a WORD.
 */
#ifndef	EE_CAB_DATA
#define	EE_CAB_DATA	EE_UREG
#endif


/** \brief	CAB RAM Descriptor.
 *
 *  Descriptor that is composed by a set of arrays that contains the data to be
 *  exchanged, and of a few other variables to store the CAB status.
 */
struct EE_cab_RAM_desc {
  EE_CAB_INDEX mrd;	/**< most recent data written on the CAB */
  EE_CAB_INDEX free;	/**< free buffer on the top of the stack */
};

/** \brief	CAB ROM Descriptor.
 *
 *  Descriptor that contains the minimum set of references to the RAM data,
 *  plus the informations on the dimension and the number of buffers.
 */
struct EE_cab_ROM_desc {
  /** Most recent data / free message pointer */
  struct EE_cab_RAM_desc * ram_desc;
  EE_CAB_INDEX		 * freestk;	/**< Free list pointer */
  EE_CAB_INDEX		 * used;	/**< CAB usage (pointer) */
  EE_CAB_DATA		 * msgs;	/**< Message buffers (pointer) */

  /** dimension of each buffer in the CAB */
  EE_CAB_INDEX		dim_msg;
  EE_CAB_INDEX		n_msg;		/**< number of messages in the CAB */

#ifdef	__MSRP__	/* Multicore */
  EE_TYPESPIN		sl_id;		/**< Spinlock ID */
#endif	/* __MSRP__ - Multicore */
};

#ifdef	__MSRP__	/* Multicore Environment */
/** \brief	CAB RAM Defining MACRO.
 *  \param	name:	CAB Identifier.
 *  \param	nmsg:	Number of Messages in the CAB
 *  			( 1 + number of readers + number of writers )
 *  \param	dimmsg:	Size of a CAB Messages in <b>EE_CAB_DATA</b> units
 *
 *  This macro can be used to initalize a CAB that contains a message.
 *
 *  The CAB is initialized with a starting message (the index 0).
 *
 *  \note	<b>freestk</b> has a dimension of the number of messages-1,
 *  		since a message (the <b>mrd</b>) is always allocated.
 *
 *  \note	Use this macro with MemMap.h has shown above:
 *
 *  #define SHARED_START_SEC_VAR_DATA
 *  #include "MemMap.h"
 *  EE_DEFINE_CAB_RAM( ... );
 *  #define SHARED_STOP_SEC_VAR_DATA
 *  #include "MemMap.h"
 */
#define	EE_DEFINE_CAB_RAM(name, nmsg, dimmsg, slid)		\
  struct EE_cab_RAM_desc name##_CABram = {nmsg-1, nmsg-1};

/** \brief	CAB NOINIT Defining MACRO.
 *  \param	name:	CAB Identifier.
 *  \param	nmsg:	Number of Messages in the CAB
 *  			( 1 + number of readers + number of writers )
 *  \param	dimmsg:	Size of a CAB Messages in <b>EE_CAB_DATA</b> units
 *
 *  This macro can be used to initalize a CAB that contains a message.
 *
 *  The CAB is initialized with a starting message (the index 0).
 *
 *  \note	<b>freestk</b> has a dimension of the number of messages-1,
 *  		since a message (the <b>mrd</b>) is always allocated.
 *
 *  \note	Use this macro with MemMap.h has shown above:
 *
 *  #define SHARED_START_SEC_VAR_NOINIT
 *  #include "MemMap.h"
 *  EE_DEFINE_CAB_NOINIT( ... );
 *  #define SHARED_STOP_SEC_VAR_NOINIT
 *  #include "MemMap.h"
 */
#define	EE_DEFINE_CAB_NOINIT(name, nmsg, dimmsg, slid)		\
  EE_CAB_INDEX name##_CABfreestk[nmsg-1];			\
  EE_CAB_INDEX name##_CABused[nmsg];				\
  EE_CAB_DATA name##_CABmsgs[nmsg*dimmsg];

/** \brief	CAB ROM Defining MACRO.
 *  \param	name:	CAB Identifier.
 *  \param	nmsg:	Number of Messages in the CAB
 *  			( 1 + number of readers + number of writers )
 *  \param	dimmsg:	Size of a CAB Messages in <b>EE_CAB_DATA</b> units
 *
 *  This macro can be used to initalize a CAB that contains a message.
 *
 *  The CAB is initialized with a starting message (the index 0).
 *
 *  \note	<b>freestk</b> has a dimension of the number of messages-1,
 *  		since a message (the <b>mrd</b>) is always allocated.
 *
 *  #define SHARED_START_SEC_CONST_DATA
 *  #include "MemMap.h"
 *  EE_DEFINE_CAB_ROM( ... );
 *  #define SHARED_STOP_SEC_CONST_DATA
 *  #include "MemMap.h"
 */
#define	EE_DEFINE_CAB_ROM(name, nmsg, dimmsg, slid)		\
  const struct EE_cab_ROM_desc name = {				\
    &name##_CABram,						\
    name##_CABfreestk,						\
    name##_CABused,						\
    name##_CABmsgs,						\
    dimmsg,							\
    nmsg,							\
    slid							\
  }
#else	/* __MSRP__ - Multicore Environment */
/** \brief	CAB Defining MACRO.
 *  \param	name:	CAB Identifier.
 *  \param	nmsg:	Number of Messages in the CAB
 *  			( 1 + number of readers + number of writers )
 *  \param	dimmsg:	Size of a CAB Messages in <b>EE_CAB_DATA</b> units
 *
 *  This macro can be used to initalize a CAB that contains a message.
 *
 *  The CAB is initialized with a starting message (the index 0).
 *
 *  \note	<b>freestk</b> has a dimension of the number of messages-1,
 *  		since a message (the <b>mrd</b>) is always allocated.
 */
#define	EE_DEFINE_CAB(name, nmsg, dimmsg)			\
  struct EE_cab_RAM_desc name##_CABram = {nmsg-1, nmsg-1};	\
  EE_CAB_INDEX name##_CABfreestk[nmsg-1];			\
  EE_CAB_INDEX name##_CABused[nmsg];				\
  EE_CAB_DATA name##_CABmsgs[nmsg*dimmsg];			\
  const struct EE_cab_ROM_desc name = {				\
    &name##_CABram,						\
    name##_CABfreestk,						\
    name##_CABused,						\
    name##_CABmsgs,						\
    dimmsg,							\
    nmsg							\
  }
#endif	/* __MSRP__ - Multicore Environment */

/* this to refer it as an extern variable */
/** \brief	CAB External Decralation.
 *
 *  This macro can be used to declare an external defined CAB.
 */
#define	EE_EXTERN_CAB(name)	extern const struct EE_cab_ROM_desc name

#ifdef	__EE_MEMORY_PROTECTION__
#define OS_START_SEC_CODE
#include "MemMap.h"
#endif	/* __EE_MEMORY_PROTECTION__ */

#ifndef	EE_PRIVATE_CAB_INIT__
/** \brief	CAB Initialization.
 *  \param	c: Pointer to CAB ROM Descriptor (MUST BE NOT NULL).
 *
 *  Initializes a CAB.
 */
void EE_cab_init(const struct EE_cab_ROM_desc *c);
#endif	/* EE_PRIVATE_CAB_INIT__ */

#ifndef	EE_PRIVATE_CAB_RESERVE__
/** \brief	CAB Message Reservation.
 *  \param	c: Pointer to CAB ROM Descriptor (MUST BE NOT NULL).
 *  \param	msg: Pointer to Reserved Message Buffer Pointer.
 *  \param	msg_num: Pointer to Reserved Message Buffer Index.
 *
 *  Reserve a CAB Message for Message Writing.
 */
void
EE_cab_reserve(
  const struct EE_cab_ROM_desc *c, void **msg, EE_CAB_INDEX *msg_num
);
#endif	/* EE_PRIVATE_CAB_RESERVE__ */

#ifndef	EE_PRIVATE_CAB_PUTMES__
/** \brief	CAB Message Commit.
 *  \param	c: Pointer to CAB ROM Descriptor (MUST BE NOT NULL).
 *  \param	msg_num: Pointer to Reserved Message Buffer Index.
 *
 *  Commit a Wrote Message into CAB.
 */
void EE_cab_putmes(const struct EE_cab_ROM_desc *c, EE_CAB_INDEX msg_num);
#endif	/* EE_PRIVATE_CAB_PUTMES__ */

#ifndef	EE_PRIVATE_CAB_GETMES__
/** \brief	CAB Message Retrieval.
 *  \param	c: Pointer to CAB ROM Descriptor (MUST BE NOT NULL).
 *  \param	msg: Pointer to Retrieved Message Buffer Pointer.
 *  \param	msg_num: Pointer to Retrieved Message Buffer Index.
 *
 *  Retrieve a CAB Message for Message Reading.
 */
void
EE_cab_getmes(
  const struct EE_cab_ROM_desc *c, void **msg, EE_CAB_INDEX *msg_num
);
#endif	/* EE_PRIVATE_CAB_GETMES__ */

#ifndef	EE_PRIVATE_CAB_UNGET__
/** \brief	CAB Message Pop.
 *  \param	c: Pointer to CAB ROM Descriptor (MUST BE NOT NULL).
 *  \param	msg: Pointer to Retrieved Message Buffer Pointer.
 *  \param	msg_num: Pointer to Retrieved Message Buffer Index.
 *
 *  Pop a Read CAB Message from CAB.
 */
void EE_cab_unget(const struct EE_cab_ROM_desc *c, EE_CAB_INDEX msg_num);
#endif	/* EE_PRIVATE_CAB_UNGET__ */

#ifdef	__EE_MEMORY_PROTECTION__
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif	/* __EE_MEMORY_PROTECTION__ */

#endif	/* EE_CABS_H */
