#include "Union_find.h"
Union_find::Union_find(vector<int>& v) {
	this->parent = new int[v.size()];
	this->size = new int[v.size()];
	for (int i = 0; i < v.size(); ++i) {
		parent[i] = i;
		size[i] = 1;
	}
}
Union_find::~Union_find() {
	if (this->parent != nullptr)
		delete[] this->parent;
	if (this->size != nullptr)
		delete[] this->size;
	parent = size = nullptr;
}
//�ж������ڵ��Ƿ�����ϵ
bool Union_find::is_connected(int p, int q) {
	if (find_root(p) == find_root(q))return true;
	else return false;
}
//�������ڵ�������һ��
//�ӽڵ�����ٵļӵ������ȥ
void Union_find::Tunion(int p, int q) {
	int p_root = find_root(p);
	int q_root = find_root(q);
	if (p_root == q_root)return;
	if (size[p_root] > size[q_root]) {
		parent[q_root] = p_root;
		size[p_root] += size[q_root];
	}
	else {
		parent[p_root] = q_root;
		size[q_root] += size[p_root];
	}
}
//����Ŀ��ڵ�ĸ��ڵ�
int Union_find::find_root(int t) {
	while (t != parent[t])
		t = parent[t];
	return t;
}
