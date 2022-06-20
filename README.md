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

| POINT A                  | POINT B                  | Distance Cost |
| ------------------------- | ------------------------- | -------------- |
| A | B | 2 |
| A | C | 1 |
| B | A | 2 |
| B | C | 3 |
| B | D | 4 |
| C | A | 1 |
| C | B | 3 |
| C | D | 1 |
| D | C | 1 |
| D | B | 4 |



---
