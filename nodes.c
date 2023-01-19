#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include <ctype.h>
#include "algo.h"

node *createNode(int id);
void deleteNodes(int id, node *head);
void addToEnd(node *head, int id);
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



