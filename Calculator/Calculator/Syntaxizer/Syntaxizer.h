/*
 * Syntaxizer.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_
#define CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_

#include "../Core/Core.h"

class Syntaxizer {
public:

	// constructor and destructor
	Syntaxizer(std::vector<Token*> & tokens);
	~Syntaxizer();

	// public methods
	bool tryOperator(char oper);
	bool tryNumber();
	void consumeOperator(Node * nd, char oper);
	void consumeNumber(Node * nd);
	bool tryConsumeOperator(Node * nd, char oper);
	bool tryConsumeNumber(Node * nd);

private:

	// private fields
	std::vector<Token*> & tokens;
	unsigned current;

	// private methods
	Token* currentToken();
	bool hasMoreTokens();

};

#endif /* CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_ */
