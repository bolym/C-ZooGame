CC=g++
EXE_FILE=zoo

all: $ (EXE_FILE)

$ (EXE_FILE): sloth.o seaOtter.o monkey.o animal.o zoo.o sloth.hpp seaOtter.hpp monkey.hpp animal.hpp zoo.hpp zoo_tycoon.cpp
	$(CC) sloth.o seaOtter.o monkey.o animal.o zoo.o zoo_tycoon.cpp -std=c++11 -o $(EXE_FILE)

sloth.o: sloth.hpp sloth.cpp
	$(CC) -c sloth.cpp

seaOtter.o: seaOtter.hpp seaOtter.cpp
	$(CC) -c seaOtter.cpp

monkey.o: monkey.hpp monkey.cpp
	$(CC) -c monkey.cpp

animal.o: animal.hpp animal.cpp
	$(CC) -c animal.cpp

zoo.o: zoo.hpp zoo.cpp
	$(CC) -c zoo.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)
