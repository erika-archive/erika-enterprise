# ###*B*###
# ERIKA Enterprise - a tiny RTOS for small microcontrollers
# 
# Copyright (C) 2002-2008  Evidence Srl
# 
# This file is part of ERIKA Enterprise.
# 
# ERIKA Enterprise is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation, 
# (with a special exception described below).
# 
# Linking this code statically or dynamically with other modules is
# making a combined work based on this code.  Thus, the terms and
# conditions of the GNU General Public License cover the whole
# combination.
# 
# As a special exception, the copyright holders of this library give you
# permission to link this code with independent modules to produce an
# executable, regardless of the license terms of these independent
# modules, and to copy and distribute the resulting executable under
# terms of your choice, provided that you also meet, for each linked
# independent module, the terms and conditions of the license of that
# module.  An independent module is a module which is not derived from
# or based on this library.  If you modify this code, you may extend
# this exception to your version of the code, but you are not
# obligated to do so.  If you do not wish to do so, delete this
# exception statement from your version.
# 
# ERIKA Enterprise is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License version 2 for more details.
# 
# You should have received a copy of the GNU General Public License
# version 2 along with ERIKA Enterprise; if not, write to the
# Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA.
# ###*E*###
# ###*B*###
# Copyright (C) Roberto Bucher (SUPSI- Lugano)
#               Simone Mannori (Scilab / INRIA / DIGITEO)
#
# Copyright (C) METALAU Project (INRIA)
# ###*E*###
 
## Author: 2007 Mauro Marinoni
## CVS: $Id: cfg.mk,v 1.5 2008/07/18 11:24:24 pj Exp $

ifeq ($(findstring __LIB_SCICOS__,$(LIB_OPT)),__LIB_SCICOS__)

EE_VPATH += $(EEBASE)/contrib/scicos/src/pic30
EE_VPATH += $(EEBASE)/contrib/scicos/src/pic30/communication
EE_VPATH += $(EEBASE)/contrib/scicos/libsrc/rt
EE_VPATH += $(EEBASE)/contrib/scicos/libsrc/core

ifeq ($(findstring __RTD_CYGWIN__,$(EEOPT)), __RTD_CYGWIN__) 
ALLINCPATH += -I"$(shell cygpath -w $(EEBASE)/contrib/scicos/inc/core)"
ALLINCPATH += -I"$(shell cygpath -w $(EEBASE)/contrib/scicos/inc/pic30/communication)"
else
ALLINCPATH += -I$(EEBASE)/contrib/scicos/inc/core
ALLINCPATH += -I$(EEBASE)/contrib/scicos/inc/pic30/communication
endif

##
## Application files
##

 
ifeq ($(findstring __NIOS2__,$(EEOPT)) , __NIOS2__)

EE_SRCS +=     contrib/scicos/src/nios2/led.c \
               contrib/scicos/src/nios2/button.c \
               contrib/scicos/src/nios2/sevenseg.c 

endif

ifeq ($(findstring __EE_FLEX__,$(EEOPT)) , __EE_FLEX__)

##
## Add Scicos to the linker list of libs
##
OPT_LIBS += -lscicos

endif

endif




