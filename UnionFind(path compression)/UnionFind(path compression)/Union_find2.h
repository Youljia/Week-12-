#pragma once
#include<vector>
using namespace std;
class Union_find2
{
public:
	Union_find2(vector<int>& v);
	~Union_find2();
	bool is_connected2(int p, int q);
	void Tunion2(int p, int q);
private:
	int find_root2(int t);
private:
	int* parent;
	int* rank;
};

