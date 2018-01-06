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
	cout << "    ·��������Ϊ:" << G.NumberOfVertices() << endl;
	cout << "    ·�����߸���Ϊ:" << G.NunberOfEdges() << endl;
	cout << "    ·�������" << endl;
	for (i = 0; i < G.NumberOfVertices(); i++) {
		cout << "    "; string s;
		cout << setw(10) << G.getValue(i) << endl;
	}
	cout << "\n";
	cout << "·�������:   ";
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

void rttable(Graphlnk G, int v, int dist[], int path[])
{
	system("cls");
	int i,j,k,n;
	cout << "******************************·����" << G.getValue(v) << "��·�ɱ�****************************" << endl<<endl;
	cout << setw(15) << "Ŀ��·��" << setw(15) << "��һ��" << setw(15)<<"���·������"<<endl;
	n = G.NumberOfVertices();
	int * d = new int[n];
	for (i = 0; i<n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			cout <<setw(12) << G.getValue(i) << setw(15) << G.getValue(d[--k]) << setw(13)<<dist[i] << endl;
		}
	}
	cout << "************************************************************************************" << endl;
	system("pause");

	delete d;
}
int * Path(Graphlnk G, int v1)//ʹ�ù�������������һ�����㵽�����������·����·��������С����
{
	//�����������Ĵ��룬�����ҵҪ���滻�������
	int n = G.NumberOfVertices();                //n��ͼ�е�ĸ���
	int *path = new int[n];                      //��ʼ��·������
	int *dist = new int[n];                      //��ʼ����������
	for (int i = 0; i < n; i++) {
		path[i] = -1; dist[i] = maxSize;         //��·����ֵΪ-1�����븳ֵΪmaxSize
		if (i == v1) {
			path[i] = i;  dist[i] = 0;           //·��������е���һ���㸳ֵΪ�Լ������븳ֵΪ0
		}
	}
	queue<int> q;
	q.push(v1);                               //��������
	while (q.size() != 0) {                   //�ж��Ƿ����ѭ��
		int cur;                                               //curΪ���γ��ӵĵ�
		cur = q.front();
		q.pop();
		int cur1 = G.getFirstNeighbor(cur);                    //cur1��ֵΪcur�ĵ�һ���ھ�
		if (cur1 != -1) {
			int weight = G.getWeight(cur, cur1);               //����cur��cur1�ľ���
			if (dist[cur] + weight < dist[cur1]) {             //�����㵽cur�ľ���+cur��cur1�ľ���С����㵽cur1�ľ��루����·����ͬ��
				dist[cur1] = dist[cur] + weight;               //����㵽cur1�ľ��븳ֵΪСֵ
				path[cur1] = cur;                              //���ı�cur1����һ����Ϊcur
				q.push(cur1);                                 //��cur1���
			}
			cur1 = G.getNextNeighbor(cur, cur1);                //cur1��ֵΪcur����һ���ھӣ�����ǰ���㷨һ��
			while (cur1 != -1) {                               //֪��curû���ھӣ���������ѭ��
				weight = G.getWeight(cur1, cur);
				if (dist[cur] + weight < dist[cur1]) {
					dist[cur1] = dist[cur] + weight;
					path[cur1] = cur;
					q.push(cur1);
				}
				cur1 = G.getNextNeighbor(cur, cur1);
			}
		}
	}
	rttable(G, v1, dist, path);          //��������������·��
	return NULL;
}