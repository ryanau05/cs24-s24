#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
  // Member Variables
  Node* root;
  size_t nodeCount = 0;
  // Private Helper Functions
  void rebalance(Node* promote);
  void clearAll(Node* curr);
  void print_all(const Node* node) const;


public:
  Tree();
  ~Tree();

  // Public Member Functions
  void        clear();                              // done
  size_t      count() const;                        // done
  bool        contains(const std::string& s) const; // done
  size_t      find(const std::string& s) const;
  void        insert(const std::string& s);         // done
  std::string lookup(size_t index) const;
  void        print() const;
  void        remove(size_t index);
};

#endif
