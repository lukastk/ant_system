WSTP=/usr/local/Wolfram/Mathematica/10.4/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions/
$WSTP/wsprep $1.tm -o ./build/$1tm.cpp
g++ -std=c++11 -static -c -m64 -I$WSTP -I/usr/local/boost_1_60_0/boost/ ./build/$1tm.cpp -o ./build/$1tm.o
g++ -std=c++11 -static -c -m64 -I$WSTP -I/usr/local/boost_1_60_0/boost/ $1.cpp -o ./build/$1.o
g++ -std=c++11 -static -m64 -I$WSTP -I/usr/local/boost_1_60_0/boost/ ./build/$1tm.o ./build/$1.o -L$WSTP -lWSTP64i4 -lm -lpthread -lrt -lstdc++ -ldl -luuid -o ./bin/$1
