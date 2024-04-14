#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

using namespace std;

class FibVec {

private:
  // Member Variables
  int *mVec = new int[1];
  int fib_size = 2;
  int size = 1;
  int num_values = 0;

  // Helper Functions
  size_t fib_val(size_t val) const; // calculates f(val) DONE
  void resize(int mVec[], int resize_val); // resizes vector to f(size) DONE

public:
  // Constructor and Destructor
  FibVec(); // constructor DONE
  ~FibVec();

  // Member Functions
  size_t capacity() const; // return size of storage buffer DONE
  size_t count() const; // return num of items in vector DONE
  void insert(int val, size_t index); // inserts val at index DONE
  int lookup(int index) const; // returns val at index DONE
  int pop(); // removes and returns last value of vector
  void push(int val); // inserts val at end of vector DONE
  int remove(size_t index);

};

#endif