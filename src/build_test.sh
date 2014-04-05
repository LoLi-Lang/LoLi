echo "G++: "
g++ -std=c++11 -o gcctest loli_symbols.cpp loli_types.cpp  loli_cons.cpp loli_main.cpp && ./gcctest

echo "CLANG++: "
clang++ -std=c++11 -o clangtest loli_symbols.cpp loli_types.cpp  loli_cons.cpp loli_main.cpp && ./clangtest
