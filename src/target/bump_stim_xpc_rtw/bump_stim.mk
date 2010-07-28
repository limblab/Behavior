# Copyright 1996-2006 The MathWorks, Inc.
#
# File    : xpc_vc.tmf   $Revision: $ $Date: 2004/02/18 21:46:05 $
#
# Abstract:
#       Real-Time Workshop template makefile for building a WindowsNT-based
#       stand-alone generic real-time version of Simulink model using
#       generated C code and the
#          Microsoft Visual C/C++ compiler versions: 5.0, 6.0, 7.0
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#    OPT_OPTS       - Optimization option. Default is -O2. To enable
#                     debugging specify as OPT_OPTS=-Zd.
#    OPTS           - User specific options.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
HOST            = PC
BUILD           = yes
MAKECMD         = nmake
SYS_TARGET_FILE = xpctarget.tlc



#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE        - yes (1) or no (0): Build for external mode

MODEL           = bump_stim
MODULES         = bump_stim_capi.c bump_stim_data.c rt_atan2.c rt_logging.c rt_logging_mmi.c rt_matrx.c rt_nonfinite.c rt_printf.c rtw_modelmap_utils.c 
MAKEFILE        = bump_stim.mk
MATLAB_ROOT     = C:\Program Files\MATLAB\R2007a
ALT_MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2007a
MATLAB_BIN      = C:\Program Files\MATLAB\R2007a\bin
ALT_MATLAB_BIN  = C:\PROGRA~1\MATLAB\R2007a\bin
S_FUNCTIONS     = xpctimeinfo.c donipcie.c Byte2Bits.c dopci8255.c serPos.c enccbcioquadcount.c adnipcie.c mastercon_bs.c danipcie.c xpcudpbytesend.c
S_FUNCTIONS_LIB = 
NUMST           = 3
TID01EQ         = 1
NCSTATES        = 0
BUILDARGS       =  GENERATE_REPORT=1 ADD_MDL_NAME_TO_GLOBALS=1 EXT_MODE=1
MULTITASKING    = 1
EXT_MODE        = 0

MODELREFS       = 
SHARED_SRC      = 
SHARED_SRC_DIR  = 
SHARED_BIN_DIR  = 
SHARED_LIB      = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = bump_stimlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# ..\..\..\..\..\..\.. or .. or even . if you want it
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif
#--------------------------- Tool Specifications ------------------------------

!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths
MATLAB_INCLUDES = $(MATLAB_INCLUDES);C:\DOCUME~1\David\Desktop\Behavior\trunk\src\target\BUMP_S~1
MATLAB_INCLUDES = $(MATLAB_INCLUDES);C:\DOCUME~1\David\Desktop\Behavior\trunk\src\target
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\dspblks\include


XPC_INCLUDES    = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\include;.
XPC_INCLUDES    = $(XPC_INCLUDES);$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include
INCLUDE         = .;..;$(XPC_INCLUDES);$(MATLAB_INCLUDES);$(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#----------------- Compiler and Linker Options --------------------------------


# Optimization Options
#   Set  OPT_OPTS=-Zd  for debugging
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =
#/GD

CC_OPTS = $(OPT_OPTS) $(OPTS) /c /O2 /nologo



CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMT=$(MULTITASKING) -DHAVESTDIO -DXPCMSVISUALC \
		  -DXPCCALLCONV=  -DUSE_RTMODEL -DERT_CORE

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS = $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) $(cvarsmt) $(CFLAGS_VERSPECIFIC)
CPPFLAGS = $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) \
	   $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC) /GX

LDFLAGS = /NOLOGO /DLL /SUBSYSTEM:CONSOLE /DEF:xpcvcdll.def $(EXT_LIB) /Include:_malloc

#----------------------------- Source Files -----------------------------------
#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm
REQ_SRCS  = $(MODEL).c $(MODULES) xpctarget.c

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif


USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)
#------------------------------ CAN LIBRARIES --------------------------------
!include xpcextralibs.mk

# ------------------------- Additional Libraries ------------------------------

LIBS =

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\dspblks\lib\win32\dsp_rt_vc.lib
!else
LIBS = $(LIBS) dsp_rt.lib
!endif 
!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_vc.lib
!else
LIBS = $(LIBS) rtwlib.lib
!endif 

LIBS = $(LIBS) xpcruntime.lib

CANLIB =
!ifdef CANAC2_C200
CANLIB = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2s_vc.lib
!endif
!ifdef CANAC2_527
CANLIB = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2e_vc.lib
!endif
!ifdef CANAC2_1000
CANLIB = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb1_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb2_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb3_vc.lib
!endif
!ifdef CANAC2_1000_MB
CANLIB = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb1_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb2_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2pci_mb3_vc.lib
!endif
!ifdef CANAC2_104
CANLIB = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2104_mb1_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2104_mb2_vc.lib \
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\lib\xpccanac2104_mb3_vc.lib
!endif

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules --------------------------------------
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
..\$(MODEL).dlm : $(MODEL).dll
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\xpc\bin\mkusrdlm -c+ -q+ -g- $(MODEL).dll ..\$(MODEL)
	@echo ### Created DLM $@
#	@del $(MODEL).dll
#	@del $(MODEL).pdb

