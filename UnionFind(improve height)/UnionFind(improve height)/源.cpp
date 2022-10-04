#include<iostream>
#include<vector>
#include"Union_find.h"
#include"Union_find2.h"
using namespace std;
int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//�Ľ��������Ĳ��鼯
	//����һ��size���飬��ÿ��union��ʱ����sizeС�ļӵ��������ȥ
	Union_find uf(v);
	if (uf.is_connected(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	uf.Tunion(3, 5);
	if (uf.is_connected(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	uf.Tunion(2, 3);
	if (uf.is_connected(2, 5))
		cout << "2��5�й���" << endl;
	else
		cout << "2��5û�й���" << endl;

	//�Ľ��������Ĳ��鼯
	//rank�洢���Ǹýڵ�����µ���ȣ������ǳ�ļӵ�����������ȥ
	Union_find2 uf1(v);
	if (uf1.is_connected2(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	uf1.Tunion2(3, 5);
	if (uf1.is_connected2(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	uf1.Tunion2(2, 3);
	if (uf1.is_connected2(2, 5))
		cout << "2��5�й���" << endl;
	else
		cout << "2��5û�й���" << endl;
	return 0;
}