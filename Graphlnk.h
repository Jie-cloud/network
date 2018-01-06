#pragma once
#include"Graph.h"
using namespace std;

struct Edge {    //·����
	int dest;    //��һ������
	int cost;    //�ߵ�Ȩֵ 
	Edge * link;  //��һ����
};

struct Vertex {
	int num;   //yesnodojflkdjf
	Edge * adj;   //ͷָ��
};

struct RowColWeight
{
	int row = -1;							//���±�
	int col = -1;							//���±�
	int weight = 0;							//Ȩֵ
};

struct node {
	int num;
};

class Graphlnk :public Graph {
public:
	Graphlnk(int sz);
	int getValue(int i);
	int getWeight(int v1, int v2);					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int getFirstNeighbor(int v);				//ȡ����v�ĵڸ��ڽӶ���
	int getNextNeighbor(int v, int w);			//ȡ�ڽӶ���w����һ���ڽӶ���
	bool insertVertex(const int vertex);			//����һ������vertex
	bool insertEdge(int v1, int v2, int cost);		//�����(v1,v2),ȨΪcost
	bool removeVertex(int v);					//ɾȥ����v��������v��صı�
	bool removeEdge(int v1, int v2);				//ɾȥ��(v1,v2)
	Vertex * Nodeintable;
};
/*Graphlnk::Graphlnk(int sz = MaxVeitices) {
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
	//	cerr << "�洢�������"<<endl;
	//	exit(1);
	//}
	for (int i = 0; i<maxVertices; i++)
	{
		Nodeintable[i].adj = NULL;
		//	NodeTable[i].adj->cost = maxWeight;
	}
};*/
/*int Graphlnk::getFirstNeighbor(int v) {
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
}*/

/*int Graphlnk::getWeight(int v1, int v2)
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
}

bool Graphlnk::insertVertex(const int vertex)
{
	if (numVertices == maxVertices) return false;
	Nodeintable[numVertices].num = vertex;
	numVertices++;
	return true;
}*/

/*bool Graphlnk::removeVertex(int v)
{
	if (numVertices == 1 || v<0 || v >= numVertices)return false;
	Edge *p, *s, *t;
	int k;
	while (Nodeintable[v].adj != NULL)
	{
		p = Nodeintable[v].adj;
		k = p->dest;
		s = Nodeintable[k].adj;
		t = NULL;
		while (s != NULL && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL) Nodeintable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		Nodeintable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	Nodeintable[v].num = Nodeintable[numVertices].num;
	p = Nodeintable[v].adj = Nodeintable[numVertices].adj;
	while (p != NULL)
	{
		s = Nodeintable[p->dest].adj;
		while (s != NULL) {
			if (s->dest == numVertices) { s->dest = v; break; }
			else s = s->link;
		}
		p = p->link;
	}
	/*for (int k = 0; k < numVertices - 1; k++) {
	Edge * cur1 = Nodeintable[k].adj;
	if (getValue(k) > getValue(k + 1)) {
	Edge * cur2 = Nodeintable[k+1].adj;
	Edge * cur3 = cur1;
	cur1 = cur2;
	cur2 = cur3;
	int cur = Nodeintable[k].num;
	Nodeintable[k].num = Nodeintable[k + 1].num;
	Nodeintable[k + 1].num = cur;
	}
	}*/

	/*return true;
}


bool Graphlnk::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 0 && v1< numVertices && v2 >= 0 && v2<numVertices)
	{
		Edge *q, *p = Nodeintable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL) return false;
		p = new Edge;
		q = new Edge;
		p->dest = v2;
		p->cost = cost;
		p->link = Nodeintable[v1].adj;
		Nodeintable[v1].adj = p;
		q->dest = v1;
		q->cost = cost;
		q->link = Nodeintable[v2].adj;
		Nodeintable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;
}*/

/*bool Graphlnk::removeEdge(int v1, int v2)
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
}*/

ostream& operator << (ostream& out, Graphlnk & G);

/*void CreatGraph(Graphlnk &G, node N[], int n, RowColWeight E[], int e)
{	//��ͼG�в���n������V��e����E

	//��ͼG�в���n������
	for (int i = 0; i < n; i++) {
		G.insertVertex(N[i].num);
	}

	//��ͼG�в���e����
	for (int k = 0; k < e; k++) {
		G.insertEdge(E[k].row, E[k].col, E[k].weight);
	}
}*/