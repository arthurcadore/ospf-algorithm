#include "dijkstra.h"

void dijkstra(unordered_map<string, list<Neighbor>>& map, list<string>& cities,
              string& destination,
              unordered_map<string, Table_Line>& distance_table) {
  // Passo 1: Cria a tabela distance_table, de forma que,
  // para cada cidade do mapa: distance_table[cidade] = (MAX_INT, next_city)
  // Observação: D[destination] = (0,destination)
  for (auto city : cities) {
    distance_table[city] = Table_Line{"", INT_MAX};
  }
  distance_table[destination] = Table_Line{"", 0};

  // Passo 2: Cria Q, que é uma lista contendo todos os nodos (incluindo nodoA)
  list<string> Q = cities;

  // Passo 3: Enquanto Q não estivar vazio:
  while (!Q.empty()) {
    // Passo 3.1: Extraia de Q o nodo u, que é o nodo com menor distância até
    // nodoA
    string u;
    int min_distance = INT_MAX;
    for (auto city : Q) {
      if (distance_table[city].total_distance < min_distance) {
        u = city;
        min_distance = distance_table[city].total_distance;
      }
    }

    // Passo 3.2: Para cada nodo v vizinho de u:
    //   Calcule a distância do nodo v: dist_v = dist_u + distancia(u,v)
    //   Se dist_v for menor do que a distância contida em D[v], faça isto:
    //     Atualize D[v] = (dist_v, u)
    for (auto neighbor : map[u]) {
      string v = neighbor.name;
      int dist_v = min_distance + neighbor.distance;
      if (dist_v < distance_table[v].total_distance) {
        distance_table[v] = Table_Line{u, dist_v};
      }
    }

    // Passo 3.3: Remova u de Q
    Q.remove(u);
  }
}
