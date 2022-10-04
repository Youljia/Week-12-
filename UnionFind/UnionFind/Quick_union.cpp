#include "Quick_union.h"
Quick_union::Quick_union(vector<int>& v1) {
	this->parent = new int[v1.size()];
	for (int i = 0; i < v1.size(); ++i)
		this->parent[i] = i;
}
Quick_union::~Quick_union() {
	if (this->parent != nullptr)
		delete[] this->parent;
	this->parent = nullptr;
}
//������Ԫ����������
//ʵ�� --�� ������Ԫ�صĸ��ڵ���������
void Quick_union::Tunion2(int p, int q) {
	int p_root = find_root(p);
	int q_root = find_root(q);
	if (p_root == q_root)return;
	else
		parent[p_root] = q_root;
}
//�ж�����Ԫ���Ƿ�����ϵ
bool Quick_union::is_connected2(int p, int q) {
	return find_root(p) == find_root(q);
}
//����Ԫ��t�ĸ��ڵ�
int Quick_union::find_root(int t) {
	while (t != parent[t])
		t = parent[t];
	return t;
}
