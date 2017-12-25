#include"Graphlnk.h"
#include<queue>
void main() {
	node *n = new node[10];
	ifstream in("route.txt");
	string nonvalue;
	in >> nonvalue >> nonvalue >> nonvalue;
	queue<RowColWeight> q;
	int  i = 0, cur2 = 0;
	while (!in.eof()) {
		cur2++;
		RowColWeight r;
		in >> r.col >> r.weight >> r.row;
		n[r.col - 1].name = r.col--;
		n[r.row - 1].name = r.row--;
		if (r.row > i)i = r.row;
		q.push(r);
	}
	RowColWeight *r = new RowColWeight[cur2];
	int j = 0;
	while (q.size() != 0) {
		r[j].col = q.front().col;
		r[j].row = q.front().row;
		r[j++].weight = q.front().weight;
		q.pop();
	}
	Graphlnk g;
	CreatGraph(g, n, i+1, r, cur2);
	cout << g;
	cout << "1.É¾³ý" << endl;
	int t;
	cin >> t;
	g.removeVertex(t);
	cout << g;
}