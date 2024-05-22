#include "Counter.h"

// Counter Member Functions

Counter::Counter(){

}

Counter::~Counter(){
    linkedlist.~list();
}

void Counter::inc(const std::string& key, int by){
    if (linkedlist.find(key) == nullptr){
        linkedlist.insert(key);
    }
    list::node* increment = linkedlist.find(key);
    increment->data += by;
}

void Counter::dec(const std::string& key, int by){
    if (linkedlist.find(key) == nullptr){
        linkedlist.insert(key);
    }
    list::node* increment = linkedlist.find(key);
    increment->data -= by;
}

void Counter::del(const std::string& key){
    linkedlist.remove(key);
}

int  Counter::get(const std::string& key) const{
    if (linkedlist.find(key) == nullptr){
        return 0;
    }
    list::node* val = linkedlist.find(key);
    return val->data;
}

void Counter::set(const std::string& key, int count){
    if (linkedlist.find(key) == nullptr){
        linkedlist.insert(key);
    }
    list::node* increment = linkedlist.find(key);
    increment->data = count;
}

size_t Counter::count() const{
    size_t count_ = linkedlist.count;
    return count_;
}

int Counter::total() const{
    int sum = 0;
    list::node* curr = linkedlist.head;
    while (curr != nullptr){
        sum += curr->data;
    }
    return sum;
}