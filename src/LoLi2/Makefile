CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 -stdlib=libstdc++ -Wall -Og -Wextra -g
CFLAGSC = -std=c++11 -stdlib=libstdc++ -Wall -O0 -Wextra -g

HEADERS = \
	  include/loli_obj.h\
	  include/loli_util.h\
	  include/loli_eval.h\
	  include/loli_env.h\
	  include/loli_stack.h\
	  include/loli_typeclass.h\
	  include/loli_apply.h\
	  include/loli_lambda.h\
	  include/loli_prim.h\
	  include/loli_parser.h\
	  include/loli_repl.h\
	  include/loli_reader.h

MAIN = \
     loli_obj.cpp\
     loli_stack.cpp\
     loli_reader.cpp\
     loli_parser.cpp\
     loli_util.cpp\
     loli_env.cpp\
     loli_eval.cpp\
     loli_apply.cpp\
     loli_repl.cpp\
	 loli_typeclass.cpp\
     loli_main.cpp

TEST = \
       loli_obj.cpp\
       loli_util.cpp\
       loli_reader.cpp\
       loli_prim.cpp\
       loli_apply.cpp\
       loli_eval.cpp\
       loli_lambda.cpp\
       loli_env.cpp\
       loli_typeclass.cpp\
       loli_stack.cpp\
       loli_parser.cpp\
       loli2test.cpp

CURRENTG: 
	$(CC) $(CFLAGSG) -o currentg $(MAIN)

CURRENTC:
	$(CLANG) $(CFLAGSC) -o currentc $(MAIN)

TEST:	$(HEADERS)
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o test $(TEST)

.PHONY: clean
clean:
	rm *~
