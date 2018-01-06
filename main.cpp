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
		if (i == 0) {
			n[0].num = r.col;
			n[1].num = r.row; i = 1;
			r.col = 0; r.row = 1;
			q.push(r);
			continue;
		}
		int j = 0;
		for (j = 0; j<i; j++) {
			if (r.col == n[j].num)break;
		}
		if (j == i) {
			n[++i].num = r.col;
		}
		else {
			r.col = j;
		}
		for (j = 0; j<i; j++) {
			if (r.row == n[j].num)break;
		}
		if (j == i) {
			n[++i].num = r.row;
		}
		else {
			r.row = j;
		}
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
	CreatGraph(g, n, i, r, cur2);
	cout << g;
	cout << "1.É¾³ýÂ·ÓÉÆ÷±ßµÄ±àºÅ" << endl;
	int t1,t2;
	cin >> t1 >> t2;
	for (j = 0; j < i; j++) {
		if (n[j].num == t1) {
			t1 = j;
			break;
		}
	}
	for (j = 0; j < i; j++) {
		if (n[j].num == t2) {
			t2 = j;
			break;
		}
	}
	g.removeEdge(t1,t2);
	cout << g;
}