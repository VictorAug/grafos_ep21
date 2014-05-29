#include "grafos_ep21m.h"
#include "grafos_ep21Q.h"

Arc ARC(Vertex v, Vertex w)
{
	Arc e;
	e.v = v;
	e.w = w;
	return e;
}

int **MATRIXInt(int r, int c, int val)
{
	int i, j;
	int **m = malloc(r*sizeof(int*));
	for(i = 0; i < r; i++)
		m[i] = malloc(c*sizeof(int));
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			m[i][j] = val;
	return m;
}

Digraph Matriz_DIGRAPHInit(int V)
{
	Digraph G = malloc(sizeof *G);
	G->V = V;
	G->A = 0;
	lbl = malloc(V*sizeof(int));
	dist = malloc(V*sizeof(int));
	parent = malloc(V*sizeof(int));
	G->adj = MATRIXInt(V, V, 0);
	return G;
}

int Matriz_DIGRAPHInsertA(Digraph G, Vertex v, Vertex w)
{
	if(v != w && G->adj[v][w] == 0){
		G->adj[v][w] = 1;
		G->A++;
		return 1;
	}
	else return 0;
}

void Matriz_DIGRAPHRemoveA(Digraph G, Vertex v, Vertex w)
{
	if(G->adj[v][w] == 1){
		G->adj[v][w] = 0;
		G->A--;
	}
}

void Matriz_DIGRAPHShow(Digraph G)
{
	Vertex v, w;
	printf("    |  0  ");
	for(v = 1; v < G->V; v++)
        printf("|  %d  ",v);
    printf("\n----+-----");
    for(v = 1; v < G->V; v++)
        printf("+-----");
	for(v = 0; v < G->V; v++){
		printf("\n  %d ", v);
		for(w = 0; w < G->V; w++){
			if(G->adj[v][w] == 0)
				printf("|  0  ");
			else printf("|  1  ");
		}
	}
	printf("\n");
}

int Matriz_GRAPHInsertE(Graph G, Vertex v, Vertex w)
{
	if(G->V > v && G->V > w && v != w)
    {
		Matriz_DIGRAPHInsertA(G,w,v);
		Matriz_DIGRAPHInsertA(G,v,w);
		return 1;
	}
	else return 0;
}

void Matriz_GRAPHRemoveE(Digraph G, Vertex v, Vertex w)
{
	Matriz_DIGRAPHRemoveA(G,v,w);
	Matriz_DIGRAPHRemoveA(G,w,v);
}

void reset_lbl()
{
	int i;
	for(i = 0; i < USHRT_MAX; i++)
		lbl[i] = 0;
}

void Matriz_DIGRAPHbfs(Digraph G, Vertex s)
{
    Vertex v, w;
    cnt = 0;
    for(v = 0; v < G->V; v++)
        lbl[v] = parent[v] = -1;
    QUEUEInit(G->V);
    lbl[s] = cnt++;
    parent[s] = s;
    QUEUEPut(s);
    printf("____");
    for(w = 1; w < G->V; w++)
        printf("_____");
    printf("\n\n  i ");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",w);
    printf("\n----+-----");
    for(w = 1; w < G->V; w++)
        printf("+-----");
    printf("\nFILA");
    while(!QUEUEEmpty())
    {
        v = QUEUEGet();
        printf("|  %d  ",v);
        for(w = 0; w < G->V; w++)
            if(G->adj[v][w] == 1 && lbl[w] == -1){
                lbl[w] = cnt++;
                parent[w] = v;
                QUEUEPut(w);
            }
    }
    printf("\n____");
    for(w = 1; w < G->V; w++)
        printf("_____");
    printf("\n\n");
    Matriz_DIGRAPHShow1(G);
}

void Matriz_DIGRAPHShow1(Digraph G)
{
    Vertex w;
    printf("______");
    for(w = 1; w < G->V; w++)
        printf("______");
    printf("\n\n    i ");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",w);
    printf("\n------+-----");
    for(w = 1; w < G->V; w++)
        printf("+-----");
    printf("\nPARENT");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",parent[w]);
    printf("\n______");
    for(w = 1; w < G->V; w++)
        printf("_____");
    printf("\n\n");
}

void Matriz_DIGRAPHShow2(Digraph G)
{
    Vertex w;
    printf("____");
    for(w = 1; w < G->V; w++)
        printf("_____");
    printf("\n\n  i ");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",w);
    printf("\n----+-----");
    for(w = 1; w < G->V; w++)
        printf("+-----");
    printf("\nDIST");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",dist[w]);
    printf("\n____");
    for(w = 0; w < G->V; w++)
        printf("_____");
    printf("\n");
}

void Matriz_DIGRAPHdist(Digraph G, Vertex s)
{
    Vertex v,w;
    for(v = 0; v < G->V; v++)
    {
        dist[v] = G->V;
        parent[v] = -1;
    }
    QUEUEInit(G->V);
    dist[s] = 0;
    parent[s] = s;
    QUEUEPut(s);
    while(!QUEUEEmpty())
    {
        v = QUEUEGet();
        for(w = 0; w < G->V; w++)
            if(G->adj[v][w] == 1)
                if(dist[w] == G->V){
                    dist[w] = dist[v] + 1;
                    parent[w] = v;
                    QUEUEPut(w);
                }
    }
    QUEUEFree();
    printf("\n");
    Matriz_DIGRAPHShow1(G);
    Matriz_DIGRAPHShow2(G);
    printf("\n");
}

Digraph Matriz_DIGRAPHdel()
{
    Digraph Matrix;
    Matrix->V = 0;
    Matrix->A = 0;
    return Matrix;
}
