#ifndef PARSE_CSV_H
#define PARSE_CSV_H

#include <fstream>
#include <list>
#include <sstream>
#include <unordered_map>

#include "types.h"

using std::getline;
using std::ifstream;
using std::list;
using std::string;
using std::stringstream;
using std::unordered_map;

void parse_csv(unordered_map<string, list<Neighbor>>& map,
               list<string>& cities);

#endif 