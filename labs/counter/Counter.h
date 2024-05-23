// Counter.h
#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include "List.h"
#include "Index.h"

class Counter {
public:
    class Iterator {
    public:
        Iterator(list::node* curr_ = nullptr);
        const std::string& key() const;
        int value() const;

        void operator ++ ();
        bool operator == (const Iterator& other) const;
        bool operator != (const Iterator& other) const;

    private:
        list::node* curr;
    };

    Counter();
    ~Counter();

    size_t count() const;
    int total() const;

    void inc(const std::string& key, int by = 1);
    void dec(const std::string& key, int by = 1);
    void del(const std::string& key);
    int  get(const std::string& key) const;
    void set(const std::string& key, int count);

    Iterator begin() const;
    Iterator end() const;

private:
    list linkedlist;
    Index index;
};

#endif
