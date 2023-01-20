#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"

edge *createEdge(node *endNode, int weight)
{
    edge *edge = malloc(sizeof(*edge));
    if (edge == NULL)
    {
        return NULL;
    }
    edge->endNode = endNode;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void insertEdgeToEnd(node *dest, int weight, node *head)
{
    edge *temp = head->edge;
    if (temp == NULL)
    {
        head->edge = createEdge(dest, weight);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createEdge(dest, weight);
    }
}

void addEdge(int src, int dest, int weight, node *head)
{
    node *temp = head;
    node *source = NULL;
    node *destination = NULL;
    while (temp != NULL)
    {
        if (temp->nodeID == src)
        {
            source = temp;
        }
        if (temp->nodeID == dest)
        {
            destination = temp;
        }
        temp = temp->next;
    }
    if (!source || !destination)
    {
        return;
    }
    insertEdgeToEnd(destination, weight, source);
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
 edge *getEdge(node *head, node *end){
         edge *temp_edge = head->edge;
         while (temp_edge)
         {
             if (temp_edge->endNode == end)
             {
                 return temp_edge;
             }
             temp_edge = temp_edge->next;
         }
         return NULL;
     }
