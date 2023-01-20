#include <stdio.h>
#include <stdlib.h>
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
//        switch (c)
//        {
//        case 'A':
//            c= A(graph);
//            break;
//        case 'B':
//            c= B(graph);
//            break;
//        case 'D':
//            D(graph);
//            break;
//        case 'S':
//            S(graph);
//            break;
//        case 'T':
//            T(graph);
//            break;
//        }
    }
    deleteGraph(graph);
    return 0;
}