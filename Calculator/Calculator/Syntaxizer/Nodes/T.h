/*
 * T.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_T_H_
#define CALCULATOR_SYNTAXIZER_NODES_T_H_

#include "../Node.h"

class T: public Node {
public:

	// contructor and destructor
	T();
	~T();

	// public methods
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;
};

#endif /* CALCULATOR_SYNTAXIZER_NODES_T_H_ */
