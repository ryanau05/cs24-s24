CXX = g++ -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

test: Heap.o Point.o WordList.o
	${CXX} $^ -o $@

main: Heap.o Point.o WordList.o
	${CXX} $^ -o $@

Heap.o: Heap.h
Point.o: Point.cpp
WordList.o: WordList.h
test: test.cpp
main: main.cpp

clean:
	rm -f test *.o