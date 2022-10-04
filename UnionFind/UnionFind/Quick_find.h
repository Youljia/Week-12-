#pragma once
#include<vector>
using namespace std;
class Quick_find
{
public:
	Quick_find(vector<int>& v);
	void Tunion(int p, int q);
	bool is_connected(int p, int q);
private:
	int find(int t);
private:
	int* id;
	int size;
};

