#Makefile for a simple polynomial calculator

polyapp: poly.o polyapp.o utils.o
	gcc -o polyapp poly.o polyapp.o utils.o
poly.o: poly.c
	gcc -c poly.c
polyapp.o: polyapp.c
	gcc -c polyapp.c
utils.o: utils.c
	gcc -c utils.c
