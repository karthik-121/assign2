PLEASE VIEW IN "RAW" FORMAT TO SEE PROPER FORMAT OF THE TXT FILES

program5: Single-source Shortest Path in a Directed Acyclic Graph (DAG) 

Given a weighted directed graph G=(V,E) and the source vertex s, the single-source shortest path
problem’s goal is to identify the shortest path from the source vertex to all vertices in the graph.
For example, finding the shortest path from our home to different adjacent cities can be modeled
as a single-source shortest path problem with our home being the source vertex.
Depending on the input graphs type, a single-source shortest path problem can be solved using
different algorithms that vary in asymptotic running time and complexity. For example, the BFS
algorithm from part 3 is sufficient to solve the single-source shortest path problem for unweighted
graphs. However, we need other algorithms to solve the single-source shortest path problem in
weighted graphs5.

In this part, your task is to write a program to solve the single-source shortest path problem for a
type of directed called directed acyclic graphs (DAG). A DAG is a directed graph with no cycles6.

The single-source shortest problem in DAGs can be solved by visiting the DAG’s vertices in a
topologically sorted order and updating the shortest path of the visited vertex’s adjacent vertices.
You must use the DFS traversal from part 4 to topologically sort the DAG.

Input-Output format: Your program will take two file names as its command-line input. This
first file includes a DAG, and it follows the same format from parts 2 and 4. Your program reads the
contents of this file and constructs the graph data structure. The first line in this file provides the
number of vertices in the DAG. Each following line includes information about a weighted directed
edge in the DAG. Each weighted edge is described by the name of its pair of vertices, followed by
the edge weight, separated by a space. Your program must read and construct this DAG,
The second file includes single source shortest path queries on the constructed DAG. Each line
contains a different single-source shortest path query by specifying a source vertex. Your program
must read the source vertex, perform the single source shortest path algorithm using the provided
source vertex, and print out each of vertex in the DAG in lexicographic ordering, followed by the
length of the shortest path to that vertex, and a newline character. Note that an additional newline
character follows the last vertex in DAG. Further, your program must detect if the input graph is
not a DAG. In such cases, your program simply prints out CYCLE, followed by a newline character.

Example Execution:

Let’s assume we have the following graph input file:

graph.txt
7
A
B
C
D
E
F
G
A D 10
A C 5
B D 7
C D 3
D E 5
E F 1
C F 10
E G 10
F G 5

query.txt
A
G

Then the result will be:
$./fifth graph.txt query.txt
A 0
B INF
C 5
D 8
E 13
F 14
G 19

A INF
B INF
C INF
D INF
E INF
F INF
G 0

For the scenario when the input graph is not a DAG:

not_dag.txt
2
CA
NJ
NJ CA 3000
CA NJ 3100

query.txt
CA

Then the result will be:
$./fifth not_dag.txt query.txt
CYCLE

We will not give you improperly formatted files. You can assume all your input files will be in
proper format, as stated above.
