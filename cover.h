#pragma once
#include"Graphlnk.h"
int cover(Graphlnk & G);
int merge(int t1, Graphlnk g);
void init(Graphlnk & g);
void rttable(Graphlnk G, int v, int dist[], int path[]);
int * Path(Graphlnk G, int v1);//ʹ�ù�������������һ�����㵽�����������·����·��������С����