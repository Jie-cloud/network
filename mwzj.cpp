#include"Graphlnk.h"
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

ostream& operator << (ostream& out, Graphlnk & G)
{
	int i, j;
	cout << "    路由器个数为:" << G.NumberOfVertices() << endl;
	cout << "    路由器边个数为:" << G.NunberOfEdges() << endl;
	cout << "    路由器编号" << endl;
	for (i = 0; i < G.NumberOfVertices(); i++) {
		cout << "    "; string s;
		cout << setw(10) << G.getValue(i) << endl;
	}
	cout << "\n";
	cout << "路由器编号:   ";
	for (i = 0; i < G.NumberOfVertices(); i++) {
		cout << left << setw(10) << G.getValue(i);
	}cout << endl;
	for (i = 0; i < G.NumberOfVertices(); i++)
	{
		cout << "     " << G.getValue(i);
		for (j = 0; j < G.NumberOfVertices(); j++)
		{
			if (G.getWeight(i, j) == maxWeight)
				cout << right << setw(10) << "Max";
			else
				cout << setw(10) << G.getWeight(i, j);
		}
		cout << "\n";
	}
	cout << endl;
	return out;
}

