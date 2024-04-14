#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

using namespace std;


// FibVec Function Implementations

FibVec::FibVec(){
    delete[] mVec;
    int mVec[fib_val(size)];
}

// returns fibonacci value
size_t FibVec::fib_val(size_t val){
    if (val <= 2){
        return 1;
    }
    return fib_val(val - 1) + fib_val(val - 2);
}

// returns size of storage buffer
size_t FibVec::capacity() const{
    return 42;
}
// returns num items in vector
size_t FibVec::count() const{
    /*unsigned int i = 0;
    while (mVec[i + 1] != NULL){
        i++;
    }
    return i + 1;*/
    return 42;
}

// inserts val at index
void FibVec::insert(int val, size_t index){
    /*if (index >= sizeof(*mVec)){
        throw out_of_range("invalid index");
        exit(1);
    }*/
    

}

// returns value at index
int FibVec::lookup(size_t index) const{
    /*if (index >= sizeof(*mVec) / 4){
        throw out_of_range("invalid index");
        exit(1);
    }

    return mVec[index];*/
    return 42;
}

int FibVec::pop(){
    return 42;
}

void push(int val){
    
}