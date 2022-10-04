#include<iostream>
#include<vector>
#include"Quick_find.h"
#include"Quick_union.h"
using namespace std;
int main() {
	vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 };
	//基于普通数组的并查集
	//查找是否有关联的复杂度为O(1)，但是将两个数连接起来的复杂度为O(n)
	Quick_find q1(v1);
	if (q1.is_connected(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	q1.Tunion(3, 5);
	if (q1.is_connected(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	q1.Tunion(2, 3);
	if (q1.is_connected(2, 5))
		cout << "2跟5有关联" << endl;
	else
		cout << "2跟5没有关联" << endl;

	Quick_union q2(v1);
	if (q2.is_connected2(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	q2.Tunion2(3, 5);
	if (q2.is_connected2(3, 5))
		cout << "3跟5有关联" << endl;
	else
		cout << "3跟5没有关联" << endl;
	q2.Tunion2(2, 3);
	if (q2.is_connected2(2, 5))
		cout << "2跟5有关联" << endl;
	else
		cout << "2跟5没有关联" << endl;
	return 0;
}