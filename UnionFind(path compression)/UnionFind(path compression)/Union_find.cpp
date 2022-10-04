#include "Union_find.h"
Union_find::Union_find(vector<int>& v) {
	this->parent = new int[v.size()];
	this->rank = new int[v.size()];
	for (int i = 0; i < v.size(); ++i) {
		parent[i] = i;
		rank[i] = 1;
	}
}
Union_find::~Union_find() {
	if (this->parent != nullptr)
		delete[] this->parent;
	if (this->rank != nullptr)
		delete[] this->rank;
	parent = rank = nullptr;
}
bool Union_find::is_connected(int p, int q) {
	if (find_root(p) == find_root(q))return true;
	else return false;
}
//连接两个节点，并维护一下rank
void Union_find::Tunion(int p, int q) {
	int p_root = find_root(p);
	int q_root = find_root(q);
	if (p_root == q_root)return;
	if (rank[p_root] > rank[q_root])
		parent[q_root] = p_root;
	else if (rank[p_root] < rank[q_root])
		parent[p_root] = q_root;
	else {
		parent[p_root] = q_root;
		rank[q_root] += 1;
	}
}
//一边查找一边进行路径压缩
//让该节点的父亲等于节点父亲的父亲
int Union_find::find_root(int t) {
	while (t != parent[t]) {
		parent[t] = parent[parent[t]];
		t = parent[t];
	}
	return t;
}
