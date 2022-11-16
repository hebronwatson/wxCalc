rm -f Makefile CMakeCache.txt cmake_install.cmake a.out
cmake . 
make
if [[ `uname` == "Darwin" ]]; then
    cd Test_Calc.app/Contents/MacOS
fi
./Test_Calc
