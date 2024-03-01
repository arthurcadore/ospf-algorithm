#include "parse_csv.h"

void parse_csv(unordered_map<string, list<Neighbor>>& map,
               list<string>& cities) {
  // Open CSV file
  ifstream csv("cities.csv");

  if (!csv.is_open()) {
    // If there is an error opening the file, throw an exception.
    throw "Error opening the csv file";
  }

  string line;
  // Discard first line (header).
  getline(csv, line);

  // For each line, extract information and store it in map and cities.
  while (getline(csv, line)) {
    if (!line.empty()) {
      stringstream ss(line);
      string city_a;
      string city_b;
      int distance;

      // Read city A, city B, and distance, and insert into their respective variables.
      getline(ss, city_a, ',');
      getline(ss, city_b, ',');
      ss >> distance;

      // Add city to the list of cities.
      cities.push_back(city_a);

      // Add neighboring city to the list of neighbors of city A.
      if (map.find(city_a) == map.end()) {
        // If city A is not in the neighbors hashtable, initialize it.
        list<Neighbor> new_list = {Neighbor{city_b, distance}};

        map[city_a] = new_list;
      } else {
        // If it is, add city B to the list of neighbors of city A.
        map[city_a].push_back({Neighbor{city_b, distance}});
      }
    }
  }

  // Remove duplicates from the list of cities.
  cities.unique();
}
