PLEASE VIEW IN "RAW" FORMAT TO SEE PROPER FORMAT OF THE TXT FILES

program6: Dijkstra’s Shortest Path Algorithm

In this part, we implement Dijkstra’s Algorithm. This algorithm solves the single-source shortest
path problem for graphs with nonnegative edge weights. The key idea behind Dijkstra’s algorithm
is to maintain a set of vertices whose final shortest path from the source vertex has been determined.
This set starts empty, and at each iteration of the algorithm, we add the next vertex by extracting it
from a min-priority queue of vertices. For more information on Dijkstra’s shortest path algorithm,
see https://bit.ly/3hToIy5.

Input-Output format: Your program will take two file names as its command-line input. This
first file includes a weighted directed graph, and it follows the same format from parts 2 and 4.
Your program reads the contents of this file and constructs the graph data structure. The first line
in this file provides the number of vertices in the graph. Each following line includes information
about a weighted directed edge in the graph. Each weighted edge is described by the name of its
pair of vertices, followed by the edge weight, separated by a space. Your program must read and
construct this graph.

The second file includes single source shortest path queries on the constructed each. Each line
contains a different single-source shortest path query by specifying a source vertex. Your program
must read the source vertex, perform Dijkstra’s single-source shortest path algorithm using the
provided source vertex, and print out each of vertex in the graph in lexicographical ordering,
followed by the length of the shortest path to that vertex, and a newline character. Note that an
additional newline character follows the last vertex in DAG.

Example Execution:
Let’s assume we have the following graph input file:
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
A
E

Then the result will be:

$./sixth graph.txt query.txt
A 0
B INF
C 8
D 12
E 13

A INF
B INF
C 7
D 3
E 0

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above. Further, all input graphs edges are nonnegative for this part.
