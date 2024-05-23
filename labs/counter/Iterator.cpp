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
    return (curr == other.curr);
}

bool Counter::Iterator::operator != (const Iterator& other) const{
    return (curr != other.curr);
}