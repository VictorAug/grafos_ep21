#ifndef GRAFOS_EP21_H_INCLUDED
#define GRAFOS_EP21_H_INCLUDED
#define Vertex int
#define Edge Arc
#define EDGE ARC
#define graph digraph
#define Graph Digraph
#define GRAPHInit DIGRAPHInit
#define GRAPHShow DIGRAPHShow
#define adj_graph adj_digraph
#define adj_Graph adj_Digraph
#define adjGRAPHInit adjDIGRAPHInit
#define adjGRAPHShow adjDIGRAPHShow
#include <limits.h>
#define maxV USHRT_MAX
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

static int *parent, *dist, *lbl, c, cnt;

typedef struct Arc{
	Vertex v;
	Vertex w;
}Arc;

struct digraph{
	int V;
	int A;
	int **adj;
};
typedef struct digraph *Digraph;

struct no{
	Vertex w;
	struct no *next;
};
typedef struct no *link;

struct adj_digraph{
	int V, A;
	link *adj;
};
typedef struct adj_digraph *adj_Digraph;

#endif
