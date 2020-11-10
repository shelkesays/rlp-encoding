#!/usr/bin/env bash

BASEDIR=$(dirname "$0")

# Source command
SOURCE="source"

# Check which shell environrment is executing the script and 
# depending on the shell environment change source command
if test -n "$ZSH_VERSION"; then
  PROFILE_SHELL=zsh
  SOURCE="$SOURCE"
elif test -n "$BASH_VERSION"; then
  PROFILE_SHELL=bash
  SOURCE="$SOURCE"
elif test -n "$KSH_VERSION"; then
  PROFILE_SHELL=ksh
  SOURCE="$SOURCE"
elif test -n "$FCEDIT"; then
  PROFILE_SHELL=ksh
  SOURCE="$SOURCE"
elif test -n "$PS3"; then
  PROFILE_SHELL=unknown
  SOURCE="$SOURCE"
else
  PROFILE_SHELL=sh
  SOURCE="$BASEDIR"
fi

echo "[RUNNING]: Script under \`$PROFILE_SHELL\` environment"

# Read the confifuration file
"$SOURCE" "$BASEDIR/config.cfg"

# Remove trailing \r and \n
BUILD=$(echo "$BUILD" | tr -d '\r' | tr -d '\n')
BIN=$(echo "$BIN" | tr -d '\r' | tr -d '\n')
LIBS=$(echo "$LIBS" | tr -d '\r' | tr -d '\n')
TESTS=$(echo "$TESTS" | tr -d '\r' | tr -d '\n')

# Build directory
BUILDDIR="$BASEDIR/$BUILD"
# Bin directory
BINDIR="$BASEDIR/$BIN"
# Libs directory
LIBSDIR="$BASEDIR/$LIBS"

# Test directory
TESTDIR="$BINDIR/$TESTS"

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
echo "[Running]: Unit Test Cases"
if [ -d "$TESTDIR" ]; then
    echo "[SUCCESS]: Utils Test Case Execution starts: "
    "$TESTDIR/utilstest"
    echo "[SUCCESS]: Utils Test Case Execution ends: "
else
    echo "[ERROR]: Tests directory is not generated."
fi
echo "Unit Test Case execution complete."
