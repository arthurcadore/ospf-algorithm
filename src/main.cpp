#include "main.h"

int main(int argc, char const *argv[]) {
  cout << endl
       << endl
       << "---------------------Dijkstra's Algorithm---------------------"
       << endl
       << endl;

  // Hashtable that stores the cities in the map, the neighboring cities, and the
  // distance between them.
  unordered_map<string, list<Neighbor>> map;
  // List with all cities in the map.
  list<string> cities;
  list<string> cities_to_remove;

  try {
    // Read the CSV file and store the data in map and cities.
    parse_csv(map, cities);
  } catch (...) {
    // In case of an error reading the file, the program is terminated.
    cout << "Error opening the csv file" << endl;
    return 1;
  }

  // User input variables.
  string destination;
  string starting_point;
  while (true) {
    // Ask the user to input a city from the map as the destination.
    do {
      cout << "Enter the name of the destination city: ";
      getline(cin, destination);
    } while (map.find(destination) == map.end());

    // Ask the user to input a city from the map as the starting point.
    do {
      cout << "Enter the name of the starting city: ";
      getline(cin, starting_point);
    } while (map.find(starting_point) == map.end());

    // Distance and path table used by the algorithm.
    unordered_map<string, Table_Line> distance_table;
    dijkstra(map, cities, destination, distance_table);

    // Display to the user the shortest path between origin and destination and
    // inform distance.
    string current_city = starting_point;
    // Create path string that will be displayed to the user.
    string path = "";

    cout << endl;
    cout << "Shortest path to reach " << destination << " from " << starting_point << ": " << endl;

    // Iterate over the distance and path table to create the path string.
    while (current_city != "") {
      path += current_city + " -> ";

      current_city = distance_table[current_city].next_city;

      // Check if the city is not the starting point or the destination and then add
      // it to the list.
      if (current_city != starting_point && current_city != destination) {
        // Add intermediate cities to the list to remove routes.
        cities_to_remove.push_back(current_city);
      }
    }

    // As the initial code formatting includes an empty string at the end of the list,
    // pop_back is used to remove it.
    cities_to_remove.pop_back();

    // Remove the extra 3 characters from the printing loop.
    path.erase(path.length() - 3);

    // Print the total distance traveled by the route.
    cout << path << endl;
    cout << "Total distance: " << distance_table[starting_point].total_distance << "km" << endl;

    // Call the route removal function.
    route_remover(map, cities_to_remove, distance_table);

    // Clear the table containing the routes from the first call of the algorithm.
    distance_table.clear();

    // Call the algorithm again, this time with the routes already removed.
    dijkstra(map, cities, destination, distance_table);

    // Display to the user the second shortest path between origin and destination
    // and inform distance.
    cout << endl;
    cout << "Second shortest path to reach " << destination << " from " << starting_point << ": " << endl;

    current_city = starting_point;
    // Create path string that will be displayed to the user.
    path = "";
    // Iterate over the distance and path table to create the path string.
    while (current_city != "") {
      path += current_city + " -> ";

      current_city = distance_table[current_city].next_city;
    }

    // Remove " -> " from the end of the string.
    path.erase(path.length() - 3);

    cout << path << endl;
    cout << "Total distance: " << distance_table[starting_point].total_distance << "km" << endl;

    cout << endl
         << endl
         << "---------------------Dijkstra's Algorithm---------------------"
         << endl
         << endl;
  }

  return 0;
}
