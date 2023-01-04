
/* Q. Represent a graph of your college campus using adjacency list /adjacency 
matrix. Nodes should represent the various departments/institutes and links 
should represent the distance between them. Find minimum spanning tree.

b) Using Prim’s algorithm:

*/


#define infinity 9999 
#define MAX 20 
#include<iostream>
#include<stdlib.h>
using namespace std; 
class graph 
{ 
int G[MAX][MAX]; 
int n; 
public: 
graph() 
{ 
n = 0; 
} 
 void readgraph(); 
 void printgraph(); 
 int prims(graph &); 
}; 
void graph::readgraph() 
{ 
int i, j; 
cout<< "\nEnter No. of department: "; 
cin>>n; cout<< "\nEnter the adjacency matrix : "; 
for (i = 0; i< n; i++) 
for (j = 0; j < n; j++) 
cin>> G[i][j]; 
} 
void graph::printgraph() 
{ 
 int i, j; 
 for (i = 0; i< n; i++) 
 { cout<< "\n"; 
 for (j = 0; j < n; j++) 
cout<< " " << G[i][j]; 
 } 
 } 
int graph::prims(graph &spanning) 
{ 
int cost[MAX][MAX]; 
int u, v, min_distance, link[MAX], from[MAX]; 
int visited[MAX], no_of_edges, i, min_cost, j; 
 for (i = 0; i< n; i++) 
 for (j = 0; j < n; j++) 
{ 
 if (G[i][j] == 0) 
 cost[i][j] = infinity; 
 else 
 cost[i][j] = G[i][j]; 
 spanning.G[i][j] = 0; 
} 
link[0] = 0; 
visited[0] = 1; 
for (i = 1; i< n; i++) 
{ 
link[i] = cost[0][i]; 
from[i] = 0; 
visited[i] = 0; 
} 
min_cost = 0; 
no_of_edges = n - 1; 
while (no_of_edges> 0) 
{ 
min_distance = infinity; 
for (i = 1; i< n; i++) 
 if (visited[i] == 0 && link[i] <min_distance) 
 { 
 v = i; 
min_distance = link[i]; 
 } 
 u = from[v]; 
spanning.G[u][v] = link[v]; 
spanning.G[v][u] = link[v]; 
no_of_edges--; 
 visited[v] = 1; 
for (i = 1; i< n; i++) 
if (visited[i] == 0 && cost[i][v] < link[i]) 
{ 
link[i] = cost[i][v]; 
from[i] = v; 
 } 
min_cost = min_cost + cost[u][v]; 
 } 
spanning.n = n; 
return (min_cost); 
} 
int main() 
{ 
graph gl, spanning; 
gl.readgraph(); 
int total_cost = gl.prims(spanning); 
cout<< "\nspanning tree matrix : \n"; 
spanning.printgraph(); 
cout<< "\nTotal of cost spanning tree=" <<total_cost; 
return 0; 
}

