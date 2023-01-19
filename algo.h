#ifndef ALGO_H
#define ALGO_H

typedef struct Edge edge;
typedef struct Node node;

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
char A(node *head);
char B(node *head);
char D(node *head);
void S(node *head);
char T(node *head);
int shortestPathFunc( int source, int target, node *head);
int countNodes(node *head);
int find_minimum(int arr[], int n, int *min_distance);
#endif