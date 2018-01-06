#include"Graphlnk.h"
void printPath(Graphlnk& G, int v, int dist[], int path[])
{//���path�����д洢��ͼG�Ӷ���v������������·���;���
	cout << "�Ӷ���" << G.getValue(v) << "����������������·��Ϊ��" << endl;
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
			cout << "����" << G.getValue(i) << "�����·��Ϊ��" << G.getValue(v) << " ";
			while (k>0)
			{
				cout << G.getValue(d[--k]) << " ";
			}
			cout << "���·������Ϊ��" << dist[i] << endl;
		}
	}
	delete[] d;
}
int * Path(Graphlnk &G, int v1)//ʹ�ù�������������һ�����㵽�����������·����·��������С����
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
	printPath(G, v1, dist, path);          //��������������·��
	return NULL;
}