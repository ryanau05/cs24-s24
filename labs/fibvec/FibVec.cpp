#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

using namespace std;


// FibVec Function Implementations

FibVec::FibVec(){
    delete[] mVec;
    int *mVec = new int[2];
}

FibVec::~FibVec(){

}

size_t FibVec::fib_val(size_t val) const{
    if (val <= 2){
        return 1;
    }
    return fib_val(val - 1) + fib_val(val - 2);
}

void FibVec::resize(int mVec[], int resize_val){
    fib_size = resize_val;
    size = fib_val(fib_size);

    int *tempVec = new int[size];
    for (int i = 0; i < num_values; i++){
        tempVec[i] = mVec[i];
    }

    delete[] mVec;
    int *mVec = new int[size];

    for (int i = 0; i < num_values; i++){
        mVec[i] = tempVec[i];
    }
    delete[] tempVec;
}

size_t FibVec::capacity() const{
    return fib_val(size);
}

size_t FibVec::count() const{
    return num_values;
}

void FibVec::insert(int val, size_t index){
    if (index >= fib_val(fib_size + 2)){
        throw out_of_range("invalid index");
        exit(1);
    }

    if (num_values == fib_size){
        resize(mVec, fib_size + 1);
    }

    int *tempVec = new int[size];
    for (int i = 0; i < num_values; i++){
        tempVec[i] = mVec[i];
    }

    delete[] mVec;
    int *mVec = new int[size];

    int i = 0;
    while (i < index){
        mVec[i]= tempVec[i];
        i++;
    }
    mVec[index] = val;
    i++;
    while (i < num_values){
        mVec[i] = tempVec[i - 1];
    }
    delete[] tempVec;
}

int FibVec::lookup(size_t index) const{
    if (index >= sizeof(*mVec) / 4){
        throw out_of_range("invalid index");
        exit(1);
    }

    return mVec[index];
}

int FibVec::pop(){
    return 42;
}

void FibVec::push(int val){
    if (num_values == fib_size){
        resize(mVec, fib_size + 1);
    }
    mVec[num_values] = val;
    num_values++;
}

int FibVec::remove(size_t index){
    return 42;
}