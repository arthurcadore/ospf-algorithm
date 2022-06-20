# OSFP Algorithm c++ code. 

##Objective: Find de shortest way between two points. 

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
<table align="center">
| POINT A                  | POINT B                  | Distance Cost |
| ------------------------- | ------------------------- | -------------- |
  <tr>
    <th> POINT A</th>
    <th>POINT B</th>
    <th>Distance Cost</th>
  </tr>
  <tr>
    <th>A</th>
    <th>B</th>
    <th>2</th>
  </tr>
  <tr>
    <th>A</th>
    <th>C</th>
    <th>1</th>
  </tr>
  <tr>
    <th>B</th>
    <th>A</th>
    <th>2</th>
  </tr>
  <tr>
    <th>B</th>
    <th>C</th>
    <th>3</th>
  </tr>
  <tr>
    <th>B</th>
    <th>D</th>
    <th>4</th>
  </tr>
  <tr>
    <th>C</th>
    <th>A</th>
    <th>1</th>
  </tr>
  <tr>
    <th>C</th>
    <th>B</th>
    <th>3</th>
  </tr>
  <tr>
    <th>C</th>
    <th>D</th>
    <th>1</th>
  </tr>
  <tr>
    <th>D</th>
    <th>C</th>
    <th>1</th>
  </tr>
  <tr>
    <th>D</th>
    <th>B</th>
    <th>4</th>
  </tr>
</table>

<p align="center">Here is an represantation of the router table: </p>

<p align="center">
<img src="https://github.com/arthurcadore/ospf_algorithm_cpp/blob/main/map_diagram.png">
</p>


