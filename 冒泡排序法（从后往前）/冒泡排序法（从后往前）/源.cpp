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

class Solution {
public:
	//冒泡排序法，从后往前走
	void BubbleSort(vector<int>& arr) {
		for (int i = 0; i < arr.size() - 1;) {
			int indicator = 0;
			for (int j = arr.size() - 1; j >= i + 1; --j) {
				if (arr[j - 1] > arr[j]) {
					swap(arr[j - 1], arr[j]);
					indicator = j;
				}
			}
			if (!indicator)
				break;
			i = indicator;
		}
	}
};

int main()
{
	vector<int> v1{ 5,7,8,1,2 };
	Solution s;
	s.BubbleSort(v1);
	show(v1);
	return 0;
}