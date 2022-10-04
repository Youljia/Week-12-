#include "Union_find2.h"
Union_find2::Union_find2(vector<int>& v) {
	this->parent = new int[v.size()];
	this->rank = new int[v.size()];
	for (int i = 0; i < v.size(); ++i) {
		parent[i] = i;
		rank[i] = 1;
	}
}
Union_find2::~Union_find2() {
	if (this->parent != nullptr)
		delete[] this->parent;
	if (this->rank != nullptr)
		delete[] this->rank;
	parent = rank = nullptr;
}
bool Union_find2::is_connected2(int p, int q) {
	if (find_root2(p) == find_root2(q))return true;
	else return false;
}
//连接两个节点，并维护一下rank
void Union_find2::Tunion2(int p, int q) {
	int p_root = find_root2(p);
	int q_root = find_root2(q);
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
int Union_find2::find_root2(int t) {
	while (t != parent[t])
		t = parent[t];
	return t;
}