#include<iostream>
#include<vector>
using namespace std;

void show(vector<int>& arr) {
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}
class Solution {
public:
	void SheelSort(vector<int>& arr) {
		int h = arr.size() / 2;
		while (h >= 1) {
			for (int start = 0; start < h; ++start) {
				//对每个{start,start+h...}进行插入排序法
				for (int i = start + h; i < arr.size(); i += h) {
					int t = arr[i];
					int j = i;
					for (j; j - h >= 0; j -= h) {
						if (arr[j - h] > arr[j])
							arr[j] = arr[j - h];
						else
							break;
					}
					arr[j] = t;
				}
			}
			h /= 2;
		}
	}
};

int main() {
	vector<int> v1{ 5,7,8,1,2,3 };
	Solution s;
	s.SheelSort(v1);
	show(v1);
	return 0;
}