$(MODEL).dll : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS) $(MODELREF_LINK_LIBS)
	$(LD) $(LDFLAGS) $(LIBS) $(S_FUNCTIONS_LIB) $(CANLIB) $(SHARED_LIB) @$(CMD_FILE) -out:$@
	@del $(CMD_FILE)
	@echo ### Created DLL $@

!else
#--- Model reference RTW Target ---
$(PRODUCT) : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS)
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@echo ### Created static library $(MODELLIB)
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

xpcruntime.lib: xpcimports.obj xpcPCFunctions.obj
	$(LIBCMD) /nologo /out:$@ $**

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspacf}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspallpole}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspavi}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspbiquad}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspblms}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspburg}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspchol}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspconvcorr}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspdct}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspendian}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspeph}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfbsub}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfft}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfilterbank}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfir}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspg711}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspgivensrot}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsphist}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspic}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspiir}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspinterp}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspisfinite}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspldl}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplms}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplpc2cc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplsp2poly}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplu}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspmmutils}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppinv}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppoly2lsf}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppolyval}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspqrdc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspqsrt}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprandsrc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprc2ac}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprc2lpc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprebuff}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspsvd}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspunwrap}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspupfir}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspvfdly}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\include}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\modver}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\rtw\c\libsrc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspacf}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspallpole}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspavi}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspbiquad}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspblms}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspburg}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspchol}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspconvcorr}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspdct}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspendian}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspeph}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfbsub}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfft}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfilterbank}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspfir}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspg711}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspgivensrot}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsphist}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspic}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspiir}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspinterp}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspisfinite}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspldl}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplms}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplpc2cc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplsp2poly}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsplu}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspmmutils}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppinv}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppoly2lsf}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsppolyval}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspqrdc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspqsrt}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprandsrc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprc2ac}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprc2lpc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dsprebuff}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspsvd}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspunwrap}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspupfir}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\dspvfdly}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\include}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\dspblks\c\modver}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\libsrc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

# Libraries:



