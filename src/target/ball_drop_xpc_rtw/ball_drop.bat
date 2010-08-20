set MATLAB=C:\Program Files\MATLAB\R2007a
set MSVCDir=e:\program files\microsoft visual studio\vc98

set MSDevDir=e:\program files\microsoft visual studio\common\msdev98
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" INCLUDE "e:\program files\microsoft visual studio\vc98\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" PATH "e:\program files\microsoft visual studio\vc98\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSCommonDir=e:\program files\microsoft visual studio\common
call "C:\Program Files\MATLAB\R2007a\toolbox\rtw\rtw\private\vcvars32_600.bat"

:make
cd .
nmake -f ball_drop.mk  GENERATE_REPORT=0 ADD_MDL_NAME_TO_GLOBALS=1 EXT_MODE=1 VISUAL_VER=6.0
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
