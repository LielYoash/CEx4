#ifndef EDGES_H
#define EDGES_H

// Description: Header file for edges.c

typedef struct Node node;

typedef struct Edge
{
    int startNode;
    int endNode;
    int weight;
    struct edge *next;
} edge;

edge *createEdge(node *endNode, int weight);
void deleteEdges(int nodeID, node *node, edge *edge);
void insertEdgeToEnd(node *dest,int weight, node *head);
void addEdge(int src, int dest, int weight, node *head);
void cleanEdges(edge *edge);

#endif