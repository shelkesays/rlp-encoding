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
cmake -H. -B"$BUILD_DIR"

# Run build
cmake --build "$BUILD_DIR"