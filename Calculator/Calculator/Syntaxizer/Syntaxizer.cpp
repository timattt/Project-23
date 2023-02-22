/*
 * Syntaxizer.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "Syntaxizer.h"

#include "../Tokenizer/Token.h"
#include "Node.h"
#include "Nodes/G.h"

Syntaxizer::Syntaxizer(std::vector<Token*> & tokens) : tokens(tokens), current(0) {
}

Syntaxizer::~Syntaxizer() {
}


bool Syntaxizer::tryOperator(char oper) {
	return hasMoreTokens() && currentToken()->isOperator(oper);
}

bool Syntaxizer::tryNumber() {
	return hasMoreTokens() && currentToken()->isNumber();
}

void Syntaxizer::consumeOperator(Node * nd, char oper) {
	if (!tryOperator(oper)) {
		printf("Required operator [%c]\n", oper);
		printFancyInfoAboutTokensError(tokens, current);
		ERROR("Bad tokens list");
	}

	nd->addToken(currentToken());
	current++;
}

void Syntaxizer::consumeNumber(Node * nd) {
	if (!tryNumber()) {
		printf("Required number\n");
		printFancyInfoAboutTokensError(tokens, current);
		ERROR("Bad tokens list");
	}

	nd->addToken(currentToken());
	current++;
}

bool Syntaxizer::tryConsumeOperator(Node * nd, char oper) {
	if (tryOperator(oper)) {
		consumeOperator(nd, oper);
		return true;
	}
	return false;
}

Token* Syntaxizer::currentToken() {
	if (current >= tokens.size()) {
		ERROR("Out of tokens limit");
	}
	return tokens.operator [](current);
}

bool Syntaxizer::hasMoreTokens() {
	return current < tokens.size();
}

bool Syntaxizer::tryConsumeNumber(Node * nd) {
	if (tryNumber()) {
		consumeNumber(nd);
		return true;
	}

	return false;
}
