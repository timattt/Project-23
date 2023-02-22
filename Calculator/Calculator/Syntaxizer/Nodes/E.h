/*
 * E.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_E_H_
#define CALCULATOR_SYNTAXIZER_NODES_E_H_

#include "../Node.h"

class E: public Node {
public:

	// contructor and destructor
	E();
	~E();

	// public methods
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;
};

#endif /* CALCULATOR_SYNTAXIZER_NODES_E_H_ */
