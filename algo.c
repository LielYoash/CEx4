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
void A(node *head);
void B(node *head);
void D(node *head);
void S(node *head);
void T(node *head);
int shortestPathFunc(int source, int target, node *head);
int countNodes(node *head);

void funcHelper(int startNodeID, int endNodeId, int weight, node *head)
{
    while (endNodeId != 0 && weight != 0)
    {
        if (isalpha(startNodeID) || isalpha(endNodeId) || isalpha(weight))
        {
            break;
        }
        addEdge(startNodeID, endNodeId, weight, head);
    }
}

void deleteGraph(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        edge *temp2 = temp->edge;
        while (temp2 != NULL)
        {
            edge *temp3 = temp2;
            temp2 = temp2->next;
            free(temp3);
        }
        node *temp4 = temp;
        temp = temp->next;
        free(temp4);
    }
}

int countNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void A(node *head)
{
    if (head != NULL)
    {
        deleteGraph(head);
    }
    
    int numOfNodes, startNodeId, endNodeId, weight;
    char init;
    scanf("%d", &numOfNodes);
    for (int i = 0; i < numOfNodes; i++)
    {
        addNodeToEnd(head, i);
    }
    while (scanf("%c", &init) != 0)
    {
        if (init == 'n')
        {
            scanf("%d %d %d", &startNodeId, &endNodeId, &weight);
            funcHelper(startNodeId, endNodeId, weight, head);
        }
        else
        {
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void B(node *head)
{
    int startNodeID, endNodeID, weight;
    scanf("%d", &startNodeID);
    node *temp = getNode(startNodeID, head);
    if (temp == NULL)
    {
        addNodeToEnd(head, startNodeID);
        scanf("%d %d", &endNodeID, &weight);
        funcHelper(startNodeID, endNodeID, weight, head);
    }
    else
    {
        cleanEdges(temp->edge);
        temp->edge = NULL;
        funcHelper(startNodeID, endNodeID, weight, head);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void D(node *head)
{
    int id;
    scanf("%d", &id);
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->nodeID == id)
        {
            deleteEdges(temp->nodeID, temp, temp->edge);
        }
        temp = temp->next;
    }
    deleteNodes(id, head);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void S(node *head)
{
    int startNodeID, endNodeID;
    scanf("%d %d", &startNodeID, &endNodeID);
    printf("Dijsktra shortest path: %d \n", shortestPathFunc(startNodeID, endNodeID, head));
}

int shortestPathFunc(int startNodeID, int endNodeID, node *head)
{
    if (head == NULL)
        return -1;
    if (startNodeID == endNodeID)
        return 0;
    node *start = getNode(startNodeID, head);
    node *end = getNode(endNodeID, head);
    if (start == NULL || end == NULL)
        return -1;

    int numberOfNodes = countNodes(head);
    int distance[numberOfNodes], visited[numberOfNodes], previous[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[startNodeID] = 0;
    int currentNode = startNodeID;
    while (currentNode != endNodeID)
    {
        visited[currentNode] = 1;
        edge *temp = start->edge;
        while (temp != NULL)
        {
            if (visited[temp->endNode] == 0)
            {
                if (distance[temp->endNode] > distance[currentNode] + temp->weight)
                {
                    distance[temp->endNode] = distance[currentNode] + temp->weight;
                    previous[temp->endNode] = currentNode;
                }
            }
            temp = temp->next;
        }
        int minDistance = INT_MAX;
        currentNode = -1;
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (visited[i] == 0 && distance[i] < minDistance)
            {
                minDistance = distance[i];
                currentNode = i;
            }
        }
        if (currentNode == -1)
            break;
    }
    return distance[endNodeID];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void T(node *head)
{
    int count;
    scanf("%d", &count);
    if (count == 0)
    {
        return;
    }
    int cities[count];
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &cities[i]);
    }
    int fac = factorial(count);
    int perm[fac];
    int temp = 0;
    permutation(head, cities, 0, count - 1, perm, &temp);
    int ind = find_minimum(perm, fac);
    if (perm[ind] == INT_MAX)
    {
        printf("TSP shortest path: %d \n", -1);
    }
    else
    {
        printf("TSP shortest path: %d \n", perm[ind]);
    }
}

int arrayCalculate(node *head, int cities[], int size)
{
    int distance = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        int path = shortestPathFunc(head, cities[i], cities[i + 1]);
        if (path == -1)
        {
            return INT_MAX;
        }
        distance += path;
    }
    return distance;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(node *head, int *cities, int start, int end, int *perm, int *ind)
{
    if (start == end)
    {
        perm[(*ind)++] = arrayCalculate(head, cities, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        swap((cities + i), (cities + start));
        permutation(head, cities, start + 1, end, perm, ind);
        swap((cities + i), (cities + start));
    }
}

int find_minimum(int arr[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[index])
        {
            index = i;
        }
    return index;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    return factorial(num - 1) * num;
}
