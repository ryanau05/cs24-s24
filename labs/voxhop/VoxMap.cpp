#include "VoxMap.h"
#include "Errors.h"
#include <string>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <algorithm>

VoxMap::VoxMap(std::istream& stream) {
  stream >> width >> depth >> height;

  map.resize(width);
  for (int i = 0; i < width; i++){
    map[i].resize(depth);

    for (int j = 0; j < depth; j++){
      map[i][j].resize(height);
    }
  }

  for (int i = 0; i < height; i++){         // iterate through each tier
    std::string line;
    std::getline(stream, line);             // discards empty line

    for (int j = 0; j < depth; j++){        // iterate through each line
      std::getline(stream, line);           // read in each line of tier
      std::string hexVal = "";

      for (int k = 0; k < width / 4; k++){  // adds each hexdex to string as bin
        hexVal += hexToBin(line[k]);
      }

      for (int k = 0; k < width; k++){
        map[k][j][i] = (hexVal[k] == '1');
      }
    }
  }
}

VoxMap::~VoxMap() {

}

Route VoxMap::route(Point src, Point dst) {
  // std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
  // std::unordered_set<Point, PointHash> closedSet;

  // Node* startNode = new Node(src, 0, heuristic(src, dst));
  // openSet.push(startNode);

  // while (!openSet.empty()) {
  //   Node* current = openSet.top();
  //   openSet.pop();

  //   if (isDest(current->point, dst)) {
  //     Route route;
  //     Node* temp = current;
  //     while (temp->parent) {
  //       Point& p1 = temp->parent->point;
  //       Point& p2 = temp->point;

  //       if (p2.x > p1.x) route.push_back(Move::EAST);
  //       else if (p2.x < p1.x) route.push_back(Move::WEST);
  //       else if (p2.y > p1.y) route.push_back(Move::NORTH);
  //       else if (p2.y < p1.y) route.push_back(Move::SOUTH);

  //       temp = temp->parent;
  //     }
  //     std::reverse(route.begin(), route.end());

  //     // Clean up allocated nodes in openSet
  //     while (!openSet.empty()) {
  //       Node* node = openSet.top();
  //       openSet.pop();
  //       delete node;
  //     }

  //     // Clean up startNode
  //     delete startNode;

  //     return route;
  //   }

  //   closedSet.insert(current->point);

  //   std::vector<Point> neighbors = {
  //     {current->point.x + 1, current->point.y, current->point.z},
  //     {current->point.x - 1, current->point.y, current->point.z},
  //     {current->point.x, current->point.y + 1, current->point.z},
  //     {current->point.x, current->point.y - 1, current->point.z}
  //   };

  //   for (const Point& neighbor : neighbors) {
  //     if (!isValid(current->point, neighbor)) continue;
  //     if (closedSet.find(neighbor) != closedSet.end()) continue;

  //     int tentativeGCost = current->gCost + 1;  // Assuming uniform cost for each move
  //     Node* neighborNode = new Node(neighbor, tentativeGCost, heuristic(neighbor, dst), current);

  //     openSet.push(neighborNode);
  //   }
  // }

  // // Clean up allocated nodes in openSet if no path found
  // while (!openSet.empty()) {
  //   Node* node = openSet.top();
  //   openSet.pop();
  //   delete node;
  // }

  // // Clean up startNode
  // delete startNode;

  return {};
}

std::string VoxMap::hexToBin(char val) const{
  std::map<char, std::string> hexmap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
        {'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}
  };

  auto it = hexmap.lower_bound(val);
  std::string hexBin = "";
  if (it != hexmap.end()) {
      hexBin = it->second;
  }
  return hexBin;
}

int VoxMap::heuristic(const Point& a, const Point& b){
  float h = std::abs(a.x - b.x) + std::abs(a.y - b.y) + std::abs(a.z - b.z);
  return static_cast<int>(h);
}

bool VoxMap::isValid(Point a, Point b) const{
  if (b.x < 0 || b.x >= width || b.y < 0 || b.y >= depth){        // handles out of bounds
    return false;
  }

  if (b.z + 1 < height && map[b.x][b.y][b.z]){                                         // handles block in path
    if (map[b.x][b.y][b.z + 1]){                                   // if block on top of dest is stone
      return false;
    }
    else {                                                                  // if block on top of dest is air
      if (a.z + 1 < height && map[a.x][a.y][a.z + 1]){                                          // if block on top of curr is stone
        return false;
      }
      else {                                                                // if block on top of curr is air
        return true;
      }
    }
  }

  if (b.z - 1 >= 0 && map[b.x][b.y][b.z - 1]){                                     // if flat
    return true;
  }
  else {                                                                    // if block below dest is air
    if (isBottomless(b)){
      return false;
    }
    else {
      return true;
    }
  }

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
  int itr = a.z;
    while (itr >= 0) {
        if (map[a.x][a.y][itr]) {
            return false;
        }
        itr--;
    }

    return true;
}

std::unique_ptr<Node> VoxMap::createNode(Point pt, int g, int h, Node* p) {
    return std::make_unique<Node>(pt, g, h, p);
}