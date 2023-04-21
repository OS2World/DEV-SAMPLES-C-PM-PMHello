# make makefile
# 
# Tools used:
#  Compile::Resource Compiler
#  Compile::GNU C
#  Make: make
all : pmhello1.exe pmhello2.exe pmhello3.exe

pmhello1.exe : pmhello.obj pmhello1.obj pmhello.def
	gcc -Zomf pmhello.obj pmhello1.obj pmhello.def -o pmhello1.exe

pmhello2.exe : pmhello.obj pmhello2.obj pmhello.def
	gcc -Zomf pmhello.obj pmhello2.obj pmhello.def -o pmhello2.exe

pmhello3.exe : pmhello.obj pmhello3.obj pmhello.def
	gcc -Zomf pmhello.obj pmhello3.obj pmhello.def -o pmhello3.exe

pmhello.obj : pmhello.c
	gcc -Wall -Zomf -c -O2 pmhello.c -o pmhello.obj

pmhello1.obj : pmhello1.c
	gcc -Wall -Zomf -c -O2 pmhello1.c -o pmhello1.obj

pmhello2.obj : pmhello2.c
	gcc -Wall -Zomf -c -O2 pmhello2.c -o pmhello2.obj

pmhello3.obj : pmhello3.c
	gcc -Wall -Zomf -c -O2 pmhello3.c -o pmhello3.obj

clean :
	rm -rf *exe *RES *obj