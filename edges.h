
// Description: Header file for edges.c
Edge *createEdge(node *endNode, int weight);
void deleteEdges(int nodeID, node *node, edge *edge);
void addEdgeToEnd(node dest,int weight, node *head);
void addEdge(int src, int dest, int weight, node *head);
void cleanEdges(edge *edge);