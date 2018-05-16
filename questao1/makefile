#Makefile for "jogoDoDado" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = ./build/main.o ./build/bebida.o ./build/fruta.o ./build/produto.o ./build/roupa.o 
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
./build/bebida.o:./include/bebida.h
	$(CC) $(CPPFLAGS) -c src/bebida.cpp -o $(BUILD)bebida.o
./build/fruta.o:./include/fruta.h
	$(CC) $(CPPFLAGS) -c src/fruta.cpp -o $(BUILD)fruta.o
./build/produto.o:./include/produto.h
	$(CC) $(CPPFLAGS) -c src/produto.cpp -o $(BUILD)produto.o
./build/roupa.o:./include/roupa.h
	$(CC) $(CPPFLAGS) -c src/roupa.cpp -o $(BUILD)roupa.o	
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 