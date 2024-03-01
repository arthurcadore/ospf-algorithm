#include "dijkstra.h"

void dijkstra(unordered_map<string, list<Neighbor>>& map, list<string>& cities,
              string& destination,
              unordered_map<string, Table_Line>& distance_table) {
  // Step 1: Create the distance_table, so that for each city in the map:
  // distance_table[city] = (MAX_INT, next_city)
  // Note: D[destination] = (0, destination)
  for (auto city : cities) {
    distance_table[city] = Table_Line{"", INT_MAX};
  }
  distance_table[destination] = Table_Line{"", 0};

  // Step 2: Create Q, which is a list containing all nodes (including nodeA)
  list<string> Q = cities;

  // Step 3: While Q is not empty:
  while (!Q.empty()) {
    // Step 3.1: Extract from Q the node u, which is the node with the shortest distance to nodeA
    string u;
    int min_distance = INT_MAX;
    for (auto city : Q) {
      if (distance_table[city].total_distance < min_distance) {
        u = city;
        min_distance = distance_table[city].total_distance;
      }
    }

    // Step 3.2: For each neighbor node v of u:
    // Calculate the distance to node v: dist_v = dist_u + distance(u, v)
    // If dist_v is less than the distance contained in D[v], do this:
    // Update D[v] = (dist_v, u)
    for (auto neighbor : map[u]) {
      string v = neighbor.name;
      int dist_v = min_distance + neighbor.distance;
      if (dist_v < distance_table[v].total_distance) {
        distance_table[v] = Table_Line{u, dist_v};
      }
    }

    // Step 3.3: Remove u from Q
    Q.remove(u);
  }
}
