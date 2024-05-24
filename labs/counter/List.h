#ifndef LIST_H
#define LIST_H

// TODO...

#include <string>

class list{
    public:
        class node{
            public:
                std::string key;
                int data;
                node* next;
                node* prev;
                node* hashNext;

                node(const std::string& key_, int data_ = 0);
        };

        node* head;
        node* tail;
        int count;
        int total;
        list();
        ~list();
        void insert(node* add);
        node* find(const std::string& key_) const;
        void remove(std::string key_);
};

#endif