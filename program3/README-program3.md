PLEASE VIEW IN "RAW" FORMAT TO SEE PROPER FORMAT OF THE TXT FILES

Third: Breadth-first Search (BFS) 
In this part, you will implement the bread-first search (BFS) graph traversal algorithm. For a given
input graph G=(V,E) and a source vertex s, BFS starts exploring the edges of G until it discovers all
vertices reachable from the source vertex. During a BFS search, we start by visiting the adjacent
vertices to the source vertex, processing them, and subsequently exploring vertices in order of edge
distance (i.e., the smallest number of edges) from it. Figure 3 shows an example graph and its
BFS traversal starting from source vertex B. Note that the vertices are processed in order of their
distance from the source3
.
You will write a program that will read an undirected graph from a file using your implementation
from part 1 and perform BFS starting from different source vertices.

Input-Output format: Your program will take two file names as its command-line input. The
first file includes the undirected graph. This file is similar to the graph file from part 1. Your
program reads the contents of this file and constructs the graph data structure. The first line in
this file provides the number of vertices in the graph. Next, each line contains the name of each
vertex in the graph. Afterwards, each following line includes information about an edge in the
graph. Each edge is described by the name of its pair of vertices, separated by a space.
The second file includes BFS queries on the constructed graph. Each line contains a different BFS
query specifying a source vertex for the BFS. Your program must read the source vertex, perform
a BFS traversal on the constructed graph using the chosen source vertex, and print out the graph
vertices in order of BFS processing. Each vertex is separated by a space and finally, a newline
character.

Example Execution:
Let’s assume we have the following graph and query file:
graph.txt
6
A
B
C
D
E
F
A B
A C
A D
B D
C D
C E
D E
E F

query.txt:
B
E

Then the result will be:
$./third graph.txt query.txt
B A D C E F
E C D F A B

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.

You have traverse the immediate children of a node in a lexicographic order. For
example, if A node has three edges to nodes B, C, and D, then the BFS will process B first, then
C, and finally D. This requirement ensures that every graph has a single unique BFS traversal for
a given source vertex. You can easily satisfy this requirement by maintaining the adjacency list in
a lexicographically sorted order.
