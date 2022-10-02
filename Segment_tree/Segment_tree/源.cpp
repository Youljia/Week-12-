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
	//查询某个元素
	T get(int index) {
		return this->arr[index];
	}
	//查询数组长度
	int get_size() {
		return arr.size();
	}
	//线段树的查询 --》 查询某个区间的元素和
	T query(int query_l, int query_r) {
		return query(0, 0, arr.size() - 1, query_l, query_r);
	}
	//线段树的更新和数组的更新
	void set(int target, T e) {
		arr[target] = e;
		set(0, 0, arr.size() - 1, target, e);
	}
private:
	//根据数组元素创建线段树
	// 宏观寓意 --》 创建index位置的信息
	//递归实现 --》 父亲节点的信息是两个孩子节点信息的总和
	void Build_segment_tree(int index, int l, int r) {
		//递归结束的条件 --》 当区间中只有一个元素的时候
		if (l == r) {
			tree[index] = arr[l];
			return;
		}
		int left = left_child(index);
		int right = right_child(index);
		int mid = l + (r - l) / 2;
		Build_segment_tree(left, l, mid);
		Build_segment_tree(right, mid + 1, r);
		//合并两个子孩子，得到父亲节点的信息
		tree[index] = merge(tree[left], tree[right]);
	}
	//合并两个孩子的信息
	//限制为加法 --> 该线段树存储的是一个区间的元素和
	T merge(T a, T b) {
		return a + b;
	}
	//求左孩子的下标
	int left_child(int index) {
		return index * 2 + 1;
	}
	//求右孩子的下标
	int right_child(int index) {
		return index * 2 + 2;
	}
	//递归调用 --> 线段树的查询
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
	//递归调用 --》线段树的更新
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
	//拷贝的数组
	vector<T> arr;
	//线段树
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