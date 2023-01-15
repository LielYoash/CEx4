#include <stdio.h>
#include <stdlib.h>


int createNode(int id){
    int *newNode = (node)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: malloc failed in makeNode");
        exit(1);
    }
    newNode->nodeID = id;
    newNode->next = NULL;
    newNode->edge = NULL;
    return newNode;
        
}

typedef struct Nodes{
    int nodeID;
    struct node *next;
    struct edge *edge;
} node;

void addEdge(node *n, int endNode, int weight) {
    edge *e = malloc(sizeof(edge));
    if (e == NULL) {
        printf("Error: malloc failed in makeEdge");
        exit(1);
    }
    e->startNode = n->nodeID;
    e->endNode = endNode;
    e->weight = weight;
    e->next = NULL;
    if (n->edge == NULL) {
        n->edge = e;
    } else {
        edge *temp = n->edge;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = e;
    }
}
void startOver(){
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
    head = NULL;
}






