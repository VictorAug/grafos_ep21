#ifndef GRAFOS_EP21Q_H_INCLUDED
#define GRAFOS_EP21Q_H_INCLUDED
#include "grafos_ep21adj.h"
#include "grafos_ep21m.h"
static int *q, i;

void QUEUEInit(int);

int QUEUEEmpty();

void QUEUEPut(Vertex);

Vertex QUEUEGet();

void QUEUEFree();

#endif // GRAFOS_EP21Q_H_INCLUDED
