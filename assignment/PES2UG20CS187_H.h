#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int sparseMatrix[10][10];
int sr,sc,er,ec;

struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *link;
};

typedef struct Node Node;

struct Nodemove
{
	int row_position;
	int column_postion;
	struct Nodemove *rlink;
	struct Nodemove *llink;
};

typedef struct Nodemove Nodemove;

struct list
{
    Node *head;
};

typedef struct list list;

struct listmove
{
    Node *head;
};

typedef struct listmove listmove;

void initlist(list* p);
void initlistm(listmove* p);
void creatematrix(list* spm, int ele,int row, int column);
void create(listmove* spm,int row, int column);
void display(listmove* spm);
void read(list* spm);
void movement(list* spm,listmove* move);
