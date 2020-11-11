#!/usr/bin/env bash

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
