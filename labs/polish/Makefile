CXX = g++ -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter

test: Nodes.o AST.o Stack.o test.o
	${CXX} $^ -o $@
main: Nodes.o AST.o Stack.o main.o
	${CXX} $^ -o $@

Nodes.o: Nodes.h
AST.o: AST.h
Stack.o: Stack.h
test.o: test.cpp
main.o: main.cpp

clean:
	rm -f test main *.o