#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <ctype.h>

void funcHelper(int startNodeID, int endNodeId, int weight, node *head);
void deleteGraph(node *head);
void A(node *head);
void B(node *head);


void funcHelper(int startNodeID, int endNodeId, int weight, node *head)
{
    while (endNodeId != -1 && weight != 0)
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
