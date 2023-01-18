#ifndef NODES_H
#define NODES_H

// Description: Header file for nodes.c

typedef struct Edge edge;

typedef struct Node{
    int nodeID;
    struct edge *edge;
    struct node *next;
} node;


node *createNode(int id);
void deleteNodes(int id, node *head);
void addNodeToEnd(node *head, int id);
node getNode(int id, node *head);

#endif