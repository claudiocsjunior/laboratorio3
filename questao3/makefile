#Makefile for "jogoDoDado" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = ./build/main.o ./build/agencia.o ./build/contaCorrente.o ./build/movimentacao.o ./build/contaPoupanca.o ./build/conta.o 
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
./build/agencia.o:./include/agencia.h
	$(CC) $(CPPFLAGS) -c src/agencia.cpp -o $(BUILD)agencia.o
./build/contaCorrente.o:./include/contaCorrente.h
	$(CC) $(CPPFLAGS) -c src/contaCorrente.cpp -o $(BUILD)contaCorrente.o
./build/movimentacao.o:./include/movimentacao.h
	$(CC) $(CPPFLAGS) -c src/movimentacao.cpp -o $(BUILD)movimentacao.o	
./build/contaPoupanca.o:./include/contaPoupanca.h
	$(CC) $(CPPFLAGS) -c src/contaPoupanca.cpp -o $(BUILD)contaPoupanca.o
./build/conta.o:./include/conta.h
	$(CC) $(CPPFLAGS) -c src/conta.cpp -o $(BUILD)conta.o	
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 