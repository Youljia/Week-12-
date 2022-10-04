#include "Trie.h"
Trie::Trie() {
	this->root = new Node;
	this->size = 0;
}
int Trie::get_size() {
	return this->size;
}
bool Trie::is_empty() {
	if (this->size)
		return false;
	else
		return true;
}
//在Trie树中添加单词
void Trie::add(string word) {
	Node* cur = this->root;
	for (int i = 0; i < word.size()-1; ++i) {
		char c = word.at(i);
		if (cur->next->at(c) == NULL) {
			cur->next->insert(pair<char,Node*>(c,new Node));
		}
		cur = cur->next->at(c);
	}
	if (!cur->is_word) {
		cur->is_word = true;
		size++;
	}
}
//是否包含某个单词
bool Trie::contains(string word) {
	Node* cur = this->root;
	for (int i = 0; i < word.size(); ++i) {
		char c = word.at(i);
		if (cur->next->at(c) == NULL)return false;
		cur = cur->next->at(c);
	}
	return cur->is_word;
}
//查找是否有以prefix为前缀的单词
bool Trie::Prefix(string prefix) {
	Node* cur = this->root;
	for (int i = 0; i < prefix.size(); ++i) {
		char c = prefix.at(i);
		if (cur->next->at(c) == NULL)return false;
		cur = cur->next->at(c);
	}
	return true;
}
