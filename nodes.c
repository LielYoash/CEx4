#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include <ctype.h>
#include "algo.h"

node *createNode(int id);
void deleteNodes(node *head);
void addNodeToEnd(node *head, int id);
node *getNode(int id, node *head);

node *createNode(int id) {
    node *node = malloc(sizeof(node));
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
    node *nodeToDelete = getNode(id,head);
    if (nodeToDelete != NULL)
    {
        // remove edges pointing to this node
        node *temp = head;
        while (temp != NULL)
        {
            edge *edgeToDelete = getEdge(temp, nodeToDelete);
            if (edgeToDelete != NULL)
            {
                // remove the edge
                if (temp->edge == edgeToDelete)
                {
                    temp->edge = edgeToDelete->next;
                }
                else
                {
                    edge *prevEdge = temp->edge;
                    while (prevEdge->next != edgeToDelete)
                    {
                        prevEdge = prevEdge->next;
                    }
                    prevEdge->next = edgeToDelete->next;
                }
                free(edgeToDelete);
            }
            temp = temp->next;
        }

        // remove the node
        if (head == nodeToDelete)
        {
            head = nodeToDelete->next;
        }
        else
        {
            node *prevNode = head;
            while (prevNode->next != nodeToDelete)
            {
                prevNode = prevNode->next;
            }
            prevNode->next = nodeToDelete->next;
        }
        free(nodeToDelete);
    }
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



