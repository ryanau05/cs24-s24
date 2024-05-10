#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
  Node* right = nullptr;
  Node* left = nullptr;
  Node* parent = nullptr;
  int weight = 1;
  std::string data;

};

#endif