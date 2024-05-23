#include "Counter.h"
#include <iostream>

// Counter Member Functions

Counter::Counter(){
    list();
    Index();
}

Counter::~Counter(){

}

void Counter::inc(const std::string& key, int by){
    if (index.find_(key) == nullptr){
        list::node* add = new list::node(key, by);
        linkedlist.insert(add);
        index.insert_(key, add);
        return;
    }

    list::node* curr = index.find_(key);
    curr->data += by;
}

void Counter::dec(const std::string& key, int by){
    if (index.find_(key) == nullptr){
        list::node* add = new list::node(key);
        linkedlist.insert(add);
        index.insert_(key, add);
    }

    list::node* curr = index.find_(key);
    curr->data -= by;
}

void Counter::del(const std::string& key){
    index.remove_(key);
}

int  Counter::get(const std::string& key) const{
    if (index.find_(key) == nullptr){
        return 0;
    }
    list::node* val = index.find_(key);
    if (val == nullptr){
        return 0;
    }
    return val->data;
}

void Counter::set(const std::string& key, int count){
    if (index.find_(key) == nullptr){
        list::node* add = new list::node(key, count);
        linkedlist.insert(add);
        index.insert_(key, add);
        return;
    }

    list::node* curr = index.find_(key);
    curr->data = count;
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
        curr = curr->next;
    }
    return sum;
}

Counter::Iterator Counter::begin() const{
    Counter::Iterator itr(linkedlist.head);
    return itr;
}

Counter::Iterator Counter::end() const{
    Counter::Iterator itr(nullptr);
    return itr;
}