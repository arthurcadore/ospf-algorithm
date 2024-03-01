# OSFP Protocol - SPF Algorithm (Dijkstra)

This repository contains a C++ implementation of the OSPF (Open Shortest Path First) routing protocol, using the SPF (Shortest Path First) algorithm, also known as Dijkstra's algorithm. OSPF is a dynamic routing protocol widely used in large-scale networks to calculate the shortest path for routing packets.

---
### Prerequisites, before you begin, ensure you have the following packages installed on your system:

- Git version 2.34.1
- cmake (version 3.17)


### Algorithm description: 

Before starts the algorithm application, make shure you have an database file (by default is `cities.csv`), to feed the algorithm and allow it to calculate de OSPF. 

The database (.csv) file needs the following structure to operate correctely: 

<table align="center">
  <tr>
    <th>Source</th>
    <th>Destination</th>
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
</table>

### Getting Started:

First, copy the line below and paste on your prompt to clone the repository:

```
git clone https://github.com/arthurcadore/ospf-algorithm
```

Navigate to the project directory:
```
cd ./ospf-algorithm
```

## Code compilation: 

In sequence, compile de C++ codes, and execute the application by the commands below: 

```
cmake CMakeLists.txt

make run
```

## Using the application: 

After the application is running, you will be prompted to enter the destination and source city names. The application will calculate the shortest path and the second shortest path between the two cities, and display the results, as shown below:

```
@arthurcadore ➜ /ospfAlgorithm (main) $ make run
[100%] Built target route_finder


---------------------Dijkstra's Algorithm---------------------

Enter the name of the destination city: Florianópolis
Enter the name of the starting city: Rio do Sul

Shortest path to reach Florianópolis from Rio do Sul: 
Rio do Sul -> Ituporanga -> Alfredo Wagner -> Rancho Queimado -> Santo Amaro da Imperatriz -> Palhoça -> São José -> Florianópolis 
Total distance: 201km

Second shortest path to reach Florianópolis from Rio do Sul: 
Rio do Sul -> Ituporanga -> Leoberto Leal -> Major Gercino -> Angelina -> São Pedro de Alcântara -> São José -> Florianópolis 
Total distance: 220km
 
```



