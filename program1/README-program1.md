PLEASE VIEW IN "RAW" FORMAT TO SEE PROPER FORMAT OF THE TXT FILES


Introduction
In this assignment, you will improve your C programming skills by implementing graph algorithms.
First, you represent a graph data structure in C by representing undirected and weighted directed
graphs. Second, you implement two simple graph traversal algorithms – breadth-first search (BFS)
and depth-first search (DFS). Third, you will use the DFS traversal to single-source shortest path
computation in directed acyclic graphs (DAGs). Lastly, you will implement Dijkstra’s shortest
path algorithm that is not limited to DAGs and can be used to find single-source shortest paths
in all directed graphs that have no edges with negative weights. Your program must follow the
input-output guidelines listed in each section exactly, with no additional or missing output.



program1: Undirected Graph Representation


Graphs are a widely used data structure in CS with applications in computer networks, circuits,
and neural networks. A graph consists of vertices that are connected by edges. If edges have a
direction associated with them, such graphs are called directed graphs. If the edges do not have
any direction associated with them, such graphs are called undirected graphs.


There exist several standard ways to represent a graph on a computer. In this programming assignment, we are going to use the adjacency list representation. 
In the adjacency list representation, each vertex stores a linked list of its adjacent vertices. 
In this part, you write a program that will read an undirected graph from a file. Store it in an
adjacency list representation and then answer simple graph queries.




Input-Output format: Your program will take two file names as its command-line input. The
first file includes the undirected graph. Your program reads the contents of this file and constructs
the graph data structure. The first line in this file provides the number of vertices in the graph.
Next, each line contains the name of each vertex in the graph. Afterwards, each following line
includes information about an edge in the graph. Each edge is described by the name of its pair of
vertices, separated by a space.
The second file includes queries on the constructed graph. Each line contains a separate query that
starts with the query type and a vertex, separated by a space. There are two query types. Degree
queries start with the letter ’d’, followed by a space and the vertex’s name, which is a string. Upon
processing a degree query, your program must print out the queried vertex’s degree, followed by a
newline character. Adjacency queries start with the letter ’a’, followed by a space and the vertex’s
name. Upon processing an adjacency query, your program must print out the vertices adjacent to
the queried vertex, each vertex separated by a space and finally, a newline character. When you
print the results of the adjacency query, the results have to be sorted lexicographically.
Example Execution:
Let’s assume we have the following graph and query file:
graph.txt
5
A
B
C
D
E
A B
A C
A D
B D
C D
C E
D E

query.txt:
d E
a C
d A
a A

Then the result will be:
$./first graph.txt query.txt
2
A D E
3
B C D

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.
