#!/usr/bin/env sh

BASEDIR=$(dirname "$0")

# Build directory
BUILDDIR="$BASEDIR/build"
# Bin directory
BINDIR="$BASEDIR/bin"
# Libs directory
LIBSDIR="$BASEDIR/libs"

# Delete existing build, bin and libs directory
if [ -d "$LIBSDIR" ]; then
    rm -rf "$BUILDDIR"
fi

if [ -d "$LIBSDIR" ]; then
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
