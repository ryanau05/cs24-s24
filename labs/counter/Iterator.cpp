#include "Counter.h"

// Counter::Iterator Member Functions

Counter::Iterator::Iterator(list::node* curr_){
    curr = curr_;
}

const std::string& Counter::Iterator::key() const{
    static const std::string empty_string = "";
    return curr ? curr->key : empty_string;
}

int Counter::Iterator::value() const{
    return curr ? curr->data : 0;
}

void Counter::Iterator::operator ++ (){
    if (curr->next != nullptr){
        curr = curr->next;
    }
}

bool Counter::Iterator::operator == (const Iterator& other) const{
    if (curr->key == other.key() && curr->data == other.value()){
        return true;
    }

    return false;
}

bool Counter::Iterator::operator != (const Iterator& other) const{
    if (curr->key == other.key() && curr->data == other.value()){
        return false;
    }

    return true;
}