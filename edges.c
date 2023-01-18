
#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"



edge *createEdge(node *endNode, int weight);
void deleteEdges(int nodeID, node *node, edge *edge);
void addEdgeToEnd(node dest,int weight, node *head);
void addEdge(int src, int dest, int weight, node *head);
void cleanEdges(edge *edge);

edge *createEdge(node *endNode, int weight)
{
    edge *edge = malloc(sizeof(edge));
    if (edge == NULL)
    {
        return NULL;
    }
    edge->endNode = endNode;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void deleteEdges(int nodeID, node *node, edge *e)
{
    if (e == NULL)
        return;
    edge *temp = e;
    edge *prev = NULL;
    while (temp != NULL)
    {
        if (temp->endNode == nodeID)
        {
            if (prev == NULL)
            {
                e = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void insertEdge(node *dest,int weight, node *head){
    edge *temp = head->edge;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createEdge(dest,weight);
}

void addEdge(int src, int dest, int weight, node *head){
    node *temp = head;
    node *source = NULL;
    node *destination = NULL;
    while (temp != NULL) {
        if (temp->nodeID == src) {
            source = temp;
        }
        if (temp->nodeID == dest) {
            destination = temp;
        }
        temp = temp->next;
    }
    if(!source || !destination){
        return;
    }
    insertEdge(destination,weight,source);
}

void cleanEdges(edge *e)
{
    edge *temp = e;
    while (temp != NULL)
    {
        edge *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}
