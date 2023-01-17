#ifdef EDGES_H
#define EDGES_H

// Description: Header file for edges.c

typedef struct Nodes node;
typedef struct Edges edge;


edge *createEdge(node *endNode, int weight);
void deleteEdges(int nodeID, node *node, edge *edge);
void addEdgeToEnd(node dest,int weight, node *head);
void addEdge(int src, int dest, int weight, node *head);
void cleanEdges(edge *edge);

#endif