#ifndef ALGO_H
#define ALGO_H

typedef struct Edge edge;
typedef struct Node node;

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
void A(node *head);
void B(node *head);


#endif