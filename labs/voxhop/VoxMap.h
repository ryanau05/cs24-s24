#ifndef VOXMAP_H
#define VOXMAP_H

#include <istream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <memory>
#include <map>

#include "Point.h"
#include "Route.h"

struct Node {
    Point point;
    int gCost, hCost;
    Node* parent;

    Node(Point pt, int g, int h, Node* p = nullptr) : point(pt), gCost(g), hCost(h), parent(p) {}

    int fCost() const {
        return gCost + hCost;
    }
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->fCost() > b->fCost();
    }
};

struct PointHash {
    std::size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y) ^ std::hash<int>()(p.z);
    }
};

class VoxMap {
  // Member Variables
  std::vector<std::vector<std::vector<bool> > > map;
  int width, depth, height;

  // Helper Functions
  std::string hexToBin(char val) const;
  int heuristic(const Point& a, const Point& b) const;
  bool isBottomless(Point a) const;
  int heuristic(const Point& a, const Point& b);
  bool isDest(Point a, Point b) const;
  std::unique_ptr<Node> createNode(Point pt, int g, int h, Node* p = nullptr);
  void cleanupNodes(std::priority_queue<Node*, std::vector<Node*>, CompareNode>& nodes);


public:
  VoxMap(std::istream& stream);
  ~VoxMap();

  float heuristic(Point a, Point b) const;
  bool isValid(Point a, Point b) const;

  Route route(Point src, Point dst);
};

#endif
