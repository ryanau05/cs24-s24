#include "VoxMap.h"
#include "Errors.h"
#include <string>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <unordered_map>

VoxMap::VoxMap(std::istream& stream) {
   stream >> width >> depth >> height;

    // Resize the map to fit the dimensions
    map.resize(width, std::vector<std::vector<bool>>(depth, std::vector<bool>(height, false)));

    // Skip the newline character after the dimensions line
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int h = 0; h < height; ++h) {
        // Read and discard the empty line before each tier
        std::string emptyLine;
        std::getline(stream, emptyLine);

        for (int d = 0; d < depth; ++d) {
            std::string line;
            std::getline(stream, line);
            std::string binaryString = "";

            for (char c : line) {
                binaryString += hexToBin(c);
            }

            // Populate the map with the binary values
            for (int w = 0; w < width; ++w) {
                map[w][d][h] = (binaryString[w] == '1');
            }
        }
    }
}

VoxMap::~VoxMap() {

}

Route VoxMap::route(Point src, Point dst) {
  if (!isValidStandPoint(src)) {
    throw InvalidPoint(src);
  } 
  else if (!isValidStandPoint(dst)) {
    throw InvalidPoint(dst);
  }

  std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
  std::unordered_set<Point, PointHash> closedSet;
  std::unordered_map<Point, int, PointHash> gCostMap; // To store the gCost for each node
  std::unordered_set<Node*> openSetNodes; // Track nodes in openSet
  std::vector<Node*> holding;

  Node* startNode = new Node(src, 0, heuristic(src, dst));
  openSet.push(startNode);
  openSetNodes.insert(startNode);
  holding.push_back(startNode);
  gCostMap[src] = 0;

  while (!openSet.empty()) {
    Node* current = openSet.top();
    openSet.pop();
    openSetNodes.erase(current); // Remove from openSetNodes when popped

    if (isDest(current->point, dst)) {
      Route route;
      Node* temp = current;
      while (temp->parent) {
        Point& p1 = temp->parent->point;
        Point& p2 = temp->point;

        if (p2.x > p1.x) route.push_back(Move::EAST);
        else if (p2.x < p1.x) route.push_back(Move::WEST);
        else if (p2.y < p1.y) route.push_back(Move::NORTH);
        else if (p2.y > p1.y) route.push_back(Move::SOUTH);

        temp = temp->parent;
      }
      std::reverse(route.begin(), route.end());

      // Cleanup nodes in holding vector
      for (int i = holding.size() - 1; i >= 0; i--) {
        delete holding[i];
      }

      return route;
    }

    closedSet.insert(current->point);

    std::vector<Point> neighbors = {
      {current->point.x + 1, current->point.y, current->point.z},
      {current->point.x - 1, current->point.y, current->point.z},
      {current->point.x, current->point.y + 1, current->point.z},
      {current->point.x, current->point.y - 1, current->point.z}
    };

    for (Point& neighbor : neighbors) {
      if (outOfBounds(neighbor)) {
          continue;
      }
      if (current->point.z >= height - 1 && map[neighbor.x][neighbor.y][neighbor.z]) {
          continue;
      }
      if (canJump(current->point, neighbor)) {
          neighbor = jump(neighbor);
          if (outOfBounds(neighbor) || map[neighbor.x][neighbor.y][neighbor.z]) {
              continue;
          }
      }
      if (canFall(current->point, neighbor)) {
          neighbor = fall(neighbor);
          if (outOfBounds(neighbor) || map[neighbor.x][neighbor.y][neighbor.z]) {
              continue;
          }
      }
      if (!isValid(current->point, neighbor)) {
          continue;
      }

      int newGCost = current->gCost + 1;  // Assuming uniform cost for each move

      // Check if this neighbor has been visited and update if a shorter path is found
      auto itClosed = closedSet.find(neighbor);
      if (itClosed != closedSet.end() && newGCost >= gCostMap[neighbor]) {
          continue; // Skip if already visited with a shorter or equal path
      }

      Node* neighborNode = new Node(neighbor, newGCost, heuristic(neighbor, dst), current);

      // Check if neighborNode is already in openSetNodes
      if (openSetNodes.find(neighborNode) != openSetNodes.end()) {
        // Check if we found a shorter path to this node
        if (newGCost < gCostMap[neighbor]) {
          // Update gCostMap and remove old node from openSet
          gCostMap[neighbor] = newGCost;
          auto itOpen = std::find_if(openSetNodes.begin(), openSetNodes.end(),
                                     [&](Node* n) { return n->point == neighborNode->point; });
          if (itOpen != openSetNodes.end()) {
            openSetNodes.erase(itOpen);
            openSet.push(neighborNode);
            openSetNodes.insert(neighborNode);
          }
        }
        continue; // Skip if already in openSet with a shorter or equal path
      }

      // Otherwise, add to openSet and openSetNodes
      openSet.push(neighborNode);
      openSetNodes.insert(neighborNode);
      holding.push_back(neighborNode);

      // Update gCost in gCostMap
      gCostMap[neighbor] = newGCost;
    }
  }

  // Cleanup nodes in holding vector
  for (int i = holding.size() - 1; i >= 0; i--) {
    delete holding[i];
  }

  // If no route found, throw exception or return empty route
  throw NoRoute(src, dst);
  return {}; // Return an empty route if no path found
}


