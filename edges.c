
#include <stdio.h>
#include <stdlib.h>

Edge* createEdge(int src, int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->weight = weight;
    return newEdge;
}

typedef struct Edges{
    int startNode;
    int endNode;
    int weight;
    struct edge *next;
} edge;
