#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "algo.h"

node *createNode(int id) {
    node *node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }
    node->nodeID = id;
    node->edge = NULL;
    node->next = NULL;
    return node;
}

void deleteNodes(node *head){
    int id;
    scanf("%d", &id);
    node *dNode = getNode(id, head);
    if (!dNode)
    {
        deleteEdges(head, dNode);
        deleteNodeFromList(head, dNode);
    }
}

void deleteEdges(node *head, node *dNode){
    node *temp = head;
    while (!temp)
    {
        edge *dEdge = getEdge(temp, dNode);
        if (!dEdge)
        {
            removeEdgeFromList(temp, dEdge);
            free(dEdge);
        }
        temp = temp->next;
    }
}

void removeEdgeFromList(node *temp, edge *dEdge) {
    if (temp->edge == dEdge)
    {
        temp->edge = dEdge->next;
    }
    else
    {
        edge *pEdge = temp->edge;
        while (pEdge->next != dEdge)
        {
            pEdge = pEdge->next;
        }
        pEdge->next = dEdge->next;
    }
}

void deleteNodeFromList(node *head, node *dNode) {
    node *prevNode = head;
    while (prevNode->next != dNode)
    {
        prevNode = prevNode->next;
    }
    prevNode->next = dNode->next;
    free(dNode);
}


void addNodeToEnd(node *head, int id){
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(id);
}

node* getNode(int id, node *head){
    node *temp = head;
    while (temp != NULL) {
        if (temp->nodeID == id) {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}



