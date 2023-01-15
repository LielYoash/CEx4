#include <stdio.h>
#include "nodes.c"

void A()
{
    int numOfNodes, startNodeId, endNodeId, weight;
    char init;
    scanf("%d", &numOfNodes);
    if (exist(0) == 1)
    {
        deleteGraph;
    }
    for (int i = 0; i < numOfNodes; i++)
    {
        createNode(i);
    }
    if (scanf("%c", &init) == 'n')
    {
        addEdges();
    }
}

void addEdges()
{
    int startNodeId, endNodeId, weight;
    char c;
    scanf("%d %d %d", &startNodeId, &endNodeId, &weight);
    createEdge(startNodeId, endNodeId, weight);
    while (scanf("%c", &c) != 'n')
    {
        if (isComplete() == 1)
        {
            return;
        }
        else
        {
            scanf("%d %d", &endNodeId, &weight);
            createEdge(startNodeId, endNodeId, weight);
        }
        if (scanf("%c", &c) == 'n')
        {
            addEdges();
        }
    }
}

void deleteGraph()
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

int isComplete()
{
    node *temp = head;
    while (temp != NULL)
    {
        edge *temp2 = temp->edge;
        while (temp2 != NULL)
        {
            if (temp2->endNode == temp->nodeID)
            {
                temp2 = temp2->next;
            }
            else
            {
                return 0;
            }
        }
        temp = temp->next;
    }
    return 1
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void B()
{
    int startNodeId, endNodeId, weight;
    scanf("%d %d %d", &startNodeId, &endNodeId, &weight);
    if (exist(startNodeId) == 1)
    {
        reset(startNodeId);
    }
    else
    {
        createNode(startNodeId);
    }
    addEdge(startNodeId, endNodeId, weight);
}

void exist(int id)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->nodeID == id)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void reset(int id)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->nodeID == id)
        {
            edge *temp2 = temp->edge;
            while (temp2 != NULL)
            {
                edge *temp3 = temp2;
                temp2 = temp2->next;
                free(temp3);
            }
            temp->edge = NULL;
            return;
        }
        temp = temp->next;
    }
}
