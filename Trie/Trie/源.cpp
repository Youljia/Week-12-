#include<iostream>
#include"Trie.h"
#include"Node.h"
using namespace std;
int main() {
	Trie my_tree;
	my_tree.add("panda");
	my_tree.add("pan");
	my_tree.add("fucking");
	cout << my_tree.get_size() << endl;
	if (my_tree.contains("hello"))
		cout << "����hello" << endl;
	if (my_tree.contains("panda"))
		cout << "����panda" << endl;
	if (my_tree.contains("pan"))
		cout << "����pan" << endl;
	return 0;
}