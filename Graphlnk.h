#pragma once
#include"Graph.h"
#include<queue>
#include<stack>
using namespace std;
#define maxSize 1000
struct Dist {
	int dest;      //上一个路由器位置
	int con = 0;   //标志位
	int weight = 0;
};
struct Edge {    //路由器
	int dest;    //下一个顶点
	int cost;    //边的权值 
	Edge * link;  //下一条边
};
struct Vertex {
	int num;   //yesnodojflkdjf
	Edge * adj;   //头指针
};
struct RowColWeight
{
	int row = -1;							//行下标
	int col = -1;							//列下标
	int weight = 0;							//权值
};
struct node {
	int num;
};
class Graphlnk :public Graph {
public:
	Graphlnk();
	int getValue(int i);
	int getWeight(int v1, int v2);					//取边（v1，v2）上的权值
	int getFirstNeighbor(int v);				//取顶点v的第个邻接顶点
	int getNextNeighbor(int v, int w);			//取邻接顶点w的下一个邻接顶点
	bool insertVertex( int vertex);			//插入一个顶点vertex
	bool insertEdge(int v1, int v2, int cost);		//插入边(v1,v2),权为cost
	bool removeVertex(int v);					//删去顶点v和所有与v相关的边
	bool removeEdge(int v1, int v2);				//删去边(v1,v2)
	void shortest(int v);                    //输出v1路由表
	Vertex * Nodeintable;
};

ostream& operator << (ostream& out, Graphlnk & G);
