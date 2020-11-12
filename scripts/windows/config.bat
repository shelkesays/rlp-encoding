:: Read the confifuration file
SET CONFIG=%BASEDIR%config.cfg

echo [Reading]: Configuration from %CONFIG%

FOR /f "eol=- delims=" %%a in (%CONFIG%) do SET "%%a"

:: Build directory
SET BUILDDIR=%BASEDIR%%BUILD%
:: Bin directory
SET BINDIR=%BASEDIR%%BIN%
:: Libs directory
SET LIBSDIR=%BASEDIR%%LIBS%

:: Test directory
SET TESTDIR=%BINDIR%\%TESTS%

echo [Info]: Setup configuration is complete