#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
  // Member Variables
  Node* root = new Node;
  size_t nodeCount = 0;
  // Private Helper Functions
  void rebalance(Node* promote);
  void clearAll(Node* curr);                      // recursively deletes tree
  std::string print_all(const Node* node) const;         // recursively prints tree
  bool isLeaf(Node* node);                        // true if node is leaf
  void adjustWeight(Node* node, bool increase);   // increments weight


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
  void        print() const;                        // done
  void        remove(size_t index);
};

#endif
