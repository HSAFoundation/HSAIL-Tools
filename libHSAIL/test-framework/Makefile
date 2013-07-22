ifeq ($(OS),Windows_NT)
ifdef _GCC # windows & mingw
CC=gcc
FLAG=-O3 -o compare
EXE=compare.exe
OBJ=
else # mingw only
CC=cl.exe
FLAG=-Ox
EXE=compare.exe
OBJ=compare.obj
endif
else # linux & gcc
CC=gcc
FLAG=-O3 -o compare
EXE=compare
OBJ=
endif

compare: compare.c
	-$(CC) $(FLAG) compare.c >NUL 
clean: 
	rm -f $(EXE) $(OBJ) 
