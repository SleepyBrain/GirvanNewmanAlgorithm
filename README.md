                                            
                                            The Girvan-Newman Algorithm

  It’s one of the easiest algorithms on community detection in Social Networks. It works based on Betweenness of the edges in a graph
representing communication in social networks.This algorithm works in three main steps:

01.	First  BFS (Breadth First Search) is applied among the nodes of the graph taking a particular node as the root. Edges between two nodes
in a same level is to be avoided. 

02.	Every node is labeled with the number of shortest paths from root to that node assuming the label of the root as 1. Each node is labeled
by the sum of the label of its parents .

03.	This is the main and final step of this algorithm. This step begins from the bottom of the graph crediting all leaves as 1.For the 
internal nodes this credit will be plus 1 with the sum of credits of their children. Credits of a child will be divided equally among its
parents. Credits of a child will be counted as the betweenness of the edge between that child and its parent. This process ends at the root.
These steps are repeated considering each  node as root until all of the nodes are visited.

Finally the resultant betweenness of each edge will be half of the betweenness calculated from this algorithm as a shortest path was counted twice.

