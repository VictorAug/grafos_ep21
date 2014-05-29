#ifndef GRAFOS_EP21M_H_INCLUDED
#define GRAFOS_EP21M_H_INCLUDED
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
static int *parent, *lbl, *dist, cnt;

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

Arc ARC(Vertex, Vertex);

int **MATRIXInt(int, int, int);

Digraph Matriz_DIGRAPHInit(int);

int Matriz_DIGRAPHInsertA(Digraph, Vertex, Vertex);

void Matriz_DIGRAPHRemoveA(Digraph, Vertex, Vertex);

void Matriz_DIGRAPHShow(Digraph);

void Matriz_DIGRAPHShow1(Digraph);

void Matriz_DIGRAPHShow2(Digraph);

int Matriz_GRAPHInsertE(Graph, Vertex, Vertex);

void Matriz_GRAPHRemoveE(Digraph, Vertex, Vertex);

void Matriz_DIGRAPHbfs(Digraph, Vertex);

void Matriz_DIGRAPHdist(Digraph, Vertex);

void reset_lbl();

Digraph Matriz_DIGRAPHdel();

#endif // GRAFOS_EP21M_H_INCLUDED
