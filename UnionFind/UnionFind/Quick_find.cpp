#include "Quick_find.h"
Quick_find::Quick_find(vector<int>& v) {
	this->id = new int[v.size()];
	for (int i = 0; i < v.size(); ++i)
		id[i] = i;
	this->size = v.size();
}
//������Ԫ����������
void Quick_find::Tunion(int p, int q) {
	if (find(p) == find(q))return;
	else {
		//������idΪid[p]��Ԫ�ض���ɸ�q�й���
		for (int i = 0; i < this->size; ++i) {
			if (find(i) == find(p))
				id[i] = id[q];
		}
	}
}
//�ж������±��Ƿ�����ϵ
bool Quick_find::is_connected(int p, int q) {
	if (find(p) == find(q))
		return true;
	else
		return false;
}
//�����±�Ϊt��Ԫ�����ڵļ��ϴ���
int Quick_find::find(int t) {
	return id[t];
}
