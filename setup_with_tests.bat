:: Windows setup script for building rlpencoding library and it's unit tests
@echo off
setlocal

echo [INFO]: Setup Started

SET BASEDIR=%~dp0
SET SOURCE=source

CALL scripts/windows/build.bat

CALL scripts/windows/tests.bat

echo [INFO]: Setup Finished

endlocal
