// Counter.cpp
#include "Counter.h"

Counter::Counter() {}

Counter::~Counter() {}

void Counter::inc(const std::string& key, int by) {
    list::node* nodePtr = linkedlist.find(key);
    if (nodePtr == nullptr) {
        nodePtr = new list::node(key);
        linkedlist.insert(nodePtr);
        index.insert_(key, nodePtr);
    }
    nodePtr->data += by;
}

void Counter::dec(const std::string& key, int by) {
    list::node* nodePtr = linkedlist.find(key);
    if (nodePtr != nullptr) {
        nodePtr->data -= by;
    }
}

void Counter::del(const std::string& key) {
    list::node* nodePtr = linkedlist.find(key);
    if (nodePtr != nullptr) {
        linkedlist.remove(key);
        index.remove_(key);
    }
}

int  Counter::get(const std::string& key) const {
    list::node* nodePtr = linkedlist.find(key);
    return nodePtr != nullptr ? nodePtr->data : 0;
}

void Counter::set(const std::string& key, int count) {
    list::node* nodePtr = linkedlist.find(key);
    if (nodePtr == nullptr) {
        nodePtr = new list::node(key, count);
        linkedlist.insert(nodePtr);
        index.insert_(key, nodePtr);
    } else {
        nodePtr->data = count;
    }
}

size_t Counter::count() const {
    return linkedlist.count;
}

int Counter::total() const {
    int sum = 0;
    list::node* curr = linkedlist.head;
    while (curr != nullptr) {
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

Counter::Iterator Counter::begin() const {
    return Iterator(linkedlist.head);
}

Counter::Iterator Counter::end() const {
    return Iterator(nullptr);
}