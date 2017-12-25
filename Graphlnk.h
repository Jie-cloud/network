#pragma once
#include"Graph.h"
using namespace std;

struct Edge {    //路由器
	int dest;    //下一个顶点
	int cost;    //边的权值 
	Edge * link;  //下一条边
};

struct Vertex {
	string name;
	Edge * adj;   //头指针
};

struct RowColWeight
{
	int row = -1;							//行下标
	int col = -1;							//列下标
	int weight = 0;							//权值
};

struct node {
	string name;
};

class Graphlnk :public Graph {
public:
	Graphlnk(int sz);
	~Graphlnk() {};
	void getValue(int i,string& s) {
		if (i >= 0 && i < numVertices)
			s = Nodeintable[i].name;
	}
	int getWeight(int v1, int v2);					//取边（v1，v2）上的权值
	int getFirstNeighbor(int v);				//取顶点v的第个邻接顶点
	int getNextNeighbor(int v, int w);			//取邻接顶点w的下一个邻接顶点
	bool insertVertex(const string vertex);			//插入一个顶点vertex
	bool insertEdge(int v1, int v2, int cost);		//插入边(v1,v2),权为cost
	bool removeVertex(int v);					//删去顶点v和所有与v相关的边
	bool removeEdge(int v1, int v2);				//删去边(v1,v2)
	Vertex * Nodeintable;
};
Graphlnk::Graphlnk(int sz = MaxVeitices) {
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
	//	cerr << "存储分配错误！"<<endl;
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
}

bool Graphlnk::insertVertex(const string vertex)
{
	if (numVertices == maxVertices) return false;
	Nodeintable[numVertices].name = vertex;
	numVertices++;
	return true;
}

bool Graphlnk::removeVertex(int v)
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
	Nodeintable[v].name = Nodeintable[numVertices].name;
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
	
	return true;
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
}

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
			q = NULL;
			s = p;
		}
		if (p == s)
			Nodeintable[v2].adj = p->link;
		else
		{
			q->link = p->link;
		}
		delete p;
		return true;
	}
	return false;
}

ostream& operator << (ostream& out, Graphlnk & G)
{
	int i, j;
	cout << "    路由器个数为:" << G.NumberOfVertices() << endl;
	cout << "    路由器边个数为:" << G.NunberOfEdges() << endl;
	cout << "    路由器编号" << endl;
	for (i = 0; i < G.NumberOfVertices(); i++) {
		cout << "    "; string s;
		G.getValue(i, s);
		cout << setw(10) << s << endl;
	}
	cout << "\n";
	cout << "    距离集合为:\n";
	for (i = 0; i < G.NumberOfVertices(); i++)
	{
		cout << "   ";
		for (j = 0; j < G.NumberOfVertices(); j++)
		{
			if (G.getWeight(i, j) == maxWeight)
				cout << setw(10) << "Max";
			else
				cout << setw(10) << G.getWeight(i, j);
		}
		cout << "\n";
	}
	cout << endl;
	return out;
}

void CreatGraph(Graphlnk &G, node N[], int n, RowColWeight E[], int e)
{	//在图G中插入n个顶点V和e条边E

	//在图G中插入n个顶点
	for (int i = 0; i < n; i++) {		
		G.insertVertex(N[i].name);
	}

	//在图G中插入e条边
	for (int k = 0; k < e; k++) {
		G.insertEdge(E[k].row, E[k].col, E[k].weight);
	}
}


