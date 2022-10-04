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
//��Trie������ӵ���
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
//�Ƿ����ĳ������
bool Trie::contains(string word) {
	Node* cur = this->root;
	for (int i = 0; i < word.size(); ++i) {
		char c = word.at(i);
		if (cur->next->at(c) == NULL)return false;
		cur = cur->next->at(c);
	}
	return cur->is_word;
}
//�����Ƿ�����prefixΪǰ׺�ĵ���
bool Trie::Prefix(string prefix) {
	Node* cur = this->root;
	for (int i = 0; i < prefix.size(); ++i) {
		char c = prefix.at(i);
		if (cur->next->at(c) == NULL)return false;
		cur = cur->next->at(c);
	}
	return true;
}
