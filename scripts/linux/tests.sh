#!/usr/bin/env bash

# Run unit test cases.
echo "[Running]: Unit Test Cases"
if [ -d "$TESTDIR" ]; then
    echo "[Info]: Utils Test Case Execution starts"
    "$TESTDIR/utilstest"
    echo "[Success]: Utils Test Case Execution ends"
else
    echo "[Error]: Tests directory is not generated"
fi
echo "[Info]: Unit Test Case execution complete"
