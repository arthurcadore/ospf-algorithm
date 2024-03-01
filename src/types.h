#ifndef TYPES_H
#define TYPES_H

#include <list>
#include <string>

using std::list;
using std::string;

struct Neighbor {
  string name;
  int distance;
};

struct Table_Line {
  string next_city;
  int total_distance;
};

#define INT_MAX 2147483647

#endif  // TYPES_H