#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"


node *createNode(int id);
void deleteNodes(int id, node *head);
void addToEnd(node *head, int id);
node getNode(int id, node *head);

typedef struct Nodes{
    int nodeID;
    struct edge *edge;
    struct node *next;
} node;

node *createNode(int id) {
    node *node = malloc(sizeof(node));
    if (node == NULL) {
        return NULL;
    }
    node->nodeID = id;
    node->next = NULL;
    node->edge = NULL;
    return node;
}

void deleteNodes(int id, node *head){
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL) {
        if (temp->nodeID == id) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void addNodeToEnd(node *head, int id){
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(id);
}

node getNode(int id, node *head){
    node *temp = head;
    while (temp != NULL) {
        if (temp->nodeID == id) {
            return *temp;
        }
        temp = temp->next;
    }
    return NULL;
}


