#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <ctype.h>
#include <stdbool.h>


#define INT_MAX 1000000

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);

void deleteGraph(node *head);

char A(node *head);

char B(node *head);

char D(node *head);

void S(node *head);

char T(node *head);

int shortestPathFunc(int source, int target, node *head);

int countNodes(node *head);

void permutation(node *head, int *cities, int start, int end, int *perm, int *ind);

void swap(int *a, int *b);

int factorial(int num);

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

int countNodes(node *head) {
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int min(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        return a;
    else return b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char A(node *head) {
    if (head->nodeID != -1) {
        deleteGraph(head);
    }
    int numOfNodes, startNodeId, endNodeId, weight;
    scanf(" %d", &numOfNodes);
    head = createNode(0);
    for (int i = 1; i < numOfNodes; i++) {
        addNodeToEnd(head, i);
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
    return init;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char B(node *head) {
    int startNodeID, endNodeID, weight;
    char *c;
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
    return getchar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char D(node *head) {
    int id;
    scanf("%d", &id);
    node *temp = head;
    while (temp != NULL) {
        if (temp->nodeID == id) {
            deleteEdges(temp->nodeID, temp, temp->edge);
        }
        temp = temp->next;
    }
    deleteNodes(id, head);
    return getchar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S(node *head) {
    int startNodeID, endNodeID;
    scanf("%d %d", &startNodeID, &endNodeID);
    int shortest = shortestPathFunc(startNodeID, endNodeID, head);
    printf("Dijsktra shortest path: %d \n", shortest);
}

int shortestPathFunc(int source, int target, node *head) {
    if (!head) {
        return -1;
    }
    node *curr = head;
    int N = 0;
    while (curr) {
        if (N < curr->nodeID) {
            N = curr->nodeID;
        }
        curr = curr->next;
    }
    N += 1;
    int mat[N][N];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            mat[k][i] = INT_MAX;
        }
    }

    curr = head;
    while (curr) {
        edge *ed = curr->edge;
        while (ed) {
            mat[curr->nodeID][ed->endNode->nodeID] = ed->weight;
            ed = ed->next;
        }
        curr = curr->next;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    mat[i][i] = 0;
                } else if (i == k || j == k) {
                    mat[i][j] = mat[i][j];
                } else {
                    int val = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0) {
                        val = 0;
                    }
                    mat[i][j] = min(mat[i][j], val);
                }
            }
        }
    }
    if (mat[source][target] == INT_MAX) {
        return -1;
    }
    return mat[source][target];
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char T(node *head) {
    int count;
    scanf("%d", &count);
    if (count == 0) {
        return getchar();
    }
    int cities[count];
    for (size_t i = 0; i < count; i++) {
        scanf("%d", &cities[i]);
    }
    int fac = factorial(count);
    int perm[fac];
    for (int i = 0; i < fac; i++) perm[i] = INT_MAX;
    int temp = 0;
    permutation(head, cities, 0, count - 1, perm, &temp);
    int min_distance = INT_MAX;
    int ind = find_minimum(perm, fac, &min_distance);
    if (min_distance == INT_MAX) {
        printf("TSP shortest path: %d \n", -1);
    } else {
        printf("TSP shortest path: %d \n", min_distance);
    }
}

int arrayCalculate(node *head, int cities[], int size) {
    int distance = 0;
    for (size_t i = 0; i < size - 1; i++) {
        int path = shortestPathFunc(cities[i], cities[i + 1], head);
        if (path == -1) {
            return INT_MAX;
        }
        distance += path;
    }
    if (shortestPathFunc(cities[size - 1], cities[0], head) == -1) {
        return INT_MAX;
    }
    distance += shortestPathFunc(cities[size - 1], cities[0], head);
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
        perm[(*ind)++] = arrayCalculate(head, cities, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++) {
        swap((cities + i), (cities + start));
        permutation(head, cities, start + 1, end, perm, ind);
        swap((cities + i), (cities + start));
    }
}

int find_minimum(int arr[], int n, int *min_distance) {
    int index = 0;
    *min_distance = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min_distance) {
            index = i;
            *min_distance = arr[i];
        }
    }
    return index;
}

int factorial(int num) {
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    return factorial(num - 1) * num;
}

