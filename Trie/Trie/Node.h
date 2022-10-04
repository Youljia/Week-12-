#pragma once
#include<map>
#include<iostream>
using namespace std;
class Node
{
public:
	Node(bool);
	Node();
public:
	map<char, Node*>* next;
	bool is_word;
};

