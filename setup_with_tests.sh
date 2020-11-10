BUILD_DIR="_build"
BIN_DIR="bin"
LIBS_DIR="libs"

# Delete existing build, bin and libs directory
if [ -d "$LIBS_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

if [ -d "$LIBS_DIR" ]; then
    rm -rf "$BIN_DIR"
fi

if [ -d "$LIBS_DIR" ]; then
    rm -rf "$LIBS_DIR"
fi

# Create a new build directory
mkdir "$BUILD_DIR"

# Create a build
cmake -H. -B"$BUILD_DIR"

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
