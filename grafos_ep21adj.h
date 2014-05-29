#ifndef GRAFOS_EP21ADJ_H_INCLUDED
#define GRAFOS_EP21ADJ_H_INCLUDED
#include <limits.h>
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
static int *parent, *dist, *lbl, c;

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

void reset_cc();

adj_Digraph adj_DIGRAPHInit(int);

link adj_NEW(Vertex, link);

void adj_DIGRAPHInsertA(adj_Digraph, Vertex, Vertex);

void adj_DIGRAPHShow(adj_Digraph);

void adj_GRAPHInsertE(adj_Graph, Vertex, Vertex);

void adj_DIGRAPHRemoveE(adj_Graph, Vertex, Vertex);

void adj_ShowVector(adj_Digraph);

void adj_DIGRAPHbfs(adj_Digraph, Vertex);

void adj_DIGRAPHdist(adj_Digraph, Vertex);

void adj_DIGRAPHShow2(adj_Digraph);

adj_Digraph adj_DIGRAPHdel();

#endif
