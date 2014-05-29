#ifndef GRAFOS_EP21ADJ_H_INCLUDED
#define GRAFOS_EP21ADJ_H_INCLUDED
#include "grafos_ep21.h"

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
