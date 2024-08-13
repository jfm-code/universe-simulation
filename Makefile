CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: NBody test NBody.a

NBody: main.o CelestialBody.o Universe.o
	$(CC) $(CFLAGS) -o NBody main.o CelestialBody.o Universe.o $(LIBS)

NBody.a: CelestialBody.o Universe.o
	ar rcs NBody.a CelestialBody.o Universe.o

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp

Universe.o: Universe.cpp Universe.hpp
	$(CC) $(CFLAGS) -c Universe.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

lint: main.cpp
	cpplint main.cpp

test: CelestialBody.o Universe.o
	$(CC) $(CFLAGS) -o test test.cpp CelestialBody.o Universe.o $(LIBS)

clean: 
	rm *.o NBody test