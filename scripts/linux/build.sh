#!/usr/bin/env bash

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
