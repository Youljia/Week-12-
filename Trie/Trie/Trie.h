#pragma once
#include"Node.h"
#include<string.h>
class Trie
{
public:
	Trie();
	int get_size();
	bool is_empty();
	void add(string word);
	bool contains(string word);
	bool Prefix(string prefix);
private:
	Node* root;
	int size;
};

