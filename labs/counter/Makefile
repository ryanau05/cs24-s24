CXX = g++ -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

main: Counter.o Index.o Iterator.o List.o Index.o
	${CXX} $^ -o $@

word-count: Counter.o Index.o Iterator.o List.o Index.o
	${CXX} $^ -o $@

char-count: Counter.o Index.o Iterator.o List.o Index.o
	${CXX} $^ -o $@

Counter.o: Counter.h
Index.o: Index.h
Iterator.o: Iterator.cpp
List.o: List.h
Index.o: Index.h
main: main.cpp
word-count: word-count.cpp
char-count: char-count.cpp

clean:
	rm -f main word-count char-count *.o