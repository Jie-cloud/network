#include"Graphlnk.h"
#include"cover.h"
int cover(Graphlnk & G)
{
	cout << "****************************************     网络中心    **************************************" << endl << endl;
	cout << "******************************** 网络拓扑 ********************************" << endl;
	int i, j;
	cout << "路由器的个数为：" << setw(3) << G.NumberOfVertices() << endl;
	cout << "路由器边个数为：" << setw(3) << G.NunberOfEdges() << endl;
	cout << "路由器之间的连接情况:   " << endl;
	cout << "               ";
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
	cout << "**************************************************************************" << endl;
	cout << "1.查看路由器的路由表" << endl;
	cout << "2.删除一个路由器" << endl;
	cout << "3.删除一条边" << endl;
	cout << "4.离开" << endl;
	cout << "**********************************" << endl;
	int record; int v,v1,v2;
	cout << "请输入你的选择：";
	cin >> record;
	switch (record)
	{
	case 1: cout << "请输入你要查询哪个路由器的路由表" << endl;
		cin >> v;
		v = merge(v, G);
		Path(G,  v);
		break;
	case 2: cout << "请输入要删除路由器的编号" << endl;
		cin >> v; v = merge(v, G);
		G.removeVertex(v); break;
	case 3: cout << "请输入你要删除的边两边的路由器编号" << endl;
		cin >> v1 >> v2; v1 = merge(v1, G);
		v2 = merge(v2, G);
		G.removeEdge(v1, v2);
		break;
	case 4: break;
	default:break;
	}
	if (record == 4)
		return -1;
	else return 1;
}


void init(Graphlnk &g)
{
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
	for (int l = 0; l < i; l++) {
		g.insertVertex(n[l].num);
	}

	//在图G中插入e条边
	for (int k = 0; k < cur2; k++) {
		g.insertEdge(r[k].row, r[k].col, r[k].weight);
	}
}

