#include<iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void show(vector<int>& arr) {
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}

class Solution1
{
public:
	//冒泡排序
	void Bubble_sort1(vector<int>& arr) {
		for (int i = 0; i < arr.size() - 1; ++i) {
			for (int j = i+1; j <= arr.size() - i - 1; ++j) {
				if (arr[j] > arr[j - 1])
					swap(arr[j], arr[j - 1]);
			}
		}
	}

	//改进冒泡排序 --> 一旦有序了过后就直接退出 
	void Bubble_sort2(vector<int>& arr) {
		for (int i = 0; i < arr.size()-1; ++i) {
			int indicator = 0;
			for (int j = i+1; j <= arr.size() - i - 1; ++j) {
				if (arr[j] > arr[j - 1]) {
					swap(arr[j], arr[j - 1]);
					indicator = 1;
				}
			}
			if (indicator)
				break;
		}
	}

	//改进冒泡排序 --> 在最后一次交换后，后面的元素都是有序的 
	void Bubble_sort3(vector<int>& arr) {
		for (int i = 0; i < arr.size() - 1;) {
			int indicator = 0;
			for (int j = i+1; j <= arr.size() - i - 1; ++j) {
				if (arr[j] > arr[j - 1]) {
					swap(arr[j], arr[j - 1]);
					indicator = j + 1;
				}
			}
			if (indicator)
				break;
			i = arr.size() - indicator;
		}
	}
};

int main() {
	vector<int> v1{ 5,7,8,1,2 };
	vector<int> v2{ 5,7,8,1,2 };
	vector<int> v3{ 5,7,8,1,2 };
	Solution1 s;
	s.Bubble_sort1(v1);
	show(v1);
	s.Bubble_sort2(v2);
	show(v2);
	s.Bubble_sort3(v3);
	show(v3);
	return 0;
}