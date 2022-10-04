#include<iostream>
#include<vector>
#include"Union_find.h"
#include"Union_find2.h"
using namespace std;
int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//改进基于树的并查集
	//加了一个size数组，在每次union的时候都是size小的加到大的里面去
	Union_find uf(v);
	if (uf.is_connected(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	uf.Tunion(3, 5);
	if (uf.is_connected(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	uf.Tunion(2, 3);
	if (uf.is_connected(2, 5))
		cout << "2跟5有关联" << endl;
	else
		cout << "2跟5没有关联" << endl;

	//改进基于树的并查集
	//rank存储的是该节点的往下的深度，将深度浅的加到深度深的里面去
	Union_find2 uf1(v);
	if (uf1.is_connected2(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	uf1.Tunion2(3, 5);
	if (uf1.is_connected2(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	uf1.Tunion2(2, 3);
	if (uf1.is_connected2(2, 5))
		cout << "2跟5有关联" << endl;
	else
		cout << "2跟5没有关联" << endl;
	return 0;
}