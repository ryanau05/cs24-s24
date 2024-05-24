#ifndef INDEX_H
#define INDEX_H

#include <string>
#include "List.h"

class Index {
public:
    Index();
    ~Index();

    void insert_(const std::string& key_, list::node* nodePtr);
    list::node* find_(const std::string& key_) const;
    void remove_(const std::string& key_);

private:
    static const size_t capacity = 1000000;
    list* table;

    size_t hash(const std::string& key_) const;
};

#endif