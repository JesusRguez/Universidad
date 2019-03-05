#
#

CXX = g++
CPPFLAGS = -DP0 -I../Tests-auto -I.
CXXFLAGS = -std=c++11 -Wall -pedantic -g
VPATH = ../Tests-auto:.

all: test-P0-auto test-P0-consola

test-P0-consola: test-P0-consola.o fecha.o cadena.o
	${CXX} -o $@ ${LDFLAGS} $^
	
test-P0-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o fecha.o cadena.o
	${CXX} -o $@ ${LDFLAGS} $^
	
test-caso0-fecha-auto.o test-caso0-cadena-auto.o: test-auto.hpp fecha.hpp cadena.hpp fct.h

fecha.o: fecha.hpp

cadena.o: cadena.hpp

test-P0-consola.o: fecha.hpp cadena.hpp

clean:
	${RM} test-P0-consola test-P0-auto *.o
