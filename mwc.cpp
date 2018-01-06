#include"Graphlnk.h"

Graphlnk::Graphlnk() {
	int sz = MaxVeitices;
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	Nodeintable = NULL;

	try
	{
		Nodeintable = new Vertex[maxVertices];
	}
	catch (bad_alloc & memExp)
	{
		cerr << memExp.what() << endl;
	}
	//NodeTable = new  struct Vertex<T,E>[maxVertices];
	//if(NodeTable = NULL)
	//{
	//	cerr << "´æ´¢·ÖÅä´íÎó£¡"<<endl;
	//	exit(1);
	//}
	for (int i = 0; i<maxVertices; i++)
	{
		Nodeintable[i].adj = NULL;
		//	NodeTable[i].adj->cost = maxWeight;
	}
};



int Graphlnk::getFirstNeighbor(int v) {
	if (v != -1)
	{
		Edge * p = Nodeintable[v].adj;
		if (p != NULL) return p->dest;
	}
	return -1;
}


int Graphlnk::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge * p = Nodeintable[v].adj;
		while (p != NULL && p->dest != w)
		{
			p = p->link;
		}
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}


int merge(int t1, Graphlnk g)
{
	int j;
	for (j = 0; j < g.numVertices; j++) {
		if (g.Nodeintable[j].num == t1) {
			t1 = j;
			break;
		}
	}
		return t1;
}