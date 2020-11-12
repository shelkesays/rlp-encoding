#!/usr/bin/env bash

echo "[Info]: Removing old build files."

# Delete existing build, bin and libs directory
if [ -d "$BUILDDIR" ]; then
    echo "[Remove]: $BUILDDIR"
    rm -rf "$BUILDDIR"
fi

if [ -d "$BINDIR" ]; then
    echo "[Remove]: $BINDIR"
    rm -rf "$BINDIR"
fi

if [ -d "$LIBSDIR" ]; then
    echo "[Remove]: $LIBSDIR"
    rm -rf "$LIBSDIR"
fi

echo "[Info]: Build process started."

# Create a new build directory
mkdir "$BUILDDIR"

# Create a build
cmake -H. -B"$BUILDDIR"

# Run build
cmake --build "$BUILDDIR"

echo "[Info]: Build process completed."