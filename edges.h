#ifndef EDGES_H
#define EDGES_H

// Description: Header file for edges.c

typedef struct Node node;

typedef struct Edge
{
    node *endNode;
    int weight;
    struct edge *next;
} edge;

edge *createEdge(node *endNode, int weight);
void deleteEdges(int nodeID, node *node, edge *edge);
void insertEdgeToEnd(node *dest,int weight, node *head);
void addEdge(int src, int dest, int weight, node *head);
void cleanEdges(edge *edge);
edge *getEdge(node *head, node *end);


#endif