std::string VoxMap::hexToBin(char val) const{
  std::map<char, std::string> hexmap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
        {'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}
  };

  auto it = hexmap.find(val);
  if (it != hexmap.end()) {
    return it->second;
  } else {
    return "";
  }
}

int VoxMap::heuristic(const Point& a, const Point& b){
  float h = std::abs(a.x - b.x) + std::abs(a.y - b.y) + std::abs(a.z - b.z);
  return static_cast<int>(h);
}

bool VoxMap::canJump(Point& a, Point& b){
  if (a.z < height - 1 && !map[a.x][a.y][a.z + 1] && map[b.x][b.y][b.z] && !map[b.x][b.y][b.z + 1]){
    return true;
  }
  return false;
}

Point VoxMap::jump(Point& a){
  if (a.z < height - 1) { 
    return {a.x, a.y, a.z + 1};
  }
  return a;
}

bool VoxMap::canFall(Point& a, Point& b){
  if (!map[b.x][b.y][b.z] && b.z - 1 > 0){
    if (!map[b.x][b.y][b.z - 1]){
      return true;
    }
  }
  return false;
}

Point VoxMap::fall(Point& a){
  int itr = a.z;
  while (itr > 0 && !map[a.x][a.y][itr - 1]) {
    itr--;
  }
  return {a.x, a.y, itr};
}

bool VoxMap::isflat(Point& a){
  if (a.z >= 1 && !map[a.x][a.y][a.z] && map[a.x][a.y][a.z - 1]){
    return true;
  }
  return false;
}

bool VoxMap::isValid(Point a, Point b){
  if (outOfBounds(b)){
    return false;
  }
  if (isflat(b)){
    return true;
  }

  return false;
}

bool VoxMap::isDest(Point a, Point b) const{
  if (a.x == b.x && a.y == b.y && a.z == b.z){
    return true;
  }
  else {
    return false;
  }
}

bool VoxMap::isBottomless(Point a) const{
  if (map[a.x][a.y][a.z - 1]){
    return true;
  }

  int itr = 0;
  while (itr != a.z && itr <= height){
    if (map[a.x][a.y][itr]){
      return false;
    }
    else {
      itr++;
    }
  }
  return false;
}

std::unique_ptr<Node> VoxMap::createNode(Point pt, int g, int h, Node* p) {
    return std::make_unique<Node>(pt, g, h, p);
}

bool VoxMap::outOfBounds(Point a) const{
  if (a.x < 0 || a.x >= width || a.y < 0 || a.y >= depth || a.z <= 0 || a.z >= height){
    return true;
  }
  return false;
}

bool VoxMap::isValidStandPoint(const Point& pt) const {
    // Check if the point is out of bounds
    if (outOfBounds(pt)) {
        return false;
    }

    // Check if the voxel is empty
    if (map[pt.x][pt.y][pt.z]) {
        return false;
    }

    // Check if the voxel below is full
    if (pt.z == 0 || !map[pt.x][pt.y][pt.z - 1]) {
        return false;
    }

    return true;
}