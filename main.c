#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "nodes.h"
#include "edges.h"

int main()
{
    char c;
    node *graph = NULL;
    while (1)
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'A':
            A(graph);
            break;
        case 'B':
            B(graph);
            break;
        case 'D':
            D(graph);
            break;
        case 'S':
            S(graph);
            break;
        case 'T':
            T(graph);
            break;
        }
    }
    deleteGraph(graph);
}