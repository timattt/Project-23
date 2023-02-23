/*
 * Token.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_TOKEN_H_
#define CALCULATOR_TOKEN_H_

#include <string>

/**
 * Класс, который представляет из себя терминал в схеме рек спуска.
 * Этот класс будет в дереве листом.
 * Есть два типа токенов - числа и операторы.
 */
class Token {
public:

	// Constructors and destructors
	Token(int num);
	Token(char oper);
	virtual ~Token();

	// Getters
	bool isOperator();
	bool isOperator(char oper);
	bool isNumber();

	// Methods
	virtual const std::string && toString();

	// Public fields
	int number;
	char operat;
};

#endif /* CALCULATOR_TOKEN_H_ */
