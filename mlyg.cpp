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

void Graphlnk::shortest(int v) {
	cout << "请输入路由表编号:";
	int name1, name2;
	cin >> name1 >> name2;
	Dist d[30];
	int a[30][30] = { 0 };
	int i; int from; int to;
	for (i = 0; Nodeintable[i].num != name2; i++); to = i;
	for (i = 0; Nodeintable[i].num != name1; i++); from = i;
	//cout << "hello1" << endl;
	while (d[to].con != 1) {
		int j = getFirstNeighbor(i);
		while (j != -1) {
			if (a[i][j] != 0)break;
			else {
				a[i][j] = 1;
				a[j][i] = 1;
			}
			int w = getWeight(i, j);
			d[j].dest = i;
			if (i == from)
				d[j].weight = w;
			else {
				int k = i;
				while (k != from) {
					w += d[k].weight;
					k = d[k].dest;
				}
				if (d[j].weight > w || d[j].weight == 0) {
					d[j].weight = w;
					d[j].dest = i;
				}
			}
			break;
		}
		j = getNextNeighbor(i, j);
		while (j != -1) {
			if (a[i][j] != 0) {
				j = getNextNeighbor(i, j);
				continue;
			}
			else {
				a[i][j] = 1;
				a[j][i] = 1;
			}
			int w = getWeight(i, j);
			d[j].dest = i;
			if (i == from)
				d[j].weight = w;
			else {
				int k = i;
				while (k != from) {
					w += d[k].weight;
					k = d[k].dest;
				}
				if (d[j].weight > w || d[j].weight == 0) {
					d[j].weight = w;
					d[j].dest = i;
				}
			}
			j = getNextNeighbor(i, j);
		}
		int min = 100;
		for (int m = 0; m < 30; m++) {
			if (d[m].weight < min&&d[m].weight>0 && d[m].con != 1) {
				min = d[m].weight; i = m;
			}
		}
		d[i].con = 1;
	}
	stack<int> s;
	while (to != from) {
		s.push(to);
		to = d[to].dest;
	}s.push(from);
	cout << "             ";
	while (s.size() != 1) {
		cout << Nodeintable[s.top()].num << " --> ";
		s.pop();
	}
	cout << Nodeintable[s.top()].num << endl;
	cout << "             " << left << "-----------------------------------------------------------------" << endl;
}