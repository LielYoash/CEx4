
// Description: Header file for nodes.c

typedef struct Nodes{
    int nodeID;
    struct edge *edge;
    struct node *next;
} node;


node *createNode(int id);
void deleteNodes(int id, node *head);
void addNodeToEnd(node *head, int id);
node getNode(int id, node *head);
