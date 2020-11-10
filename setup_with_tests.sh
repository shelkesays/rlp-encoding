#!/usr/bin/env sh

BASEDIR=$(dirname "$0")

# Read the confifuration file
source "$BASEDIR/config.cfg"

# Build directory
BUILDDIR="$BASEDIR/$BUILD"
# Bin directory
BINDIR="$BASEDIR/$BIN"
# Libs directory
LIBSDIR="$BASEDIR/$LIBS"

# Test directory
TESTDIR="${BINDIR}/$TESTS"

# Delete existing build, bin and libs directory
if [ -d "$BUILDDIR" ]; then
    rm -rf "$BUILDDIR"
fi

if [ -d "$BINDIR" ]; then
    rm -rf "$BINDIR"
fi

if [ -d "$LIBSDIR" ]; then
    rm -rf "$LIBSDIR"
fi

# Create a new build directory
mkdir "$BUILDDIR"

# Create a build
cmake -H. -B"$BUILDDIR"

# Run build
cmake --build "$BUILDDIR"

# Run unit test cases.
echo "Running Unit Test Cases: "
if [ -d "$TESTDIR" ]; then
    echo "[SUCCESS]: Utils Test Case Execution starts: "
    "$TESTDIR/utilstest"
    echo "[SUCCESS]: Utils Test Case Execution ends: "
else
    echo "[ERROR]: Tests directory is not generated."
fi
echo "Unit Test Case execution complete."
