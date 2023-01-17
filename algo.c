#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <ctype.h>

void A()
{
    int numOfNodes, startNodeId, endNodeId, weight;
    node *head = NULL;
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
            while (endNodeId != 0 && weight != 0)
            {
                if (isalpha(startNodeId) || isalpha(endNodeId) || isalpha(weight))
                {
                    break;
                }
                addEdge(startNodeId, endNodeId, weight, head);
            }
        }
        else
        {
            break;
        }
    }
}


// void deleteGraph()
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         edge *temp2 = temp->edge;
//         while (temp2 != NULL)
//         {
//             edge *temp3 = temp2;
//             temp2 = temp2->next;
//             free(temp3);
//         }
//         node *temp4 = temp;
//         temp = temp->next;
//         free(temp4);
//     }
// }

// int isComplete()
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         edge *temp2 = temp->edge;
//         while (temp2 != NULL)
//         {
//             if (temp2->endNode == temp->nodeID)
//             {
//                 temp2 = temp2->next;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         temp = temp->next;
//     }
//     return 1
// }

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void B()
// {
//     int startNodeId, endNodeId, weight;
//     scanf("%d %d %d", &startNodeId, &endNodeId, &weight);
//     if (exist(startNodeId) == 1)
//     {
//         reset(startNodeId);
//     }
//     else
//     {
//         createNode(startNodeId);
//     }
//     addEdge(startNodeId, endNodeId, weight);
// }

// void exist(int id)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->nodeID == id)
//         {
//             return 1;
//         }
//         temp = temp->next;
//     }
//     return 0;
// }

// void reset(int id)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->nodeID == id)
//         {
//             edge *temp2 = temp->edge;
//             while (temp2 != NULL)
//             {
//                 edge *temp3 = temp2;
//                 temp2 = temp2->next;
//                 free(temp3);
//             }
//             temp->edge = NULL;
//             return;
//         }
//         temp = temp->next;
//     }
// }
