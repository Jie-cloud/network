#pragma once
#include"Graphlnk.h"
int cover(Graphlnk & G);
int merge(int t1, Graphlnk g);
void init(Graphlnk & g);
void rttable(Graphlnk G, int v, int dist[], int path[]);
int * Path(Graphlnk G, int v1);//使用广度优先搜索求解一个顶点到其他各顶点的路径（路径长度最小）。