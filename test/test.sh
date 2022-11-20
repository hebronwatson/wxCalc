rm -f Makefile CMakeCache.txt cmake_install.cmake a.out
cmake . 

$make_status = $(make)


if [[ -z $make_status ]]; then
    echo 'Build passed!'
    echo 'Running tests...'
    if [[ `uname` == "Darwin" ]]; then
        cd Test_Calc.app/Contents/MacOS
    fi
    ./Test_Calc
else
    echo 'Build failed. Tests will be skipped.'
fi