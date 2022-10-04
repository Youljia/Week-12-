#include "Node.h"
Node::Node(bool is_word) {
	this->is_word = is_word;
	this->next = new map<char, Node*>;
}
Node::Node() {
	this->is_word = false;
	this->next = new map<char, Node*>;
}
