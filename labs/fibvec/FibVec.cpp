#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

using namespace std;


// FibVec Function Implementations

FibVec::FibVec(){

}

FibVec::~FibVec(){
    delete[] mVec;
}

size_t FibVec::fib_val(size_t val) const{
    if (val <= 2){
        return 1;
    }
    return fib_val(val - 1) + fib_val(val - 2);
}

void FibVec::resize(int resize_val){
    fib_size = resize_val;
    size = fib_val(fib_size);

    int* tempVec = new int[size];
    for (int i = 0; i < num_values; i++){
        tempVec[i] = mVec[i];
    }

    delete[] mVec;
    mVec = tempVec;
}

size_t FibVec::capacity() const{
    return size;
}

size_t FibVec::count() const{
    return num_values;
}

void FibVec::insert(int val, size_t index){
    if (index >= fib_val(fib_size + 2)){
        throw out_of_range("Index out of range");
        exit(1);
    }

    if (num_values == size){
        resize(fib_size + 1);
    }

    for (size_t i = num_values; i > index; i--){
        mVec[i] = mVec[i - 1];
    }
    mVec[index] = val;
    num_values += 1;
}

int FibVec::lookup(size_t index) const{
    size_t num = num_values;
    if (index > num){
        throw out_of_range("Index out of range");
        exit(1);
    }

    return mVec[index];
}

int FibVec::pop(){
    if (num_values == 0){
        throw underflow_error("Empty array");
    }

    int val = mVec[num_values - 1];
    int num = fib_val(fib_size - 1);
    if (num_values < num && fib_size >= 2){
        resize(fib_size - 1);
    }

    int* tempVec = new int[size];
    for (int i = 0; i < num_values - 1; i++){
        tempVec[i] = mVec[i];
    }

    delete[] mVec;
    mVec = tempVec;

    num_values -= 1;
    return val;
}

void FibVec::push(int val){
    if (num_values == size){
        resize(fib_size + 1);
    }
    mVec[num_values] = val;
    num_values += 1;
}

int FibVec::remove(size_t index){
    return 42;
}