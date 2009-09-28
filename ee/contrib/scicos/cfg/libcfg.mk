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

# Author: 2007- Mauro Marinoni
# 	  2009- Francesco Prosperi

ifeq ($(findstring __BUILD_ALL_LIBS__,$(EEOPT)) , __BUILD_ALL_LIBS__)
INCLUDE_SCICOS = YES
endif

ifeq ($(findstring __LIB_SCICOS__,$(LIB_OPT)) , __LIB_SCICOS__)
INCLUDE_SCICOS = YES
endif

##
## If the Scicos library is required
##

ifeq ($(INCLUDE_SCICOS), YES)

ifeq ($(findstring __RTD_CYGWIN__,$(EEOPT)), __RTD_CYGWIN__) 
EE_SCICOS_EVIDENCE_LIB_DIR_M := $(shell cygpath -u "$(ECLIPSE_HOME)"/Evidence/lib)
EE_SCICOS_EVIDENCE_LIB_DIR := $(shell cygpath -m "$(EE_SCICOS_EVIDENCE_LIB_DIR_M)")
else
EE_SCICOS_EVIDENCE_LIB_DIR := $(ECLIPSE_HOME)/Evidence/lib
endif

EE_OBJS_SCICOS_M := $(addprefix $(EE_SCICOS_EVIDENCE_LIB_DIR_M)/, $(patsubst %.c,%.o,$(patsubst %.S,%.o, $(EE_SRCS_SCICOS))))
EE_OBJS_SCICOS := $(addprefix $(EE_SCICOS_EVIDENCE_LIB_DIR)/, $(patsubst %.c,%.o,$(patsubst %.S,%.o, $(EE_SRCS_SCICOS))))

LIBSRCS += $(EE_SRCS_SCICOS)

$(EE_SCICOS_EVIDENCE_LIB_DIR_M)/%.o: %.c
#	@test -d  $(EE_SCICOS_EVIDENCE_LIB_DIR_M) || $(QUIET)mkdir -p $(EE_SCICOS_EVIDENCE_LIB_DIR_M)
	$(shell mkdir -p $(EE_SCICOS_EVIDENCE_LIB_DIR_M))
	$(VERBOSE_PRINTCPP) $(EE_CC) $(COMPUTED_OPT_CC) $(COMPUTED_ALLINCPATH) $(DEFS_CC) -c "$(SOURCEFILE)" -o $(TARGETFILE)

$(EE_SCICOS_EVIDENCE_LIB_DIR_M)/%.cd:	%.c
	$(VERBOSE_PRINTDEP) $(EE_DEP) $(COMPUTED_OPT_CC_DEPS) $(COMPUTED_ALLINCPATH) $(DEFS_CC) -M "$(SOURCEFILE)" > $(TARGETFILE).tmp
	@echo -n $(TARGETFILE) $(dir $(TARGETFILE)) | cat - $(TARGETFILE).tmp > $(TARGETFILE)
	@rm -rf $(TARGETFILE).tmp
	@test -s $(TARGETFILE) || rm -f $(TARGETFILE)
	
$(EE_SCICOS_EVIDENCE_LIB_DIR_M)/libscicos.a:	$(EE_OBJS_SCICOS_M)
	@printf "AR  libscicos.a\n" ;
	$(QUIET)$(EE_AR) rs $(EE_SCICOS_EVIDENCE_LIB_DIR)/libscicos.a $(EE_OBJS_SCICOS)

ALL_LIBS += $(EE_SCICOS_EVIDENCE_LIB_DIR_M)/libscicos.a
OPT_LIBS += -L$(EE_SCICOS_EVIDENCE_LIB_DIR)
		  
endif
