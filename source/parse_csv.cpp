#include "parse_csv.h"

void parse_csv(unordered_map<string, list<Neighbor>>& map,
               list<string>& cities) {
  // Abre arquivo CSV
  ifstream csv("cities.csv");

  if (!csv.is_open()) {
    // Caso haja erro ao abrir o arquivo, retorna exeção.
    throw "Erro ao abrir o arquivo csv";
  }

  string line;
  // Discarta primeira linha (cabeçalho).
  getline(csv, line);

  // Para cada linha joga informações para map e cities.
  while (getline(csv, line)) {
    if (!line.empty()) {
      stringstream ss(line);
      string city_a;
      string city_b;
      int distance;

      // Lê cidade A, cidade B e distância, e insere em suas respectivas
      // variáveis.
      getline(ss, city_a, ',');
      getline(ss, city_b, ',');
      ss >> distance;

      // Adiciona cidade à lista de cidades.
      cities.push_back(city_a);

      // Adiciona cidade vizinha à lista de vizinhos da cidade A.
      if (map.find(city_a) == map.end()) {
        // Caso não haja cidade A na hashtable de vizinhos, inicializa.
        list<Neighbor> new_list = {Neighbor{city_b, distance}};

        map[city_a] = new_list;
      } else {
        // Caso haja adiciona a cidade B à lista de vizinhos da cidade A.
        map[city_a].push_back({Neighbor{city_b, distance}});
      }
    }
  }

  // Remove duplicatas na lista de cidades.
  cities.unique();
}
