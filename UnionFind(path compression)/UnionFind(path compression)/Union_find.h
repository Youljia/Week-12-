#pragma once
#include<vector>
using namespace std;
class Union_find
{
public:
	Union_find(vector<int>& v);
	~Union_find();
	bool is_connected(int p, int q);
	void Tunion(int p, int q);
private:
	int find_root(int t);
private:
	int* parent;
	int* rank;
};

