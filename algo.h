#ifndef ALGO_H
#define ALGO_H

typedef struct Edge edge;
typedef struct Node node;

void menu(char c, node *graph);
void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
void A(node *head);
void B(node *head);
void D(node *head);
void S(node *head);
void T(node *head);
int getNumNodes(node *head);
void initMatrix(int mat[], int numNodes);
void fillMatrix(int mat[], node *head, int numNodes);
void floydWarshall(int mat[], int numNodes);
int shortestPathLength(int source, int target, node *head);
void find_minimum(int perm[], int n);
void permutation(node *head, int *cities, int start, int end, int *perm, int *ind);
void swap(int *a, int *b);
int factorial(int num);

#endif