:: Windows setup script for building rlpencoding library and it's unit tests
@echo off
setlocal

SET BASEDIR=%~dp0

:: Source command
SET SOURCE=source

:: Call function GETPARENT to get the environment
CALL :GETPARENT PARENT

:: Check which shell environment is executing the script and 
:: depending on the shell environment change source command
IF /I "%PARENT%" == "powershell" (
    SET SOURCE=source
) ELSE IF /I "%PARENT%" == "pwsh" (
    SET SOURCE=source
) ELSE IF /I "%PARENT%" == "WindowsTerminal" (
    SET SOURCE=.
)

echo [Running]: Script under %PARENT% environment

:: Execute the config configuration
CALL %BASEDIR%/scripts/windows/config.bat

:: Execute the build script
CALL %BASEDIR%/scripts/windows/build.bat

endlocal

GOTO :EOF


:: Function to get the environment
:GETPARENT
    SET "PSCMD=$ppid=$pid;while($i++ -lt 3 -and ($ppid=(Get-CimInstance Win32_Process -Filter ('ProcessID='+$ppid)).ParentProcessId)) {}; (Get-Process -EA Ignore -ID $ppid).Name"

    for /f "tokens=*" %%i in ('powershell -noprofile -command "%PSCMD%"') do SET %1=%%i

GOTO :EOF