/*
 * Token.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "Token.h"
#include <string>

Token::Token(int num) : number(num), operat(0) {

}

Token::Token(char oper) : number(0), operat(oper) {
}

Token::~Token() {
}

bool Token::isOperator() {
	return operat != 0;
}

bool Token::isOperator(char oper) {
	return isOperator() && operat == oper;
}

bool Token::isNumber() {
	return operat == 0;
}

const std::string && Token::toString() {
	if (isNumber()) {
		return std::move(std::to_string(number));
	}
	if (isOperator()) {
		return std::move(std::string(1, operat));
	}

	return std::move(std::string("unknown"));
}
