CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 
CFLAGSC = -std=c++11

HEADERS = loli_types.h loli_symbols.h loli_cons.h loli_prim.h loli_list.h
MAIN = loli_types.cpp loli_symbols.cpp loli_cons.cpp loli_prim.cpp loli_list.cpp loli_main.cpp

currentg: $(HEADERS)
	$(CC) $(CFLAGSG) -o currentg $(MAIN)

currentc: $(HEADERS)
	$(CLANG) $(CFLAGSC) -o currentc $(MAIN)
