#ifndef ROUTER_REMOVER
#define ROUTER_REMOVER

#include <fstream>
#include <list>
#include <sstream>
#include <unordered_map>

#include "types.h"

using std::list;
using std::string;
using std::unordered_map;

void route_remover(unordered_map<string, list<Neighbor>> &map,
                   list<string> &cities_to_remove,
                   unordered_map<string, Table_Line> &distance_table);

#endif