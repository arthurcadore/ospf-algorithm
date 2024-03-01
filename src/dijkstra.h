#ifndef DUHJSTRA_H
#define DUHJSTRA_H

#include <list>
#include <string>
#include <unordered_map>

#include "types.h"

using std::list;
using std::string;
using std::unordered_map;

void dijkstra(unordered_map<string, list<Neighbor>>& map, list<string>& cities,
              string& destination,
              unordered_map<string, Table_Line>& distance_table);

#endif 