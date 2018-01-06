
#include"cover.h"
#include<queue>
using namespace std;
void main() {
	Graphlnk g;
	init(g);
	while (cover(g) != -1)
	{
		system("cls");
	}
}
