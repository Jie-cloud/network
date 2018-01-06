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

void rttable(Graphlnk G, int v, int dist[], int path[])
{
	system("cls");
	int i,j,k,n;
	cout << "******************************路由器" << G.getValue(v) << "的路由表****************************" << endl<<endl;
	cout << setw(15) << "目的路由" << setw(15) << "下一跳" << setw(15)<<"最短路径长度"<<endl;
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
int * Path(Graphlnk G, int v1)//使用广度优先搜索求解一个顶点到其他各顶点的路径（路径长度最小）。
{
	//在这里添加你的代码，完成作业要求，替换下面程序
	int n = G.NumberOfVertices();                //n是图中点的个数
	int *path = new int[n];                      //初始化路径数组
	int *dist = new int[n];                      //初始化距离数组
	for (int i = 0; i < n; i++) {
		path[i] = -1; dist[i] = maxSize;         //将路径赋值为-1，距离赋值为maxSize
		if (i == v1) {
			path[i] = i;  dist[i] = 0;           //路径的起点中的上一个点赋值为自己，距离赋值为0
		}
	}
	queue<int> q;
	q.push(v1);                               //将起点入队
	while (q.size() != 0) {                   //判断是否结束循环
		int cur;                                               //cur为本次出队的点
		cur = q.front();
		q.pop();
		int cur1 = G.getFirstNeighbor(cur);                    //cur1赋值为cur的第一个邻居
		if (cur1 != -1) {
			int weight = G.getWeight(cur, cur1);               //计算cur到cur1的距离
			if (dist[cur] + weight < dist[cur1]) {             //如果起点到cur的距离+cur到cur1的距离小于起点到cur1的距离（两条路径不同）
				dist[cur1] = dist[cur] + weight;               //将起点到cur1的距离赋值为小值
				path[cur1] = cur;                              //并改变cur1的上一个点为cur
				q.push(cur1);                                 //让cur1入队
			}
			cur1 = G.getNextNeighbor(cur, cur1);                //cur1赋值为cur的下一个邻居，后与前面算法一致
			while (cur1 != -1) {                               //知道cur没有邻居，结束本次循环
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
	rttable(G, v1, dist, path);          //调用输出函数输出路径
	return NULL;
}