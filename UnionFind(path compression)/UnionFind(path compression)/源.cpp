#include<iostream>
#include<vector>
#include"Union_find.h"
#include"Union_find2.h"
using namespace std;
int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//��ӵ��rank�Ļ����ϸĽ����鼯
	//��ÿ��find�Ĺ����ж��øýڵ�ĸ��׽ڵ���ڸýڵ㸸�׵ĸ��׽ڵ�
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

	//��ӵ��rank�Ļ����Ͻ���·��ѹ���Ľ����鼯
	//��ÿ�β���ʱ�����õݹ飬ʹĿ��ڵ�����и��׽ڵ㶼ֱ��ָ��Ŀ��ڵ�ĸ��ڵ�
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