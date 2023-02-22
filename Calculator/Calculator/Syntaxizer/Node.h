/*
 * Node.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODE_H_
#define CALCULATOR_SYNTAXIZER_NODE_H_

#include "../Core/Core.h"
#include "../Tokenizer/Token.h"

class Node : public Token {
public:

	// Constructor and destructor
	Node(std::string name);
	~Node();

	// Public fields
	std::vector<Token*> children;

	// Public methods
	void addToken(Token * tkn);
	std::string toString() final override;
	virtual double interpritate();

protected:

	// Protected methods
	void climbDown(Node * tkn, Syntaxizer * snt);
	double interpritateChild(int i);
	virtual void makeTree(Syntaxizer * snt);


private:

	// private fields
	std::string name;

};

#endif /* CALCULATOR_SYNTAXIZER_NODE_H_ */
