#include <stdio.h>
#include "nodes.c"

void A()
{
    int numOfNodes, startNodeId, endNodeId, weight;
    char init;
    scanf("%d", &numOfNodes);
    for (int i = 0; i < numOfNodes; i++)
    {
        createNode(i);
    }
    if (scanf("%c", &init) == 'n')
    {
    nodesSetUp:
        scanf("%d %d %d", &startNode, &endNode, &weight);
        addEdge(startNode, endNode, weight);
        while (scanf("%c", &init) != 'n')
        {
            scanf("%d %d", &endNode, &weight);
            addEdge(startNode, endNode, weight);
        }
        if (init == 'n')
        {
            goto nodesSetUp;
        }
        else
        {
            return;
        }
    }
}

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
