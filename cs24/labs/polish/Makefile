CXX = g++ -std=c++17 -g

test: Nodes.o AST.o Stack.o test.o
	${CXX} $^ -o $@

Nodes.o: Nodes.h
AST.o: AST.h
Stack.o: Stack.h
test.o: test.cpp

clean:
	rm -f test *.o