#include "Graphlnk.h"
bool Graphlnk::removeEdge(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge *p = Nodeintable[v1].adj, *q = NULL, *s = p;
		while (p != NULL && p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (p == s)
				Nodeintable[v1].adj = p->link;
			else
			{
				q->link = p->link;
			}
			delete p;
		}
		else
		{
			return false;
		}
		p = Nodeintable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			Nodeintable[v2].adj = p->link;
		else
		{
			q->link = p->link;
		}
		delete p;
		numEdges--;
		return true;
	}
	return false;
}

int Graphlnk::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge *p = Nodeintable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL) {
			//cout << "(" << p->con << ")";
			return p->cost;
		}
		else return maxWeight;
	}
	else return maxWeight;
}

bool Graphlnk::insertVertex( int vertex)
{
	if (numVertices == maxVertices) return false;
	Nodeintable[numVertices].num = vertex;
	numVertices++;
	return true;
}

void CreatGraph(Graphlnk &G, node N[], int n, RowColWeight E[], int e)
{	//在图G中插入n个顶点V和e条边E

	//在图G中插入n个顶点
	for (int i = 0; i < n; i++) {
		G.insertVertex(N[i].num);
	}

	//在图G中插入e条边
	for (int k = 0; k < e; k++) {
		G.insertEdge(E[k].row, E[k].col, E[k].weight);
	}
}

int Graphlnk::getValue(int i) {
	if (i >= 0 && i < numVertices)
		return Nodeintable[i].num;
	else return -1;
}
