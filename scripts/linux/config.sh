#!/usr/bin/env bash
CONFIG="$BASEDIR/config.cfg"

echo "[Reading]: Configuration from \`$CONFIG\`"

# Read the confifuration file
"$SOURCE" "$CONFIG"

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

echo "[Info]: Setup configuration is complete."
