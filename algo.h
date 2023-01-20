#ifndef ALGO_H
#define ALGO_H

typedef struct Edge edge;
typedef struct Node node;

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
void A(node *head);
void B(node *head);
void D(node *head);
void S(node *head);
void T(node *head);
int shortestPathLength(int source, int target, node *head);
void find_minimum(int perm[], int n);
void menu(char c, node *graph);
#endif