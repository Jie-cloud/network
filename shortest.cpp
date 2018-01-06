#include"Graphlnk.h"
void printPath(Graphlnk& G, int v, int dist[], int path[])
{//输出path数组中存储的图G从顶点v到其余各顶点的路径和距离
	cout << "从顶点" << G.getValue(v) << "到其他各顶点的最短路径为：" << endl;
	int i, j, k, n = G.NumberOfVertices();
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
			cout << "顶点" << G.getValue(i) << "的最短路径为：" << G.getValue(v) << " ";
			while (k>0)
			{
				cout << G.getValue(d[--k]) << " ";
			}
			cout << "最短路径长度为：" << dist[i] << endl;
		}
	}
	delete[] d;
}
int * Path(Graphlnk &G, int v1)//使用广度优先搜索求解一个顶点到其他各顶点的路径（路径长度最小）。
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
	printPath(G, v1, dist, path);          //调用输出函数输出路径
	return NULL;
}