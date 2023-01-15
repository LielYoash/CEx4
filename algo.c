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
    addEdge(startNodeId, endNodeId, weight);
}
