#include "Quick_find.h"
Quick_find::Quick_find(vector<int>& v) {
	this->id = new int[v.size()];
	for (int i = 0; i < v.size(); ++i)
		id[i] = i;
	this->size = v.size();
}
//将两个元素联合起来
void Quick_find::Tunion(int p, int q) {
	if (find(p) == find(q))return;
	else {
		//将所有id为id[p]的元素都变成跟q有关联
		for (int i = 0; i < this->size; ++i) {
			if (find(i) == find(p))
				id[i] = id[q];
		}
	}
}
//判断两个下标是否有联系
bool Quick_find::is_connected(int p, int q) {
	if (find(p) == find(q))
		return true;
	else
		return false;
}
//查找下标为t的元素属于的集合代号
int Quick_find::find(int t) {
	return id[t];
}
