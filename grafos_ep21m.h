#ifndef GRAFOS_EP21M_H_INCLUDED
#define GRAFOS_EP21M_H_INCLUDED
#include "grafos_ep21.h"

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
