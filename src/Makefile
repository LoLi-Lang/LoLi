CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 -Wall -Og -Wextra -g
CFLAGSC = -std=c++11 -Wall -O0 -Wextra -g

GC = -L/home/zshang/Program/LoLi/git/src/gc/build -lgc
GCINCLUDE = -I/home/zshang/Program/LoLi/git/src/gc/include

GTK_INCLUDE = gtkmm-3.0

MAIN = loli_types.cpp loli_symbols.cpp loli_cons.cpp loli_prim.cpp loli_list.cpp loli_ast.cpp loli_output.cpp loli_repl.cpp loli_read.cpp loli_parser.cpp loli_env.cpp loli_eval.cpp loli_apply.cpp loli_cbmi.cpp loli_main.cpp loli_lambda.cpp loli_def.cpp loli_file.cpp loli_set.cpp loli_cond.cpp

GUI = loli_gui.cpp
GUI_H = header/loli_gui.h

currentg: 
	$(CC) $(CFLAGSG) $(GCINCLUDE) $(GC) -o currentg $(MAIN) $(GUI) `pkg-config --cflags --libs gtk+-3.0`

currentc:
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o currentc $(MAIN) $(GUI) `pkg-config --cflags --libs gtk+-3.0`

.PHONY: clean
clean:
	rm *~
