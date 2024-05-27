#include "Heap.h"
#include "WordList.h"

Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[mCapacity];
}

Heap::Heap(const Heap& other){
    mCapacity = other.capacity();
    mCount = other.count();
    mData = new Entry[mCapacity];
    std::copy(other.mData, other.mData + mCount, mData);
}

Heap::~Heap(){
    delete[] mData;
}

size_t Heap::capacity() const{
    return mCapacity;
}

size_t Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if (index >= mCount){
        throw std::out_of_range("Invalid Index.");
    }
    return mData[index];
}

Heap::Entry Heap::pop(){
    if (mCount == 0){
        throw std::underflow_error("Heap is empty.");
    }

    Entry min = mData[0];
    mCount--;
    mData[0] = mData[mCount];

    size_t index = 0;
    while (true) {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;
        size_t smallest = index;

        if (leftChild < mCount && mData[leftChild].score < mData[smallest].score) {
            smallest = leftChild;
        }
        if (rightChild < mCount && mData[rightChild].score < mData[smallest].score) {
            smallest = rightChild;
        }
        if (smallest == index) {
            break;
        }
        std::swap(mData[index], mData[smallest]);
        index = smallest;
    }

    return min;
}

void Heap::push(const std::string& value, float score){
    if (mCount >= mCapacity){
        throw std::overflow_error("Heap is full.");
    }
    
    Entry add = {value, score};
    mData[mCount] = add;
    mCount++;

    size_t index = mCount - 1;
    while (index > 0) {
        size_t parentIndex = (index - 1) / 2;
        if (mData[index].score >= mData[parentIndex].score) {
            break;
        }
        std::swap(mData[index], mData[parentIndex]);
        index = parentIndex;
    }
}

Heap::Entry Heap::pushpop(const std::string& value, float score){
    if (mCount == 0) {
        throw std::underflow_error("Heap is empty");
    }

    Entry newItem = {value, score};

    Entry minEntry = mData[0];

    mData[0] = newItem;

    size_t index = 0;
    while (true) {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;
        size_t smallest = index;

        if (leftChild < mCount && mData[leftChild].score < mData[smallest].score) {
            smallest = leftChild;
        }
        if (rightChild < mCount && mData[rightChild].score < mData[smallest].score) {
            smallest = rightChild;
        }
        if (smallest == index) {
            break;
        }
        std::swap(mData[index], mData[smallest]);
        index = smallest;
    }

    return minEntry;
}

const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw std::underflow_error("Heap is empty.");
    }

    return mData[0];
}