#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct node{
    int vertex;
    struct node *next;
};

struct edge
{
    int start;
    int end;
};

struct graph{
    int v, e;
    struct node * adjacencyList[];
};

typedef struct node node;
typedef struct edge edge;
typedef struct graph graph;


