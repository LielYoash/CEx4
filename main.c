#include <stdio.h>
#include "algo.h"
#include "nodes.h"
#include "edges.h"

int main()
{
    char c;
    node *graph = createNode(0);
    while (scanf("%c", &c) != EOF)
    {
        menu(c,graph);
    }
    deleteGraph(graph);
    return 0;
}