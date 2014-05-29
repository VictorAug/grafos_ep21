#include "grafos_ep21.h"

adj_Digraph adj_DIGRAPHInit(int V)
{
	int v;
	adj_Digraph G = malloc(sizeof(adj_Digraph));
	G->V = V;
	G->A = 0;
	dist = malloc(V*sizeof(int));
	lbl = malloc(V*sizeof(int));
	parent = malloc(V*sizeof(int));
	G->adj = malloc(V*sizeof(link));
	for(v = 0; v < V; v++)
		G->adj[v] = NULL;
	return G;
}

link adj_NEW(Vertex w, link next)
{
	link p = malloc(sizeof(link));
	p->w = w;
	p->next = next;
	return p;
}

void adj_DIGRAPHInsertA(adj_Digraph G, Vertex v, Vertex w)
{
	link p;
	if(v == w)
		return;
	for(p = G->adj[v]; p != NULL; p = p->next)
		if(p->w == w)
			return;
	G->adj[v] = adj_NEW(w, G->adj[v]);
	G->A++;
}

void adj_DIGRAPHShow(adj_Digraph G)
{
	Vertex v;
	link p;
	for (v = 0; v < G->V; v++)
	{
		printf("%2d:", v);
		for (p = G->adj[v]; p != NULL; p = p->next)
			printf("%2d ", p->w);
		printf("\n");
	}
}

void adj_GRAPHInsertE(adj_Graph G, Vertex v, Vertex w)
{
	adj_DIGRAPHInsertA(G, v, w);
	adj_DIGRAPHInsertA(G, w, v);
}

void adj_DIGRAPHbfs(adj_Digraph G, Vertex s)
{
    Vertex v, w;
    link p;
    c = 0;
    for(v = 0; v < G->V; v++)
        lbl[v] = -1;
    QUEUEInit(G->V);
    lbl[s] = c++;
    parent[s] = s;
    QUEUEPut(s);
    printf("____");
    for(w = 0; w <= G->V; w++)
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
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(lbl[p->w] == -1){
                lbl[p->w] = c++;
                parent[p->w] = v;
                QUEUEPut(p->w);
            }
    }
    printf("\n____");
    for(w = 0; w <= G->V; w++)
        printf("_____");
    QUEUEFree();
    printf("\n\n");
    adj_DIGRAPHShow1(G);
}

void adj_DIGRAPHdist(adj_Digraph G, Vertex s)
{
    Vertex v;
    link p;
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
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(dist[p->w] == G->V){
                dist[p->w] = dist[v] + 1;
                parent[p->w] = v;
                QUEUEPut(p->w);
            }
    }
    QUEUEFree();
    printf("\n");
    adj_DIGRAPHShow1(G);
    adj_DIGRAPHShow2(G);
}

void adj_DIGRAPHShow1(adj_Digraph G)
{
    Vertex w;
    printf("______");
    for(w = 0; w <= G->V; w++)
        printf("_____");
    printf("\n\n    i ");
    for(w = 0; w < G->V; w++)
        printf("|  %d  ",w);
    printf("\n------+-----");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\nPARENT");
    for(w = 0; w < G->V; w++)
        printf("| %d ",parent[w]);
    printf("\n______");
    for(w = 0; w <= G->V; w++)
        printf("_____");
    printf("\n\n");
}

void adj_DIGRAPHShow2(adj_Digraph G)
{
    Vertex w;
    printf("____");
    for(w = 0; w <= G->V; w++)
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
    for(w = 0; w <= G->V; w++)
        printf("_____");
    printf("\n\n");
}

adj_Digraph adj_DIGRAPHdel()
{
    adj_Digraph adj;
    adj->V = 0;
    adj->A = 0;
    return adj;
}
