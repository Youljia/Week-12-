#include<iostream>
#include<vector>
#include"Quick_find.h"
#include"Quick_union.h"
using namespace std;
int main() {
	vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 };
	//������ͨ����Ĳ��鼯
	//�����Ƿ��й����ĸ��Ӷ�ΪO(1)�����ǽ����������������ĸ��Ӷ�ΪO(n)
	Quick_find q1(v1);
	if (q1.is_connected(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	q1.Tunion(3, 5);
	if (q1.is_connected(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	q1.Tunion(2, 3);
	if (q1.is_connected(2, 5))
		cout << "2��5�й���" << endl;
	else
		cout << "2��5û�й���" << endl;

	Quick_union q2(v1);
	if (q2.is_connected2(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	q2.Tunion2(3, 5);
	if (q2.is_connected2(3, 5))
		cout << "3��5�й���" << endl;
	else
		cout << "3��5û�й���" << endl;
	q2.Tunion2(2, 3);
	if (q2.is_connected2(2, 5))
		cout << "2��5�й���" << endl;
	else
		cout << "2��5û�й���" << endl;
	return 0;
}