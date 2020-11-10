BUILD_DIR="_build"
BIN_DIR="bin"
LIBS_DIR="libs"

# Delete existing build, bin and libs directory
rm -rf "$BUILD_DIR"
rm -rf "$BIN_DIR"
rm -rf "$LIBS_DIR"

# Create a new build directory
mkdir "$BUILD_DIR"

# Create a build
cmake -H. -B"$BUILD_DIR"  # -DCMAKE_INSTALL_PREFIX=_install

# Run build
cmake --build "$BUILD_DIR"

# Run unit test cases.
echo "Running Unit Test Cases: "
TEST_DIR="${BIN_DIR}/tests"
if [ -d "$TEST_DIR" ]; then
    echo "[SUCCESS]: Utils Test Case Execution starts: "
    ./"$TEST_DIR"/utilstest
    echo "[SUCCESS]: Utils Test Case Execution ends: "
else
    echo "[ERROR]: Test directory is not generated."
fi
echo "Unit Test Case execution complete."
