#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <ctype.h>

#define MAX 1000000

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
int min(int a, int b);
void A(node *head);
void B(node *head);
void D(node *head);
void S(node *head);
void T(node *head);
int shortestPathFunc( int source, int target, node *head);

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

int min(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void A(node *head)
{
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
    node *temp = head;
    *temp = getNode(startNodeID, head);
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
    printf("%d", shortestPathFunc(startNodeID, endNodeID, head));
}

int shortestPathFunc( int source, int target, node *head)
{
    int *dist = malloc(sizeof(int) * 100);
    int *prev = malloc(sizeof(int) * 100);
    int *visited = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++)
    {
        dist[i] = 1000000;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[source] = 0;
    node *temp = head;
    while (temp != NULL)
    {
        int min = 1000000;
        int minIndex = -1;
        for (int i = 0; i < 100; i++)
        {
            if (visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1)
        {
            break;
        }
        visited[minIndex] = 1;
        edge *temp2 = temp->edge;
        while (temp2)
        {
            if (dist[temp2->endNode] > dist[minIndex] + temp2->weight)
            {
                dist[temp2->endNode] = dist[minIndex] + temp2->weight;
                prev[temp2->endNode] = minIndex;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    int path = 0;
    int temp3 = target;
    while (temp3 != source)
    {
        path += dist[temp3];
        temp3 = prev[temp3];
    }
    return path;
}
  

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void T(node *head){
    int *dist = malloc(sizeof(int) * 100);
    int *prev = malloc(sizeof(int) * 100);
    int *visited = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++)
    {
        dist[i] = 1000000;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[0] = 0;
    node *temp = head;
    while (temp != NULL)
    {
        int min = 1000000;
        int minIndex = -1;
        for (int i = 0; i < 100; i++)
        {
            if (visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1)
        {
            break;
        }
        visited[minIndex] = 1;
        edge *temp2 = temp->edge;
        while (temp2)
        {
            if (dist[temp2->endNode] > dist[minIndex] + temp2->weight)
            {
                dist[temp2->endNode] = dist[minIndex] + temp2->weight;
                prev[temp2->endNode] = minIndex;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    int path = 0;
    int temp3 = 0;
    while (temp3 != 0)
    {
        path += dist[temp3];
        temp3 = prev[temp3];
    }
    printf("%d", path);
}