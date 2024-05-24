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
        list::node* add = new list::node(key);
        linkedlist.insert(add);
        index.insert_(key, add);
    }

    list::node* curr = index.find_(key);
    curr->data += by;
    linkedlist.total+= by;
}

void Counter::dec(const std::string& key, int by){
    if (index.find_(key) == nullptr){
        list::node* add = new list::node(key);
        linkedlist.insert(add);
        index.insert_(key, add);
    }

    list::node* curr = index.find_(key);
    curr->data -= by;
    linkedlist.total-= by;
}

void Counter::del(const std::string& key){
    list::node* temp = index.find_(key);
    linkedlist.total -= temp->data;
    index.remove_(key);
    linkedlist.count--;
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
        list::node* add = new list::node(key);
        linkedlist.insert(add);
        index.insert_(key, add);
    }

    list::node* curr = index.find_(key);
    linkedlist.total -= curr->data;
    linkedlist.total += count;
    curr->data = count;
}

size_t Counter::count() const{
    size_t count_ = linkedlist.count;
    return count_;
}

int Counter::total() const{
    return linkedlist.total;
}

Counter::Iterator Counter::begin() const{
    Counter::Iterator itr(linkedlist.head);
    return itr;
}

Counter::Iterator Counter::end() const{
    Counter::Iterator itr(nullptr);
    return itr;
}