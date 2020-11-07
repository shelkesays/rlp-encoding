rm -rf _build
mkdir _build
# cd _build
# cd _build
# make all
cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
cmake --build _build
# make
# make install