MODULES_dsp_rt = \
	acf_fd_c_rt.obj \
	acf_fd_d_rt.obj \
	acf_fd_r_rt.obj \
	acf_fd_z_rt.obj \
	acf_fft_interleave_zpad_d_rt.obj \
	acf_fft_interleave_zpad_r_rt.obj \
	acf_td_c_rt.obj \
	acf_td_d_rt.obj \
	acf_td_r_rt.obj \
	acf_td_z_rt.obj \
	copy_and_zero_pad_cc_nchan_rt.obj \
	copy_and_zero_pad_zz_nchan_rt.obj \
	allpole_df_a0scale_cc_rt.obj \
	allpole_df_a0scale_cr_rt.obj \
	allpole_df_a0scale_dd_rt.obj \
	allpole_df_a0scale_dz_rt.obj \
	allpole_df_a0scale_rc_rt.obj \
	allpole_df_a0scale_rr_rt.obj \
	allpole_df_a0scale_zd_rt.obj \
	allpole_df_a0scale_zz_rt.obj \
	allpole_df_cc_rt.obj \
	allpole_df_cr_rt.obj \
	allpole_df_dd_rt.obj \
	allpole_df_dz_rt.obj \
	allpole_df_rc_rt.obj \
	allpole_df_rr_rt.obj \
	allpole_df_zd_rt.obj \
	allpole_df_zz_rt.obj \
	allpole_lat_cc_rt.obj \
	allpole_lat_cr_rt.obj \
	allpole_lat_dd_rt.obj \
	allpole_lat_dz_rt.obj \
	allpole_lat_rc_rt.obj \
	allpole_lat_rr_rt.obj \
	allpole_lat_zd_rt.obj \
	allpole_lat_zz_rt.obj \
	allpole_tdf_a0scale_cc_rt.obj \
	allpole_tdf_a0scale_cr_rt.obj \
	allpole_tdf_a0scale_dd_rt.obj \
	allpole_tdf_a0scale_dz_rt.obj \
	allpole_tdf_a0scale_rc_rt.obj \
	allpole_tdf_a0scale_rr_rt.obj \
	allpole_tdf_a0scale_zd_rt.obj \
	allpole_tdf_a0scale_zz_rt.obj \
	allpole_tdf_cc_rt.obj \
	allpole_tdf_cr_rt.obj \
	allpole_tdf_dd_rt.obj \
	allpole_tdf_dz_rt.obj \
	allpole_tdf_rc_rt.obj \
	allpole_tdf_rr_rt.obj \
	allpole_tdf_zd_rt.obj \
	allpole_tdf_zz_rt.obj \
	avi_rt.obj \
	bq5_df2t_1fpf_1sos_cc_rt.obj \
	bq5_df2t_1fpf_1sos_cr_rt.obj \
	bq5_df2t_1fpf_1sos_dd_rt.obj \
	bq5_df2t_1fpf_1sos_dz_rt.obj \
	bq5_df2t_1fpf_1sos_rc_rt.obj \
	bq5_df2t_1fpf_1sos_rr_rt.obj \
	bq5_df2t_1fpf_1sos_zd_rt.obj \
	bq5_df2t_1fpf_1sos_zz_rt.obj \
	bq5_df2t_1fpf_nsos_cc_rt.obj \
	bq5_df2t_1fpf_nsos_cr_rt.obj \
	bq5_df2t_1fpf_nsos_dd_rt.obj \
	bq5_df2t_1fpf_nsos_dz_rt.obj \
	bq5_df2t_1fpf_nsos_rc_rt.obj \
	bq5_df2t_1fpf_nsos_rr_rt.obj \
	bq5_df2t_1fpf_nsos_zd_rt.obj \
	bq5_df2t_1fpf_nsos_zz_rt.obj \
	blms_an_wn_cc_rt.obj \
	blms_an_wn_dd_rt.obj \
	blms_an_wn_rr_rt.obj \
	blms_an_wn_zz_rt.obj \
	blms_an_wy_cc_rt.obj \
	blms_an_wy_dd_rt.obj \
	blms_an_wy_rr_rt.obj \
	blms_an_wy_zz_rt.obj \
	blms_ay_wn_cc_rt.obj \
	blms_ay_wn_dd_rt.obj \
	blms_ay_wn_rr_rt.obj \
	blms_ay_wn_zz_rt.obj \
	blms_ay_wy_cc_rt.obj \
	blms_ay_wy_dd_rt.obj \
	blms_ay_wy_rr_rt.obj \
	blms_ay_wy_zz_rt.obj \
	burg_a_c_rt.obj \
	burg_a_d_rt.obj \
	burg_a_r_rt.obj \
	burg_a_z_rt.obj \
	burg_ak_c_rt.obj \
	burg_ak_d_rt.obj \
	burg_ak_r_rt.obj \
	burg_ak_z_rt.obj \
	burg_k_c_rt.obj \
	burg_k_d_rt.obj \
	burg_k_r_rt.obj \
	burg_k_z_rt.obj \
	chol_c_rt.obj \
	chol_d_rt.obj \
	chol_r_rt.obj \
	chol_z_rt.obj \
	conv_td_cc_rt.obj \
	conv_td_dd_rt.obj \
	conv_td_dz_rt.obj \
	conv_td_rc_rt.obj \
	conv_td_rr_rt.obj \
	conv_td_zz_rt.obj \
	copy_and_zpad_cc_rt.obj \
	copy_and_zpad_dz_rt.obj \
	copy_and_zpad_rc_rt.obj \
	copy_and_zpad_zz_rt.obj \
	corr_td_cc_rt.obj \
	corr_td_cr_rt.obj \
	corr_td_dd_rt.obj \
	corr_td_dz_rt.obj \
	corr_td_rc_rt.obj \
	corr_td_rr_rt.obj \
	corr_td_zd_rt.obj \
	corr_td_zz_rt.obj \
	br_c_ip_rt.obj \
	br_c_op_rt.obj \
	br_d_ip_rt.obj \
	br_d_op_rt.obj \
	br_r_ip_rt.obj \
	br_r_op_rt.obj \
	br_z_ip_rt.obj \
	br_z_op_rt.obj \
	copy_col_as_row_br_c_rt.obj \
	copy_col_as_row_br_d_rt.obj \
	copy_col_as_row_br_r_rt.obj \
	copy_col_as_row_br_z_rt.obj \
	copy_col_as_row_d_rt.obj \
	copy_col_as_row_r_rt.obj \
	copy_row_as_col_br_d_rt.obj \
	copy_row_as_col_br_r_rt.obj \
	copy_row_as_col_d_rt.obj \
	copy_row_as_col_r_rt.obj \
	dct_br_d_4_rt.obj \
	dct_br_r_4_rt.obj \
	dct_br_rt.obj \
	dct_c_4_rt.obj \
	dct_c_8_rt.obj \
	dct_c_rt.obj \
	dct_d_4_rt.obj \
	dct_d_8_rt.obj \
	dct_d_rt.obj \
	dct_dbr_8_rt.obj \
	dct_r_4_rt.obj \
	dct_r_8_rt.obj \
	dct_r_rt.obj \
	dct_rbr_8_rt.obj \
	dct_tbl_c_4_rt.obj \
	dct_tbl_c_8_rt.obj \
	dct_tbl_c_rt.obj \
	dct_tbl_d_4_rt.obj \
	dct_tbl_d_8_rt.obj \
	dct_tbl_d_rt.obj \
	dct_tbl_dbr_8_rt.obj \
	dct_tbl_r_4_rt.obj \
	dct_tbl_r_8_rt.obj \
	dct_tbl_r_rt.obj \
	dct_tbl_z_4_rt.obj \
	dct_tbl_z_8_rt.obj \
	dct_tbl_z_rt.obj \
	dct_z_4_rt.obj \
	dct_z_8_rt.obj \
	dct_z_rt.obj \
	idct_c_4_rt.obj \
	idct_c_8_rt.obj \
	idct_c_rt.obj \
	idct_d_4_rt.obj \
	idct_d_8_rt.obj \
	idct_d_rt.obj \
	idct_r_4_rt.obj \
	idct_r_8_rt.obj \
	idct_r_rt.obj \
	idct_tbl_c_4_rt.obj \
	idct_tbl_c_8_rt.obj \
	idct_tbl_c_rt.obj \
	idct_tbl_d_4_rt.obj \
	idct_tbl_d_8_rt.obj \
	idct_tbl_d_rt.obj \
	idct_tbl_r_4_rt.obj \
	idct_tbl_r_8_rt.obj \
	idct_tbl_r_rt.obj \
	idct_tbl_z_4_rt.obj \
	idct_tbl_z_8_rt.obj \
	idct_tbl_z_rt.obj \
	idct_z_4_rt.obj \
	idct_z_8_rt.obj \
	idct_z_rt.obj \
	is_little_endian_rt.obj \
	eph_zc_fcn_rt.obj \
	bsub_nu_cc_c_rt.obj \
	bsub_nu_cr_c_rt.obj \
	bsub_nu_dd_d_rt.obj \
	bsub_nu_dz_z_rt.obj \
	bsub_nu_rc_c_rt.obj \
	bsub_nu_rr_r_rt.obj \
	bsub_nu_zd_z_rt.obj \
	bsub_nu_zz_z_rt.obj \
	bsub_rd_cc_c_rt.obj \
	bsub_rd_cr_c_rt.obj \
	bsub_rd_zd_z_rt.obj \
	bsub_rd_zz_z_rt.obj \
	bsub_u_cc_c_rt.obj \
	bsub_u_cr_c_rt.obj \
	bsub_u_dd_d_rt.obj \
	bsub_u_dz_z_rt.obj \
	bsub_u_rc_c_rt.obj \
	bsub_u_rr_r_rt.obj \
	bsub_u_zd_z_rt.obj \
	bsub_u_zz_z_rt.obj \
	fsub_nu_cc_c_rt.obj \
	fsub_nu_cr_c_rt.obj \
	fsub_nu_dd_d_rt.obj \
	fsub_nu_dz_z_rt.obj \
	fsub_nu_rc_c_rt.obj \
	fsub_nu_rr_r_rt.obj \
	fsub_nu_zd_z_rt.obj \
	fsub_nu_zz_z_rt.obj \
	fsub_rd_cc_c_rt.obj \
	fsub_rd_cr_c_rt.obj \
	fsub_rd_zd_z_rt.obj \
	fsub_rd_zz_z_rt.obj \
	fsub_u_cc_c_rt.obj \
	fsub_u_cr_c_rt.obj \
	fsub_u_dd_d_rt.obj \
	fsub_u_dz_z_rt.obj \
	fsub_u_rc_c_rt.obj \
	fsub_u_rr_r_rt.obj \
	fsub_u_zd_z_rt.obj \
	fsub_u_zz_z_rt.obj \
	copy_adjrow_intcol_br_c_rt.obj \
	copy_adjrow_intcol_br_z_rt.obj \
	copy_adjrow_intcol_c_rt.obj \
	copy_adjrow_intcol_z_rt.obj \
	copy_col_as_row_c_rt.obj \
	copy_col_as_row_z_rt.obj \
	copy_row_as_col_br_c_rt.obj \
	copy_row_as_col_br_dz_rt.obj \
	copy_row_as_col_br_rc_rt.obj \
	copy_row_as_col_br_z_rt.obj \
	copy_row_as_col_c_rt.obj \
	copy_row_as_col_dz_rt.obj \
	copy_row_as_col_rc_rt.obj \
	copy_row_as_col_z_rt.obj \
	fft_dbllen_tbl_c_rt.obj \
	fft_dbllen_tbl_z_rt.obj \
	fft_dbllen_trig_c_rt.obj \
	fft_dbllen_trig_z_rt.obj \
	fft_dblsig_br_c_rt.obj \
	fft_dblsig_br_z_rt.obj \
	fft_dblsig_c_rt.obj \
	fft_dblsig_z_rt.obj \
	fft_interleave_br_d_rt.obj \
	fft_interleave_br_r_rt.obj \
	fft_interleave_d_rt.obj \
	fft_interleave_r_rt.obj \
	fft_r2br_c_oop_rt.obj \
	fft_r2br_c_rt.obj \
	fft_r2br_dz_oop_rt.obj \
	fft_r2br_rc_oop_rt.obj \
	fft_r2br_z_oop_rt.obj \
	fft_r2br_z_rt.obj \
	fft_r2dif_tblm_c_rt.obj \
	fft_r2dif_tblm_z_rt.obj \
	fft_r2dif_tbls_c_rt.obj \
	fft_r2dif_tbls_z_rt.obj \
	fft_r2dif_trig_c_rt.obj \
	fft_r2dif_trig_z_rt.obj \
	fft_r2dit_tblm_c_rt.obj \
	fft_r2dit_tblm_z_rt.obj \
	fft_r2dit_tbls_c_rt.obj \
	fft_r2dit_tbls_z_rt.obj \
	fft_r2dit_trig_c_rt.obj \
	fft_r2dit_trig_z_rt.obj \
	fft_scaledata_dd_rt.obj \
	fft_scaledata_dz_rt.obj \
	fft_scaledata_rc_rt.obj \
	fft_scaledata_rr_rt.obj \
	ifft_addcssignals_c_c_oop_rt.obj \
	ifft_addcssignals_c_cbr_oop_rt.obj \
	ifft_addcssignals_d_z_oop_rt.obj \
	ifft_addcssignals_d_zbr_oop_rt.obj \
	ifft_addcssignals_r_c_oop_rt.obj \
	ifft_addcssignals_r_cbr_oop_rt.obj \
	ifft_addcssignals_z_z_oop_rt.obj \
	ifft_addcssignals_z_zbr_oop_rt.obj \
	ifft_dbllen_tbl_c_cbr_oop_rt.obj \
	ifft_dbllen_tbl_cbr_cbr_oop_rt.obj \
	ifft_dbllen_tbl_d_zbr_oop_rt.obj \
	ifft_dbllen_tbl_dbr_zbr_oop_rt.obj \
	ifft_dbllen_tbl_r_cbr_oop_rt.obj \
	ifft_dbllen_tbl_rbr_cbr_oop_rt.obj \
	ifft_dbllen_tbl_z_zbr_oop_rt.obj \
	ifft_dbllen_tbl_zbr_zbr_oop_rt.obj \
	ifft_dbllen_trig_c_cbr_oop_rt.obj \
	ifft_dbllen_trig_cbr_cbr_oop_rt.obj \
	ifft_dbllen_trig_d_zbr_oop_rt.obj \
	ifft_dbllen_trig_dbr_zbr_oop_rt.obj \
	ifft_dbllen_trig_r_cbr_oop_rt.obj \
	ifft_dbllen_trig_rbr_cbr_oop_rt.obj \
	ifft_dbllen_trig_z_zbr_oop_rt.obj \
	ifft_dbllen_trig_zbr_zbr_oop_rt.obj \
	ifft_deinterleave_d_d_inp_rt.obj \
	ifft_deinterleave_r_r_inp_rt.obj \
	2chabank_fr_df_cc_rt.obj \
	2chabank_fr_df_cr_rt.obj \
	2chabank_fr_df_dd_rt.obj \
	2chabank_fr_df_rr_rt.obj \
	2chabank_fr_df_zd_rt.obj \
	2chabank_fr_df_zz_rt.obj \
	2chsbank_df_cc_rt.obj \
	2chsbank_df_cr_rt.obj \
	2chsbank_df_dd_rt.obj \
	2chsbank_df_rr_rt.obj \
	2chsbank_df_zd_rt.obj \
	2chsbank_df_zz_rt.obj \
	fir_df_cc_rt.obj \
	fir_df_cr_rt.obj \
	fir_df_dd_rt.obj \
	fir_df_dz_rt.obj \
	fir_df_rc_rt.obj \
	fir_df_rr_rt.obj \
	fir_df_zd_rt.obj \
	fir_df_zz_rt.obj \
	fir_lat_cc_rt.obj \
	fir_lat_cr_rt.obj \
	fir_lat_dd_rt.obj \
	fir_lat_dz_rt.obj \
	fir_lat_rc_rt.obj \
	fir_lat_rr_rt.obj \
	fir_lat_zd_rt.obj \
	fir_lat_zz_rt.obj \
	fir_tdf_cc_rt.obj \
	fir_tdf_cr_rt.obj \
	fir_tdf_dd_rt.obj \
	fir_tdf_dz_rt.obj \
	fir_tdf_rc_rt.obj \
	fir_tdf_rr_rt.obj \
	fir_tdf_zd_rt.obj \
	fir_tdf_zz_rt.obj \
	g711_enc_a_sat_rt.obj \
	g711_enc_a_wrap_rt.obj \
	g711_enc_mu_sat_rt.obj \
	g711_enc_mu_wrap_rt.obj \
	rotg_d_rt.obj \
	rotg_r_rt.obj \
	hist_binsearch_s08_rt.obj \
	hist_binsearch_s16_rt.obj \
	hist_binsearch_s32_rt.obj \
	hist_binsearch_u08_rt.obj \
	hist_binsearch_u16_rt.obj \
	hist_binsearch_u32_rt.obj \
	hist_c_rt.obj \
	hist_d_rt.obj \
	hist_r_rt.obj \
	hist_z_rt.obj \
	ic_copy_channel_rt.obj \
	ic_copy_matrix_rt.obj \
	ic_copy_scalar_rt.obj \
	ic_copy_vector_rt.obj \
	ic_old_copy_fcns_rt.obj \
	iir_df1_a0scale_cc_rt.obj \
	iir_df1_a0scale_cr_rt.obj \
	iir_df1_a0scale_dd_rt.obj \
	iir_df1_a0scale_dz_rt.obj \
	iir_df1_a0scale_rc_rt.obj \
	iir_df1_a0scale_rr_rt.obj \
	iir_df1_a0scale_zd_rt.obj \
	iir_df1_a0scale_zz_rt.obj \
	iir_df1_cc_rt.obj \
	iir_df1_cr_rt.obj \
	iir_df1_dd_rt.obj \
	iir_df1_dz_rt.obj \
	iir_df1_rc_rt.obj \
	iir_df1_rr_rt.obj \
	iir_df1_zd_rt.obj \
	iir_df1_zz_rt.obj \
	iir_df1t_a0scale_cc_rt.obj \
	iir_df1t_a0scale_cr_rt.obj \
	iir_df1t_a0scale_dd_rt.obj \
	iir_df1t_a0scale_dz_rt.obj \
	iir_df1t_a0scale_rc_rt.obj \
	iir_df1t_a0scale_rr_rt.obj \
	iir_df1t_a0scale_zd_rt.obj \
	iir_df1t_a0scale_zz_rt.obj \
	iir_df1t_cc_rt.obj \
	iir_df1t_cr_rt.obj \
	iir_df1t_dd_rt.obj \
	iir_df1t_dz_rt.obj \
	iir_df1t_rc_rt.obj \
	iir_df1t_rr_rt.obj \
	iir_df1t_zd_rt.obj \
	iir_df1t_zz_rt.obj \
	iir_df2_a0scale_cc_rt.obj \
	iir_df2_a0scale_cr_rt.obj \
	iir_df2_a0scale_dd_rt.obj \
	iir_df2_a0scale_dz_rt.obj \
	iir_df2_a0scale_rc_rt.obj \
	iir_df2_a0scale_rr_rt.obj \
	iir_df2_a0scale_zd_rt.obj \
	iir_df2_a0scale_zz_rt.obj \
	iir_df2_cc_rt.obj \
	iir_df2_cr_rt.obj \
	iir_df2_dd_rt.obj \
	iir_df2_dz_rt.obj \
	iir_df2_rc_rt.obj \
	iir_df2_rr_rt.obj \
	iir_df2_zd_rt.obj \
	iir_df2_zz_rt.obj \
	iir_df2t_a0scale_cc_rt.obj \
	iir_df2t_a0scale_cr_rt.obj \
	iir_df2t_a0scale_dd_rt.obj \
	iir_df2t_a0scale_dz_rt.obj \
	iir_df2t_a0scale_rc_rt.obj \
	iir_df2t_a0scale_rr_rt.obj \
	iir_df2t_a0scale_zd_rt.obj \
	iir_df2t_a0scale_zz_rt.obj \
	iir_df2t_cc_rt.obj \
	iir_df2t_cr_rt.obj \
	iir_df2t_dd_rt.obj \
	iir_df2t_dz_rt.obj \
	iir_df2t_rc_rt.obj \
	iir_df2t_rr_rt.obj \
	iir_df2t_zd_rt.obj \
	iir_df2t_zz_rt.obj \
	interp_fir_d_rt.obj \
	interp_fir_r_rt.obj \
	interp_lin_d_rt.obj \
	interp_lin_r_rt.obj \
	isfinite_d_rt.obj \
	isfinite_r_rt.obj \
	ldl_c_rt.obj \
	ldl_d_rt.obj \
	ldl_r_rt.obj \
	ldl_z_rt.obj \
	lms_an_wn_cc_rt.obj \
	lms_an_wn_dd_rt.obj \
	lms_an_wn_rr_rt.obj \
	lms_an_wn_zz_rt.obj \
	lms_an_wy_cc_rt.obj \
	lms_an_wy_dd_rt.obj \
	lms_an_wy_rr_rt.obj \
	lms_an_wy_zz_rt.obj \
	lms_ay_wn_cc_rt.obj \
	lms_ay_wn_dd_rt.obj \
	lms_ay_wn_rr_rt.obj \
	lms_ay_wn_zz_rt.obj \
	lms_ay_wy_cc_rt.obj \
	lms_ay_wy_dd_rt.obj \
	lms_ay_wy_rr_rt.obj \
	lms_ay_wy_zz_rt.obj \
	lmsn_an_wn_cc_rt.obj \
	lmsn_an_wn_dd_rt.obj \
	lmsn_an_wn_rr_rt.obj \
	lmsn_an_wn_zz_rt.obj \
	lmsn_an_wy_cc_rt.obj \
	lmsn_an_wy_dd_rt.obj \
	lmsn_an_wy_rr_rt.obj \
	lmsn_an_wy_zz_rt.obj \
	lmsn_ay_wn_cc_rt.obj \
	lmsn_ay_wn_dd_rt.obj \
	lmsn_ay_wn_rr_rt.obj \
	lmsn_ay_wn_zz_rt.obj \
	lmsn_ay_wy_cc_rt.obj \
	lmsn_ay_wy_dd_rt.obj \
	lmsn_ay_wy_rr_rt.obj \
	lmsn_ay_wy_zz_rt.obj \
	lmssd_an_wn_dd_rt.obj \
	lmssd_an_wn_rr_rt.obj \
	lmssd_an_wy_dd_rt.obj \
	lmssd_an_wy_rr_rt.obj \
	lmssd_ay_wn_dd_rt.obj \
	lmssd_ay_wn_rr_rt.obj \
	lmssd_ay_wy_dd_rt.obj \
	lmssd_ay_wy_rr_rt.obj \
	lmsse_an_wn_dd_rt.obj \
	lmsse_an_wn_rr_rt.obj \
	lmsse_an_wy_dd_rt.obj \
	lmsse_an_wy_rr_rt.obj \
	lmsse_ay_wn_dd_rt.obj \
	lmsse_ay_wn_rr_rt.obj \
	lmsse_ay_wy_dd_rt.obj \
	lmsse_ay_wy_rr_rt.obj \
	lmsss_an_wn_dd_rt.obj \
	lmsss_an_wn_rr_rt.obj \
	lmsss_an_wy_dd_rt.obj \
	lmsss_an_wy_rr_rt.obj \
	lmsss_ay_wn_dd_rt.obj \
	lmsss_ay_wn_rr_rt.obj \
	lmsss_ay_wy_dd_rt.obj \
	lmsss_ay_wy_rr_rt.obj \
	cc2lpc_d_rt.obj \
	cc2lpc_r_rt.obj \
	lpc2cc_d_rt.obj \
	lpc2cc_r_rt.obj \
	lsp2poly_evenord_d_rt.obj \
	lsp2poly_evenord_r_rt.obj \
	lsp2poly_oddord_d_rt.obj \
	lsp2poly_oddord_r_rt.obj \
	lu_c_rt.obj \
	lu_d_rt.obj \
	lu_r_rt.obj \
	lu_z_rt.obj \
	mmpcmaudio_rt.obj \
	mmrgb24convert2gray_rt.obj \
	mmrgb24convert_rt.obj \
	mmrgb24output_rt.obj \
	mmrgb24paddedoutput_rt.obj \
	pinv_c_rt.obj \
	pinv_d_rt.obj \
	pinv_r_rt.obj \
	pinv_z_rt.obj \
	poly2lsfn_d_rt.obj \
	poly2lsfn_r_rt.obj \
	poly2lsfr_d_rt.obj \
	poly2lsfr_r_rt.obj \
	poly2lsp_d_rt.obj \
	poly2lsp_r_rt.obj \
	polyval_cc_rt.obj \
	polyval_cr_rt.obj \
	polyval_dd_rt.obj \
	polyval_dz_rt.obj \
	polyval_rc_rt.obj \
	polyval_rr_rt.obj \
	polyval_zd_rt.obj \
	polyval_zz_rt.obj \
	qrcompqy_c_rt.obj \
	qrcompqy_d_rt.obj \
	qrcompqy_mixd_c_rt.obj \
	qrcompqy_mixd_z_rt.obj \
	qrcompqy_r_rt.obj \
	qrcompqy_z_rt.obj \
	qrdc_c_rt.obj \
	qrdc_d_rt.obj \
	qrdc_r_rt.obj \
	qrdc_z_rt.obj \
	qre_c_rt.obj \
	qre_d_rt.obj \
	qre_r_rt.obj \
	qre_z_rt.obj \
	qreslv_c_rt.obj \
	qreslv_d_rt.obj \
	qreslv_mixd_c_rt.obj \
	qreslv_mixd_z_rt.obj \
	qreslv_r_rt.obj \
	qreslv_z_rt.obj \
	sort_ins_idx_d_rt.obj \
	sort_ins_idx_r_rt.obj \
	sort_ins_idx_s08_rt.obj \
	sort_ins_idx_s16_rt.obj \
	sort_ins_idx_s32_rt.obj \
	sort_ins_idx_u08_rt.obj \
	sort_ins_idx_u16_rt.obj \
	sort_ins_idx_u32_rt.obj \
	sort_ins_val_d_rt.obj \
	sort_ins_val_r_rt.obj \
	sort_ins_val_s08_rt.obj \
	sort_ins_val_s16_rt.obj \
	sort_ins_val_s32_rt.obj \
	sort_ins_val_u08_rt.obj \
	sort_ins_val_u16_rt.obj \
	sort_ins_val_u32_rt.obj \
	sort_qk_idx_d_rt.obj \
	sort_qk_idx_r_rt.obj \
	sort_qk_idx_s08_rt.obj \
	sort_qk_idx_s16_rt.obj \
	sort_qk_idx_s32_rt.obj \
	sort_qk_idx_u08_rt.obj \
	sort_qk_idx_u16_rt.obj \
	sort_qk_idx_u32_rt.obj \
	sort_qk_val_d_rt.obj \
	sort_qk_val_r_rt.obj \
	sort_qk_val_s08_rt.obj \
	sort_qk_val_s16_rt.obj \
	sort_qk_val_s32_rt.obj \
	sort_qk_val_u08_rt.obj \
	sort_qk_val_u16_rt.obj \
	sort_qk_val_u32_rt.obj \
	srt_qid_findpivot_d_rt.obj \
	srt_qid_findpivot_r_rt.obj \
	srt_qid_partition_d_rt.obj \
	srt_qid_partition_r_rt.obj \
	srt_qkrec_c_rt.obj \
	srt_qkrec_d_rt.obj \
	srt_qkrec_r_rt.obj \
	srt_qkrec_z_rt.obj \
	randsrc_gc_c_rt.obj \
	randsrc_gc_d_rt.obj \
	randsrc_gc_r_rt.obj \
	randsrc_gc_z_rt.obj \
	randsrc_gz_c_rt.obj \
	randsrc_gz_d_rt.obj \
	randsrc_gz_r_rt.obj \
	randsrc_gz_z_rt.obj \
	randsrc_u_c_rt.obj \
	randsrc_u_d_rt.obj \
	randsrc_u_r_rt.obj \
	randsrc_u_z_rt.obj \
	randsrccreateseeds_32_rt.obj \
	randsrccreateseeds_64_rt.obj \
	randsrcinitstate_gc_32_rt.obj \
	randsrcinitstate_gc_64_rt.obj \
	randsrcinitstate_gz_rt.obj \
	randsrcinitstate_u_32_rt.obj \
	randsrcinitstate_u_64_rt.obj \
	lpc2ac_d_rt.obj \
	lpc2ac_r_rt.obj \
	rc2ac_d_rt.obj \
	rc2ac_r_rt.obj \
	lpc2rc_d_rt.obj \
	lpc2rc_r_rt.obj \
	rc2lpc_d_rt.obj \
	rc2lpc_r_rt.obj \
	buf_copy_frame_to_mem_OL_1ch_rt.obj \
	buf_copy_frame_to_mem_OL_rt.obj \
	buf_copy_input_to_output_1ch_rt.obj \
	buf_copy_input_to_output_rt.obj \
	buf_copy_scalar_to_mem_OL_1ch_rt.obj \
	buf_copy_scalar_to_mem_OL_rt.obj \
	buf_copy_scalar_to_mem_UL_1ch_rt.obj \
	buf_copy_scalar_to_mem_UL_rt.obj \
	buf_output_frame_1ch_rt.obj \
	buf_output_frame_rt.obj \
	buf_output_scalar_1ch_rt.obj \
	buf_output_scalar_rt.obj \
	svd_c_rt.obj \
	svd_d_rt.obj \
	svd_r_rt.obj \
	svd_z_rt.obj \
	svdcopy_rt.obj \
	unwrap_d_nrip_rt.obj \
	unwrap_d_nrop_rt.obj \
	unwrap_d_ripf_rt.obj \
	unwrap_d_rips_rt.obj \
	unwrap_d_ropf_rt.obj \
	unwrap_d_rops_rt.obj \
	unwrap_r_nrip_rt.obj \
	unwrap_r_nrop_rt.obj \
	unwrap_r_ripf_rt.obj \
	unwrap_r_rips_rt.obj \
	unwrap_r_ropf_rt.obj \
	unwrap_r_rops_rt.obj \
	upfir_copydata_rt.obj \
	upfir_df_dblbuf_cc_rt.obj \
	upfir_df_dblbuf_cr_rt.obj \
	upfir_df_dblbuf_dd_rt.obj \
	upfir_df_dblbuf_dz_rt.obj \
	upfir_df_dblbuf_rc_rt.obj \
	upfir_df_dblbuf_rr_rt.obj \
	upfir_df_dblbuf_zd_rt.obj \
	upfir_df_dblbuf_zz_rt.obj \
	vfdly_clip_d_rt.obj \
	vfdly_clip_r_rt.obj \
	vfdly_fir_c_rt.obj \
	vfdly_fir_d_rt.obj \
	vfdly_fir_r_rt.obj \
	vfdly_fir_z_rt.obj \
	vfdly_lin_c_rt.obj \
	vfdly_lin_d_rt.obj \
	vfdly_lin_r_rt.obj \
	vfdly_lin_z_rt.obj \


