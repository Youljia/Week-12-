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
//将两个元素连接起来
//实质 --》 将两个元素的根节点连接起来
void Quick_union::Tunion2(int p, int q) {
	int p_root = find_root(p);
	int q_root = find_root(q);
	if (p_root == q_root)return;
	else
		parent[p_root] = q_root;
}
//判断两个元素是否有联系
bool Quick_union::is_connected2(int p, int q) {
	return find_root(p) == find_root(q);
}
//查找元素t的根节点
int Quick_union::find_root(int t) {
	while (t != parent[t])
		t = parent[t];
	return t;
}
