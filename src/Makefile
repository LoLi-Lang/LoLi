CC = g++
CLANG = clang++
CFLAGSG = -std=c++11 -Wall -Og -Wextra -g
CFLAGSC = -std=c++11 -Wall -O0 -Wextra -g

GC = -L/home/zshang/Program/LoLi/git/src/gc/build -lgc
GCINCLUDE = -I/home/zshang/Program/LoLi/git/src/gc/include

GTK_INCLUDE = gtkmm-3.0

HEADERS = loli_types.h loli_symbols.h loli_cons.h loli_prim.h loli_list.h loli_ast.h loli_gc.h loli_output.h loli_read.h loli_eval.h loli_env.h loli_parser.h loli.h loli_apply.h loli_cbmi.h 
MAIN = loli_types.cpp loli_symbols.cpp loli_cons.cpp loli_prim.cpp loli_list.cpp loli_ast.cpp loli_output.cpp loli_repl.cpp loli_read.cpp loli_parser.cpp loli_env.cpp loli_eval.cpp loli_apply.cpp loli_cbmi.cpp loli_main.cpp 

GUI = loli_gui.cpp
GUI_H = loli_gui.h

currentg: $(HEADERS) $(GCHEADER) $(GUI_H)
	$(CC) $(CFLAGSG) $(GCINCLUDE) $(GC) -o currentg $(MAIN) $(GUI) `pkg-config --cflags --libs gtk+-3.0`

currentc: $(HEADERS) $(GCHEADER) $(GUI_H)
	$(CLANG) $(CFLAGSC) $(GCINCLUDE) $(GC) -o currentc $(MAIN) $(GUI) `pkg-config --cflags --libs gtk+-3.0`
