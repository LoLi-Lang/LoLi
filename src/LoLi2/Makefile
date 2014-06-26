CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 -Wall -Og -Wextra -g
CFLAGSC = -std=c++11 -Wall -O0 -Wextra -g

GC = -L/home/zshang/Program/LoLi/git/src/gc/build -lgc
GCINCLUDE = -I/home/zshang/Program/LoLi/git/src/gc/include

HEADERS = \
	  include/loli_obj.h\
	  include/loli_sexp.h

MAIN = \
     loli_obj.cpp\
     loli_sexp.cpp

TEST = \
       loli_obj.cpp\
       loli_sexp.cpp\
       loli2test.cpp

currentg: 
	$(CC) $(CFLAGSG) $(GCINCLUDE) $(GC) -o currentg $(MAIN)

currentc:
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o currentc $(MAIN)

test:	$(HEADERS)
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o test $(TEST)

.PHONY: clean
clean:
	rm *~
