LIBS = -lglut -lGLU -lGL -lm
prim: main.c
	gcc -o Island3D *.c $(LIBS)