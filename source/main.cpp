#include "main.h"

int main(int argc, char const *argv[]) {
  cout << endl
       << endl
       << "---------------------Algoritmo de Dijkstra---------------------"
       << endl
       << endl;

  // Hashtable que armazena as cidades do mapa, as cidades vizinhas e a
  // distância entre elas.
  unordered_map<string, list<Neighbor>> map;
  // Lista com todas as cidades do mapa.
  list<string> cities;

  try {
    // Lê o arquivo CSV e armazena os dados em map e cities.
    parse_csv(map, cities);
  } catch (...) {
    // Em caso de erro na leitura do arquivo, o programa é encerrado.
    cout << "Erro ao abrir o arquivo csv" << endl;
    return 1;
  }

  // Variáveis de input de usuário.
  string destination;
  string starting_point;
  while (true) {
    // Pede ao usuário que insira uma cidade do mapa como destino.
    do {
      cout << "Digite o nome da cidade de destino: ";
      getline(cin, destination);
    } while (map.find(destination) == map.end());

    // Tabela de distâncias e caminhos utilizadas pelo algoritmo.
    unordered_map<string, Table_Line> distance_table;
    dijkstra(map, cities, destination, distance_table);

    // Pede ao usuário que insira uma cidade do mapa como origem.
    do {
      cout << "Digite o nome da cidade de origem: ";
      getline(cin, starting_point);
    } while (map.find(starting_point) == map.end());

    // Exibe ao usuário o menor caminho entre origem e destino e informa
    // distância.
    cout << endl;
    cout << "Menor caminho para chegar em " << destination << " partindo de "
         << starting_point << ": " << endl;

    string current_city = starting_point;
    // Cria string de caminho que será exibida ao usuário
    string path = "";
    // Itera sobre a tabela de distâncias e caminhos para criar a string
    // caminho.
    while (current_city != "") {
      path += current_city + " -> ";

      current_city = distance_table[current_city].next_city;
    }
    // Remove " -> " do final da string.
    path.erase(path.length() - 3);

    cout << path << endl;
    cout << "Distância total: " << distance_table[starting_point].total_distance
         << "km" << endl;

    cout << endl
         << endl
         << "---------------------Algoritmo de Dijkstra---------------------"
         << endl
         << endl;
  }

  return 0;
}