#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
const int maxWeight = 1000;
const int MaxVeitices = 10;			//代表最大顶点数 =n

class Graph
{
	//friend istream& operator >> (istream& in, Graphlnk & G);
public:
	Graph(int sz = MaxVeitices) {};
	~Graph() {}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		//返回当前顶点数
	int NunberOfEdges() { return numEdges; }			//返回当前边数
	virtual int getWeight(int v1, int v2) = 0;					//取边（v1，v2）上的权值
	virtual int getFirstNeighbor(int v) = 0;				//取顶点v的第个邻接顶点
	virtual int getNextNeighbor(int v, int w) = 0;			//取邻接顶点w的下一个邻接顶点
	virtual bool insertVertex(const int vertex) = 0;			//插入一个顶点vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;		//插入边(v1,v2),权为cost
	virtual bool removeVertex(int v) = 0;					//删去顶点v和所有与v相关的边
	virtual bool removeEdge(int v1, int v2) = 0;				//删去边(v1,v2)
	int maxVertices;
	int numEdges;
	int numVertices;
};
