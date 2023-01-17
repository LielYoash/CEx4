
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
    Edge *edge = malloc(sizeof(Edge));
    if (edge == NULL)
    {
        return NULL;
    }
    edge->endNode = endNode;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void deleteEdges(int nodeID, node *node, edge *edge)
{
    if (edge == NULL)
        return;
    edge *temp = edge;
    edge *prev = NULL;
    while (temp != NULL)
    {
        if (temp->endNode == nodeID)
        {
            if (prev == NULL)
            {
                edge = temp->next;
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

void addEdgeToEnd(node dest,int weight, node *head){
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createEdge(dest,weight);
}

void addEdge(int src, int dest, int weight, node *head){
    node *temp = head;
    while (temp != NULL) {
        if (temp->nodeID == src) {
            addEdgeToEnd(dest,weight,temp);
        }
        temp = temp->next;
    }
}

void cleanEdges(edge *edge)
{
    edge *temp = edge;
    while (temp != NULL)
    {
        edge *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}
