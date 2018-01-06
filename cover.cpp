#include"Graphlnk.h"
#include"cover.h"
int cover(Graphlnk & G)
{
	cout << "****************************************     ��������    **************************************" << endl << endl;
	cout << "******************************** �������� ********************************" << endl;
	int i, j;
	cout << "·�����ĸ���Ϊ��" << setw(3) << G.NumberOfVertices() << endl;
	cout << "·�����߸���Ϊ��" << setw(3) << G.NunberOfEdges() << endl;
	cout << "·����֮����������:   " << endl;
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
	cout << "1.�鿴·������·�ɱ�" << endl;
	cout << "2.ɾ��һ��·����" << endl;
	cout << "3.ɾ��һ����" << endl;
	cout << "4.�뿪" << endl;
	cout << "**********************************" << endl;
	int record; int v,v1,v2;
	cout << "���������ѡ��";
	cin >> record;
	switch (record)
	{
	case 1: cout << "��������Ҫ��ѯ�ĸ�·������·�ɱ�" << endl;
		cin >> v;
		v = merge(v, G);
		Path(G,  v);
		break;
	case 2: cout << "������Ҫɾ��·�����ı��" << endl;
		cin >> v; v = merge(v, G);
		G.removeVertex(v); break;
	case 3: cout << "��������Ҫɾ���ı����ߵ�·�������" << endl;
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

	//��ͼG�в���e����
	for (int k = 0; k < cur2; k++) {
		g.insertEdge(r[k].row, r[k].col, r[k].weight);
	}
}

