#pragma once
#include"Graph.h"
#include<queue>
#include<stack>
using namespace std;
#define maxSize 1000
struct Dist {
	int dest;      //��һ��·����λ��
	int con = 0;   //��־λ
	int weight = 0;
};
struct Edge {    //·����
	int dest;    //��һ������
	int cost;    //�ߵ�Ȩֵ 
	Edge * link;  //��һ����
};
struct Vertex {
	int num;   //yesnodojflkdjf
	Edge * adj;   //ͷָ��
};
struct RowColWeight
{
	int row = -1;							//���±�
	int col = -1;							//���±�
	int weight = 0;							//Ȩֵ
};
struct node {
	int num;
};
class Graphlnk :public Graph {
public:
	Graphlnk();
	int getValue(int i);
	int getWeight(int v1, int v2);					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int getFirstNeighbor(int v);				//ȡ����v�ĵڸ��ڽӶ���
	int getNextNeighbor(int v, int w);			//ȡ�ڽӶ���w����һ���ڽӶ���
	bool insertVertex( int vertex);			//����һ������vertex
	bool insertEdge(int v1, int v2, int cost);		//�����(v1,v2),ȨΪcost
	bool removeVertex(int v);					//ɾȥ����v��������v��صı�
	bool removeEdge(int v1, int v2);				//ɾȥ��(v1,v2)
	void shortest(int v);                    //���v1·�ɱ�
	Vertex * Nodeintable;
};

ostream& operator << (ostream& out, Graphlnk & G);
