program-2: Weighted Directed Graph Representation



In this part, you write a program that will read a weighted directed graph from a file. Store it in
an adjacency list representation and then answer simple graph queries.

Input-Output format: Your program will take two file names as its command-line input. The
first file includes the weighted directed graph. Your program reads the contents of this file and
constructs the graph data structure. The first line in this file provides the number of vertices
in the graph. Next, each line contains the name of each vertex in the graph. Afterwards, each
following line includes information about a weighted directed edge in the graph. Each weighted
edge is described by the name of its pair of vertices, followed by the edge weight, separated by a
space. For example, B A 10 defines a directed edge from vertex B to vertex A with an edge weight
of 10.
The second file includes queries on the constructed graph. Each line contains a separate query that
starts with the query type and a vertex, separated by a space. There are three query types. 
Outdegree queries start with the letter ’o’, followed by a space and the vertex’s name. Upon processing
an out-degree query, your program must print out the queried vertex’s out-degree, followed by a
newline character. In degree queries start with the letter ’i’, followed by a space and the vertex’s
name. Upon processing an in degree query, your program must print out the queried vertex’s in
degree2, followed by a newline character. Adjacency queries start with the letter ’a’, followed by
a space and the vertex’s name. Upon processing an adjacency query, your program must print
out the vertices adjacent to the queried vertex, each vertex separated by a space and finally, a
newline character. When you print the results of the adjacency query, the results have to be sorted
lexicographically.

Example Execution:
Let’s assume we have the following graph and query file:
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
query.txt:
o E
a C
i E
a A
a E

Then the result will be:
$./second graph.txt query.txt
2
E
1
C D
C D

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.
