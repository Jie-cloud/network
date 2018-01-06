#pragma once
#include"Graphlnk.h"
int * Path(Graphlnk &G, int v1);//使用广度优先搜索求解一个顶点到其他各顶点的路径（路径长度最小）。
void printPath(Graphlnk& G, int v, int dist[], int path[]);