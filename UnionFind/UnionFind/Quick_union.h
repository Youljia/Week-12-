#pragma once
#include<vector>
using namespace std;
class Quick_union
{
public:
	Quick_union(vector<int>& v1);
	~Quick_union();
	void Tunion2(int p, int q);
	bool is_connected2(int p, int q);
private:
	int find_root(int t);
private:
	int* parent;
};

