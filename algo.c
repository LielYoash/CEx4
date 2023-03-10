#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <ctype.h>
#include <limits.h>

#define MILLION 1000000

void menu(char c, node *graph) {
    switch (c) {
        case 'A':
            A(graph);
            break;
        case 'B':
            B(graph);
            break;
        case 'D':
            D(graph);
            break;
        case 'S':
            S(graph);
            break;
        case 'T':
            T(graph);
            break;
        default:
            if (c == EOF)
                return;
    }
}

void funcHelper(int startNodeID, int endNodeId, int weight, node *head) {
    while (scanf(" %d %d", &endNodeId, &weight) != 0) {
        if (isalpha(startNodeID) || isalpha(endNodeId) || isalpha(weight)) {
            break;
        }
        addEdge(startNodeID, endNodeId, weight, head);
    }
}

void deleteGraph(node *head) {
    node *temp = head;
    while (temp != NULL) {
        edge *temp2 = temp->edge;
        while (temp2 != NULL) {
            edge *temp3 = temp2;
            temp2 = temp2->next;
            free(temp3);
        }
        node *temp4 = temp;
        temp = temp->next;
        free(temp4);
    }
}


int min(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a < b ? a : b;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void A(node *head) {
    int numOfNodes, startNodeId, endNodeId, weight;
    scanf(" %d", &numOfNodes);
    node *curr = head;
    for (int i = 1; i < numOfNodes; i++) {
        addNodeToEnd(curr, i);
    }
    char init = 0;

    while (scanf(" %c", &init) != 0) {
        if (init == 'n') {
            scanf(" %d", &startNodeId);

            funcHelper(startNodeId, endNodeId, weight, head);
        } else {
            break;
        }
    }
    menu(init, head);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void B(node *head) {
    int startNodeID, endNodeID, weight;
    scanf(" %d", &startNodeID);
    node *temp = getNode(startNodeID, head);
    if (temp == NULL) {
        addNodeToEnd(head, startNodeID);
        funcHelper(startNodeID, endNodeID, weight, head);
    } else {
        cleanEdges(temp->edge);
        temp->edge = NULL;
        funcHelper(startNodeID, endNodeID, weight, head);
    }
    menu(getchar(), head);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void D(node *head) {
    deleteNodes(head);
    menu(getchar(), head);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S(node *head) {
    int startNodeID, endNodeID, shortest;
    scanf(" %d", &startNodeID);
    scanf(" %d", &endNodeID);
    shortest = shortestPathLength(startNodeID, endNodeID, head);
    printf("Dijkstra shortest path: %d \n", shortest);
}

int getNumNodes(node *head) {
    if (head == NULL) {
        return -1;
    }
    node *pNode = head;
    int ctr = 0;
    while (pNode) {
        if (ctr < pNode->nodeID) {
            ctr = pNode->nodeID;
        }
        pNode = pNode->next;
    }
    return ctr + 1;
}

void initMatrix(int mat[], int numNodes) {
    for (int k = 0; k < numNodes; k++) {
        for (int i = 0; i < numNodes; i++) {
            mat[k*numNodes+i] = MILLION;
        }
    }
}

void fillMatrix(int mat[], node *head, int numNodes) {
    node *pNode = head;
    while (pNode) {
        edge *pEdge = pNode->edge;
        while (pEdge) {
            mat[pNode->nodeID*numNodes+pEdge->endNode->nodeID] = pEdge->weight;
            pEdge = pEdge->next;
        }
        pNode = pNode->next;
    }
}

void floydWarshall(int mat[], int numNodes) {
    for (int k = 0; k < numNodes; k++) {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (i == j) {
                    mat[i*numNodes+i] = 0;
                } else if (i == k || j == k) {
                    mat[i*numNodes+j] = mat[i*numNodes+j];
                } else {
                    int b = mat[i*numNodes+k] + mat[k*numNodes+j];
                    if (mat[i*numNodes+k] == 0 || mat[k*numNodes+j] == 0) {
                        b = 0;
                    }
                    mat[i*numNodes+j] = min(mat[i*numNodes+j], b);
                }
            }
        }
    }
}

int shortestPathLength(int source, int target, node *head) {
    int numNodes = getNumNodes(head);
    if (numNodes == -1) {
        return -1;
    }
    int mat[numNodes*numNodes];
    initMatrix(mat, numNodes);
    fillMatrix(mat, head, numNodes);
    floydWarshall(mat, numNodes);
    if (mat[source*numNodes+target] == MILLION) {
        return -1;
    }
    return mat[source*numNodes+target];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void T(node *head) {
    int num_of_cities;
    scanf("%d", &num_of_cities);
    if (num_of_cities == 0) {
        return;
    }
    int cities[num_of_cities];
    for (size_t i = 0; i < num_of_cities; i++) {
        scanf("%d", &cities[i]);
    }
    int fac = factorial(num_of_cities);
    int perm[fac];
    int temp = 0;
    permutation(head, cities, 0, num_of_cities - 1, perm, &temp);
    find_minimum(perm, fac);

}

int calcArray(node *head, int cities[], int size) {
    int distance = 0;

    for (size_t i = 0; i < size - 1; i++) {
        int path_length = shortestPathLength(cities[i], cities[i + 1], head);
        if (path_length == -1) {
            return -1;
        }
        distance += path_length;
    }
    return distance;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(node *head, int *cities, int start, int end, int *perm, int *ind) {
    if (start == end) {
        int curr_permutation_length = calcArray(head, cities, end + 1);
        perm[(*ind)++] = curr_permutation_length;
        return;
    }
    int i;
    for (i = start; i <= end; i++) {
        swap((cities + i), (cities + start));
        permutation(head, cities, start + 1, end, perm, ind);
        swap((cities + i), (cities + start));
    }
}

void find_minimum(int perm[], int n) {
    int minWeight = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (perm[i] != -1) {
            if (perm[i] < minWeight) {
                minWeight = perm[i];
            }
        }
    }

    if (minWeight == INT_MAX) {
        printf("TSP shortest path: %d \n", -1);
    } else {
        printf("TSP shortest path: %d \n", minWeight);
    }
}

int factorial(int num) {
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    return factorial(num - 1) * num;
}

