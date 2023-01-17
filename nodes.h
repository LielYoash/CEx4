#ifdef NODES_H
#define NODES_H

// Description: Header file for nodes.c

typedef struct Edges edge;
typedef struct Nodes node;


node *createNode(int id);
void deleteNodes(int id, node *head);
void addNodeToEnd(node *head, int id);
node getNode(int id, node *head);

#endif