#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct adjacency
{
    int vertices;
    int edges;
    int **adjacencyMatrix;
};

typedef struct adjacency node;

struct edge
{
    int source;
    int destination;
};

typedef struct edge edge;

void rand_init(void)
{
    time_t t;
    srand((unsigned)time(&t));
}

node *createGraph(const int numVertices)
{
    assert(numVertices > 0);
    int i, j;
    node *g;
    g = (node *)malloc(sizeof(node));
    g->vertices = numVertices;
    g->edges = 0;
    g->adjacencyMatrix = malloc((sizeof(int)) * numVertices);
    assert(g != NULL);
    for (int i = 0; i < numVertices; i++)
    {
        (g->adjacencyMatrix)[i] = calloc(numVertices, sizeof(int));
        assert((g->adjacencyMatrix)[i] != NULL);
    }
    return g;
}

void display(const node *g)
{
    int i, v, j;
    v = g->vertices;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%3d\t", (g->adjacencyMatrix)[i][j]);
        }
    }
}

void displayEdge(const node *g)
{
    // 9663288050
    int v, i, j;
    v = g->vertices;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if ((g->adjacencyMatrix)[i][j] != 0)
            {
                printf("\n%d %d\n", i, j);
            }
        }
    }
}

void insertEdge(node *g, edge e){
    int v, x, y;
    v=g->vertices;
    x=e.source;
    y=e.destination;
    if((g->adjacencyMatrix)[x][y]==0){
        g->adjacencyMatrix[x][y]=1;
    }
}

