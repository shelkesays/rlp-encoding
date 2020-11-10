:: Windows setup script for building rlpencoding library and it's unit tests
@echo off
setlocal

SET BASEDIR=%~dp0
SET SOURCE=source

CALL :GETPARENT PARENT

:: Check which shell environrment is executing the script and 
:: depending on the shell environment change source command
IF /I "%PARENT%" == "powershell" (
    SET SOURCE=source
) ELSE IF /I "%PARENT%" == "pwsh" (
    SET SOURCE=source
) ELSE IF /I "%PARENT%" == "WindowsTerminal" (
    SET SOURCE=.
)

echo [RUNNING]: Script under %PARENT% environment

:: Read the confifuration file
FOR /f "eol=- delims=" %%a in (config.cfg) do SET "%%a"

:: Build directory
SET BUILDDIR=%BASEDIR%%BUILD%
:: Bin directory
SET BINDIR=%BASEDIR%%BIN%
:: Libs directory
SET LIBSDIR=%BASEDIR%%LIBS%

:: Test directory
SET TESTDIR=%BINDIR%\%TESTS%

:: Delete existing build, bin and libs directory
IF exist %BUILDDIR% (
    RMDIR /S /Q %BUILDDIR%
)

IF exist %BINDIR% (
    RMDIR /S /Q %BINDIR%
)

IF exist %LIBSDIR% (
    RMDIR /S /Q %LIBSDIR%
)

:: Create a new build directory
mkdir %BUILDDIR%

:: Create a build
cmake -H. -B%BUILDDIR%

:: Run build
cmake --build %BUILDDIR%

endlocal

GOTO :EOF

:: Function to get the environment
:GETPARENT
    SET "PSCMD=$ppid=$pid;while($i++ -lt 3 -and ($ppid=(Get-CimInstance Win32_Process -Filter ('ProcessID='+$ppid)).ParentProcessId)) {}; (Get-Process -EA Ignore -ID $ppid).Name"

    for /f "tokens=*" %%i in ('powershell -noprofile -command "%PSCMD%"') do SET %1=%%i

GOTO :EOF
