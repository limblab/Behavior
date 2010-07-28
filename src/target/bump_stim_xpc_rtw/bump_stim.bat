set MATLAB=C:\Program Files\MATLAB\R2007a
set MSVCDir=c:\program files\microsoft visual studio 9.0\VC
set MSSdk=C:\Program Files\Microsoft Platform SDK\.
@if "%MSSdk%"=="" goto Usage1

"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" INCLUDE "C:\Program Files\Microsoft Platform SDK\.\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" PATH "C:\Program Files\Microsoft Platform SDK\.\bin"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" LIB "C:\Program Files\Microsoft Platform SDK\.\lib"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" LIBPATH "C:\Program Files\Microsoft Platform SDK\.\lib"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" INCLUDE "c:\program files\microsoft visual studio 9.0\VC\include"
if errorlevel 1 goto vcvars32
"C:\Program Files\MATLAB\R2007a\rtw\bin\win32\envcheck" PATH "c:\program files\microsoft visual studio 9.0\VC\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSINSTALLDIR=c:\program files\microsoft visual studio 9.0
set VCINSTALLDIR=c:\program files\microsoft visual studio 9.0\VC
set FrameworkSDKDir=c:\program files\microsoft visual studio 9.0\SDK\v2.0
set FrameworkDir=c:\program files\microsoft visual studio 9.0\Framework
call "C:\Program Files\MATLAB\R2007a\toolbox\rtw\rtw\private\vcvars32_800free.bat"

:make
cd .
nmake -f bump_stim.mk  GENERATE_REPORT=1 ADD_MDL_NAME_TO_GLOBALS=1 EXT_MODE=1 VISUAL_VER=8.0
@if errorlevel 1 goto error_exit
exit /B 0

:Usage1
@echo Error: Build with MSVC 8.0 express edition requires MSSdk being defined as the location of Microsoft platformSDK installation.
@goto error_exit

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
