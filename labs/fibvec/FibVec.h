#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

using namespace std;

class FibVec {

private:
  // Member Variables
  int mVec[0];
  int size = 2;

  // Helper Functions
  void resize(size_t size); // resizes vector to f(val)
  size_t fib_val(size_t val); // calculates f(val)

public:
  // Constructor and Destructor
  FibVec(); // constructor
  ~FibVec();

  // Member Functions
  size_t capacity() const; // return size of storage buffer
  size_t count() const; // return num of items in vector
  void insert(int val, size_t index); // inserts val at index
  int lookup(size_t index) const; // returns val at index
  int pop(); // removes and returns last value of vector
  void push(int val); // inserts val at end of vector
  int remove(size_t index);

};

#endif