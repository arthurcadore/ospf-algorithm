# Descobrindo Rotas em um Mapa

## Compilação

```bash
# 1º - Gerar Makefile para compilação do projeto
$ cmake CMakeLists.txt

# 2º - Compilar Projeto
$ make

# 3º - Executar Projeto
$ make run
```

## Objetivo

O programa desenvolvido tem como objetivo encontrar a rota mais curta entre dois pontos no mapa, indicando ao usuário o caminho a ser percorrido, quais cidades deverão ser visitadas e qual a distância total do trajeto. Será necessário que o usuário informe o nome das cidades e o mapa deve ser exibido na tela.

Será utilizado uma tabela CSV onde haverão três colunas, exemplo:

| Cidade A                  | Cidade B                  | Distância (km) |
| ------------------------- | ------------------------- | -------------- |
| Florianópolis             | São José                  | 19             |
| Florianópolis             | Biguaçu                   | 24             |
| São José                  | Biguaçu                   | 20             |
| São José                  | Palhoça                   | 6              |
| São José                  | São Pedro de Alcântara    | 22             |
| Biguaçu                   | Antônio Carlos            | 17             |
| São Pedro de Alcântara    | Antônio Carlos            | 10             |
| São Pedro de Alcântara    | Angelina                  | 28             |
| Palhoça                   | Santo Amaro da Imperatriz | 16             |
| Palhoça                   | Paulo Lopes               | 40             |
| Santo Amaro da Imperatriz | Rancho Queimado           | 31             |
| Angelina                  | Rancho Queimado           | 15             |
| Paulo Lopes               | Garopaba                  | 17             |
| Santo Amaro da Imperatriz | São Bonifácio             | 47             |
| São Bonifácio             | Garopaba                  | 118            |

A partir destes dados informados deveremos disponibilizar esta informação ao usuário para que ele possa escolher de qual a qual cidade ele deseja saber a rota mais curta.

---

##### Autores: Arthur Cadore Matuella Barcella, Gabriel Luiz Espindola Pedro, Matheus Pires Salazar
