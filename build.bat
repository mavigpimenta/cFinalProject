if not exist "build" mkdir build

cd build
cmake  -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..\CMakeLists.txt
mingw32-make
cd ..
