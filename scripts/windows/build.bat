:: Get Windows shell environment details, i.e., powershell / Windows Terminale / pwsh

echo [Info]: Removing old build files

:: Delete existing build, bin and libs directory
IF exist %BUILDDIR% (
    echo [Remove]: %BUILDDIR%
    RMDIR /S /Q %BUILDDIR%
)

IF exist %BINDIR% (
    echo [Remove]: %BINDIR%
    RMDIR /S /Q %BINDIR%
)

IF exist %LIBSDIR% (
    echo [Remove]: %LIBSDIR%
    RMDIR /S /Q %LIBSDIR%
)

echo [Info]: Build process started

:: Create a new build directory
mkdir %BUILDDIR%

:: Create a build
cmake -H. -B%BUILDDIR%

:: Run build
cmake --build %BUILDDIR%

:: Build finished
echo [Info]: Build process completed
