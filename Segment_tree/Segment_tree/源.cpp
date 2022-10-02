#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Segment_tree {
public:
	Segment_tree(vector<T>& v) {
		this->arr = v;
		tree = new T[4 * arr.size()];
		Build_segment_tree(0, 0, arr.size() - 1);
	}
	//��ѯĳ��Ԫ��
	T get(int index) {
		return this->arr[index];
	}
	//��ѯ���鳤��
	int get_size() {
		return arr.size();
	}
	//�߶����Ĳ�ѯ --�� ��ѯĳ�������Ԫ�غ�
	T query(int query_l, int query_r) {
		return query(0, 0, arr.size() - 1, query_l, query_r);
	}
	//�߶����ĸ��º�����ĸ���
	void set(int target, T e) {
		arr[target] = e;
		set(0, 0, arr.size() - 1, target, e);
	}
private:
	//��������Ԫ�ش����߶���
	// ���Ԣ�� --�� ����indexλ�õ���Ϣ
	//�ݹ�ʵ�� --�� ���׽ڵ����Ϣ���������ӽڵ���Ϣ���ܺ�
	void Build_segment_tree(int index, int l, int r) {
		//�ݹ���������� --�� ��������ֻ��һ��Ԫ�ص�ʱ��
		if (l == r) {
			tree[index] = arr[l];
			return;
		}
		int left = left_child(index);
		int right = right_child(index);
		int mid = l + (r - l) / 2;
		Build_segment_tree(left, l, mid);
		Build_segment_tree(right, mid + 1, r);
		//�ϲ������Ӻ��ӣ��õ����׽ڵ����Ϣ
		tree[index] = merge(tree[left], tree[right]);
	}
	//�ϲ��������ӵ���Ϣ
	//����Ϊ�ӷ� --> ���߶����洢����һ�������Ԫ�غ�
	T merge(T a, T b) {
		return a + b;
	}
	//�����ӵ��±�
	int left_child(int index) {
		return index * 2 + 1;
	}
	//���Һ��ӵ��±�
	int right_child(int index) {
		return index * 2 + 2;
	}
	//�ݹ���� --> �߶����Ĳ�ѯ
	T query(int index, int l, int r, int query_l, int query_r) {
		if (query_l == l && query_r == r)return tree[index];
		int mid = l + (r - l) / 2;
		int left = left_child(index);
		int right = right_child(index);
		if (query_l >= mid + 1)return query(right, mid + 1, r, query_l, query_r);
		else if (query_r <= mid)return query(left, l, mid, query_l, query_r);
		else {
			int left_result = query(left, l, mid, query_l, mid);
			int right_result = query(right, mid + 1, r, mid + 1, query_r);
			return merge(left_result, right_result);
		}
	}
	//�ݹ���� --���߶����ĸ���
	void set(int index, int l, int r, int target, T e) {
		if (l == r) {
			tree[index] = e;
			return;
		}
		int left = left_child(index);
		int right = right_child(index);
		int mid = l + (r - l) / 2;
		if (target >= mid + 1)set(right, mid + 1, r, target, e);
		else set(left, l, mid, target, e);
		tree[index] = merge(tree[left], tree[right]);
	}
private:
	//����������
	vector<T> arr;
	//�߶���
	T* tree;
};

int main() {
	vector<int> v1{ 1,2,3,4,5,6,7,8 };
	Segment_tree<int> s(v1);
	cout << s.query(0, 2) << endl;
	cout << s.query(6, 7) << endl;
	s.set(7, 9);
	cout << s.query(6, 7) << endl;
	return 0;
}