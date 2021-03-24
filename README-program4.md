Fourth: Depth-first Search (DFS) 

In this part, you will implement the depth-first search (DFS) graph traversal algorithm. For a given
input graph G=(V,E), DFS visits an unvisited vertex v. At each step in DFS, we choose an unvisited
vertex adjacent to the most recently discovered vertex. We continue this process until all vertices
reachable from v are discovered. If any undiscovered vertices remain, we choose one of them and
repeat the above process until all vertices are discovered.

In this part, you write a program that will read a directed graph from a file using your implementation from part 2 
and perform a DFS traversal, printing out the graph vertices in order of DFS
vertex visit. When you are choosing a vertex to visit next among the adjacent children, you have
to pick the vertex that is not visited yet and occurs first in the lexicographic order.

Input-Output format: Your program will take a file name as its command-line input. This file
includes a directed graph, and it follows the same format from part 2. Your program reads the
contents of this file and constructs the graph data structure. The first line in this file provides
the number of vertices in the graph. Each following line includes information about a weighted
directed edge in the graph. Each weighted edge is described by the name of its pair of vertices,
followed by the edge weight, separated by a space. Your program must read and construct this
graph, perform a DFS traversal, and print out the graph vertices in order of DFS visitation. Each
vertex is separated by a space and, finally, a newline character.

Example Execution:
graph.txt
5
A
B
C
D
E
B A 10
A C 8
A D 12
B D 5
C E 5
D C 9
E C 7
E D 3

Then the result will be:
$./fourth graph.txt
A C E D B

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.
