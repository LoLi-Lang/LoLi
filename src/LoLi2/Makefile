CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 -Wall -Og -Wextra -g
CFLAGSC = -std=c++11 -Wall -O0 -Wextra -g

GC = -L/home/zshang/Program/LoLi/git/src/gc/build -lgc
GCINCLUDE = -I/home/zshang/Program/LoLi/git/src/gc/include

MAIN=\
     sexp.o\
     types.o

sexp.o:	loli_sexp.cpp include/loli_sexp.h

types.o: loli_types.cpp

currentg: 
	$(CC) $(CFLAGSG) $(GCINCLUDE) $(GC) -o currentg $(MAIN)

currentc:
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o currentc $(MAIN)

.PHONY: clean
clean:
	rm *~
