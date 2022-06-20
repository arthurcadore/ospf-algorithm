# OSFP Algorithm for find de shortest way between two points. 

## To compile this code: 

```bash
# 1º - Generate Makefile: 
$ cmake CMakeLists.txt

# 2º - Compile and run the project: 
$ make run
```

#PS: For compilation with make, cmake (version 3.17) should will be installed on your application. 

## Functional description: 

The program interfaces needs 3 itens to operate: 

```bash
# 1º - .csv archive that contains all routes. 

# 2º - Value of the destination point
$ String that need to be in the .csv archive. 

# 3º - Value of the source point
$ String that need to be in the .csv archive. 

```

| POINT A                  | POINT B                  | Distância (km) |
| ------------------------- | ------------------------- | -------------- |
| A             | A               | 19             |
| B            | A                   | 24             |
| C                | A                   | 20             |
| A                 | C                   | 6              |
| D                 | B    | 22             |
| B                   | D            | 17             |
| C   | D | 10             |
| D    | C                  | 28             |
| B                | C | 16             |
| C                   | B               | 40             |
| Santo Amaro da Imperatriz | Rancho Queimado           | 31             |
| Angelina                  | Rancho Queimado           | 15             |
| Paulo Lopes               | Garopaba                  | 17             |
| Santo Amaro da Imperatriz | São Bonifácio             | 47             |
| São Bonifácio             | Garopaba                  | 118            |

A partir destes dados informados deveremos disponibilizar esta informação ao usuário para que ele possa escolher de qual a qual cidade ele deseja saber a rota mais curta.

---

##### Autores: Arthur Cadore Matuella Barcella, Gabriel Luiz Espindola Pedro, Matheus Pires Salazar
