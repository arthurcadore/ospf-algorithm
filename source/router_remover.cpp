#include "router_remover.h"

void route_remover(unordered_map<string, list<Neighbor>> &map,
                   list<string> &cities_to_remove,
                   unordered_map<string, Table_Line> &distance_table) {
  // Definindo as listas que serão utilizadas para armazenar os vizinhos da
  // cidade alvo durante a checagem, para atualização do mapa.

  // OBS: São utilizadas duas listas pois, é necessário que haja uma lista de
  // retorno, como a tabela é simetrica, as rotas são espelhadas nas cidades.

  list<Neighbor> neighbours_return;
  list<Neighbor> inverted_neighbours_return;

  // define uma lista para armazenar as cidades espelhadas a verificar.
  list<string> inverted_cities_to_remove;

  // define uma lista para armazenar as cidades a verificar dentro dos vizinhos
  // da cidade espelhada.
  list<string> previous_city;

  // inicia um loop interando as listas de cidades da rota para verificação;
  for (auto city_to_remove : cities_to_remove) {
    // coleta a lista de vizinhos da determinada cidade.
    list<Neighbor> list_of_neighbours = map[city_to_remove];

    // valida se a lista de vizinhos possui mais de 2 valores.
    // OBS: É necessário que a cidade tenha pelo menos duas conexões, por isso,
    // a verificação.
    if (list_of_neighbours.size() > 2) {
      // coleta a proxima cidade apontada pela tabela até o destino.
      string &next_city = distance_table[city_to_remove].next_city;

      // adiciona as cidades espelhadas a lista para o processo contrário
      // posteriormente
      inverted_cities_to_remove.push_back(next_city);
      previous_city.push_back(city_to_remove);

      // intera a lista de vizinhos, copia todos os valores para uma lista
      // separada.
      for (auto i : list_of_neighbours) {
        if (next_city != i.name) {
          neighbours_return.push_back(i);
        }
      }
      // atualiza o valor do mapa correspondente a chave com a nova lista de
      // vizinhos.
      map[city_to_remove] = neighbours_return;

      // limpa a lista de vizinhos para novo loop.
      neighbours_return.clear();
    }
  }

  // intera lista de cidades coletadas no loop anterior para remoção das rotas
  // simétricas.
  while (!previous_city.empty()) {
    // Cria duas variaveis auxiliares para facilitar a organização do código.
    string &key = inverted_cities_to_remove.front();
    string &value_to_remove = previous_city.front();

    // procura no mapa a lista de vizihos correspondente a cidade espelhada.
    list<Neighbor> &neighbours_to_remove = map[key];

    // verifica o tamanho da lista, para garantir que possui mais de duas
    // conexões (vizinhos)
    if (neighbours_to_remove.size() > 2) {
      // intera a lsita de vizinhos procurando copiando os valores que não
      // correspondem a rota espelhada.
      for (auto i : neighbours_to_remove) {
        if (i.name != value_to_remove) {
          // adiciona a rota a uma lista separada para atualização do mapa
          inverted_neighbours_return.push_back(i);
        }
      }

      // atualiza os valores do mapa da cidade espelhada retirando a rota
      // simétrica.
      map[key] = inverted_neighbours_return;

      // limpa a lista de vizinhos para o proximo loop.
      inverted_neighbours_return.clear();
    }

    // retira a cidade alvo/espelhada da lista para o proximo loop.
    inverted_cities_to_remove.pop_front();
    previous_city.pop_front();
  }

  return;
}