@echo off

cmd /q /c cl.exe 2>&1 1>NUL
if errorlevel 1 goto GETVS
echo #cl.exe already in path >vsvars.inc
echo cl.exe already in path, not trying to auto-configure >&2
goto DONE

:GETVS
if NOT "%VCINSTALLDIR%"=="" goto GETVC
:VS110
if "%VS110COMNTOOLS%"=="" goto VS100
call "%VS110COMNTOOLS%\VCVarsQueryRegistry.bat"
goto GETVC

:VS100
if "%VS100COMNTOOLS%"=="" goto NONE
call "%VS100COMNTOOLS%\VCVarsQueryRegistry.bat"
goto GETVC

:NONE
echo Visual Studio installation not found. Please specify VCINSTALLDIR explicitly.
exit 1

:GETVC
echo Auto-configuring MSVC for %1 at %VCINSTALLDIR% >&2
call "%VCINSTALLDIR%\vcvarsall.bat" %1
echo export PATH:=%PATH:#=\#% >vsvars.inc
echo export LIB:=%LIB:#=\#% >>vsvars.inc
echo export LIBPATH:=%LIBPATH:#=\#% >>vsvars.inc
echo export INCLUDE:=%INCLUDE:#=\#% >>vsvars.inc

cmd /q /c cl.exe 2>&1 1>NUL

:DONE
