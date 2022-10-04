#include<iostream>
#include<vector>
#include"Union_find.h"
#include"Union_find2.h"
using namespace std;
int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//在拥有rank的基础上改进并查集
	//在每次find的过程中都让该节点的父亲节点等于该节点父亲的父亲节点
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

	//在拥有rank的基础上进行路径压缩改进并查集
	//在每次查找时，利用递归，使目标节点的所有父亲节点都直接指向目标节点的根节点
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