dsp_rt.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_dsp_rt)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_dsp_rt)
	@echo ### Created $@

MODULES_rtwlib = \
	rt_backsubcc_dbl.obj \
	rt_backsubcc_sgl.obj \
	rt_backsubrc_dbl.obj \
	rt_backsubrc_sgl.obj \
	rt_backsubrr_dbl.obj \
	rt_backsubrr_sgl.obj \
	rt_enab.obj \
	rt_forwardsubcc_dbl.obj \
	rt_forwardsubcc_sgl.obj \
	rt_forwardsubcr_dbl.obj \
	rt_forwardsubcr_sgl.obj \
	rt_forwardsubrc_dbl.obj \
	rt_forwardsubrc_sgl.obj \
	rt_forwardsubrr_dbl.obj \
	rt_forwardsubrr_sgl.obj \
	rt_hypot.obj \
	rt_hypot32.obj \
	rt_i32zcfcn.obj \
	rt_look.obj \
	rt_look1d.obj \
	rt_look1d32.obj \
	rt_look2d32_general.obj \
	rt_look2d32_normal.obj \
	rt_look2d_general.obj \
	rt_look2d_normal.obj \
	rt_look32.obj \
	rt_lu_cplx.obj \
	rt_lu_cplx_sgl.obj \
	rt_lu_real.obj \
	rt_lu_real_sgl.obj \
	rt_matdivcc_dbl.obj \
	rt_matdivcc_sgl.obj \
	rt_matdivcr_dbl.obj \
	rt_matdivcr_sgl.obj \
	rt_matdivrc_dbl.obj \
	rt_matdivrc_sgl.obj \
	rt_matdivrr_dbl.obj \
	rt_matdivrr_sgl.obj \
	rt_matmultandinccc_dbl.obj \
	rt_matmultandinccc_sgl.obj \
	rt_matmultandinccr_dbl.obj \
	rt_matmultandinccr_sgl.obj \
	rt_matmultandincrc_dbl.obj \
	rt_matmultandincrc_sgl.obj \
	rt_matmultandincrr_dbl.obj \
	rt_matmultandincrr_sgl.obj \
	rt_matmultcc_dbl.obj \
	rt_matmultcc_sgl.obj \
	rt_matmultcr_dbl.obj \
	rt_matmultcr_sgl.obj \
	rt_matmultrc_dbl.obj \
	rt_matmultrc_sgl.obj \
	rt_matmultrr_dbl.obj \
	rt_matmultrr_sgl.obj \
	rt_nrand.obj \
	rt_sat_div_int16.obj \
	rt_sat_div_int32.obj \
	rt_sat_div_int8.obj \
	rt_sat_div_uint16.obj \
	rt_sat_div_uint32.obj \
	rt_sat_div_uint8.obj \
	rt_sat_prod_int16.obj \
	rt_sat_prod_int32.obj \
	rt_sat_prod_int8.obj \
	rt_sat_prod_uint16.obj \
	rt_sat_prod_uint32.obj \
	rt_sat_prod_uint8.obj \
	rt_urand.obj \
	rt_zcfcn.obj \


rtwlib.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_rtwlib)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_rtwlib)
	@echo ### Created $@



# Put this rule last, otherwise nmake will check toolboxes first

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

xpctarget.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c xpcoptions.h
	@echo ### Compiling xpctarget.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{..}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@echo ### Creating $@
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ $?
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@echo ### $@ Created
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

xpcPCFunctions.obj xpcimports.obj: $(MAKEFILE) rtw_proj.tmw
