#include "router_remover.h"

void route_remover(unordered_map<string, list<Neighbor>> &map,
                   list<string> &cities_to_remove,
                   unordered_map<string, Table_Line> &distance_table) {
  // Define the lists that will be used to store the neighbors of the target city
  // during the check, for updating the map.

  // NOTE: Two lists are used because there needs to be a return list, as the table
  // is symmetric, the routes are mirrored in the cities.

  list<Neighbor> neighbors_return;
  list<Neighbor> inverted_neighbors_return;

  // Define a list to store the mirrored cities to check.
  list<string> inverted_cities_to_remove;

  // Define a list to store the cities to check within the neighbors of the
  // mirrored city.
  list<string> previous_city;

  // Start a loop iterating over the route cities for verification;
  for (auto city_to_remove : cities_to_remove) {
    // Collect the list of neighbors of the given city.
    list<Neighbor> list_of_neighbors = map[city_to_remove];

    // Check if the list of neighbors has more than 2 values.
    // NOTE: It is necessary for the city to have at least two connections, hence
    // the verification.
    if (list_of_neighbors.size() > 2) {
      // Collect the next city pointed by the table to the destination.
      string &next_city = distance_table[city_to_remove].next_city;

      // Add the mirrored cities to the list for the reverse process later on
      inverted_cities_to_remove.push_back(next_city);
      previous_city.push_back(city_to_remove);

      // Iterate over the list of neighbors, copy all values to a separate list.
      for (auto i : list_of_neighbors) {
        if (next_city != i.name) {
          neighbors_return.push_back(i);
        }
      }
      // Update the value in the map corresponding to the key with the new list of
      // neighbors.
      map[city_to_remove] = neighbors_return;

      // Clear the list of neighbors for the next loop.
      neighbors_return.clear();
    }
  }

  // Iterate over the list of cities collected in the previous loop to remove the
  // symmetric routes.
  while (!previous_city.empty()) {
    // Create two auxiliary variables to facilitate the organization of the code.
    string &key = inverted_cities_to_remove.front();
    string &value_to_remove = previous_city.front();

    // Find in the map the list of neighbors corresponding to the mirrored city.
    list<Neighbor> &neighbors_to_remove = map[key];

    // Check the size of the list, to ensure it has more than two connections
    // (neighbors)
    if (neighbors_to_remove.size() > 2) {
      // Iterate over the list of neighbors copying the values that do not
      // correspond to the mirrored route.
      for (auto i : neighbors_to_remove) {
        if (i.name != value_to_remove) {
          // Add the route to a separate list for map update
          inverted_neighbors_return.push_back(i);
        }
      }

      // Update the values in the map of the mirrored city removing the
      // symmetric route.
      map[key] = inverted_neighbors_return;

      // Clear the list of neighbors for the next loop.
      inverted_neighbors_return.clear();
    }

    // Remove the target/mirrored city from the list for the next loop.
    inverted_cities_to_remove.pop_front();
    previous_city.pop_front();
  }

  return;
}
