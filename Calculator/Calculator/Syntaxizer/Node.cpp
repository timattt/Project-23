/*
 * Node.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "Node.h"

Node::Node(std::string name) : Token(0), name(name) {
}

Node::~Node() {
	for (Token * tkn : children) {
		delete tkn;
	}
}

void Node::climbDown(Node * tkn, Syntaxizer * snt) {
	tkn->makeTree(snt);
	children.push_back(tkn);
}

void Node::makeTree(Syntaxizer * snt) {
}

void Node::addToken(Token * tkn) {
	children.push_back(tkn);
}

double Node::interpritateChild(int i) {
	Token * tkn = children[i];
	Node * nd = dynamic_cast<Node*>(tkn);
	if (nd != nullptr) {
		return nd->interpritate();
	} else if (tkn->isNumber()) {
		return tkn->number;
	}

	ERROR("May not interpritate operator-token");
	return -1;
}

double Node::interpritate() {
	return -1;
}

std::string Node::toString() {
	return name;
}
