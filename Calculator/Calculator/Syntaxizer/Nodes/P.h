/*
 * P.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_P_H_
#define CALCULATOR_SYNTAXIZER_NODES_P_H_

#include "../Node.h"

class P: public Node {
public:
	P();
	~P();
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;
};

#endif /* CALCULATOR_SYNTAXIZER_NODES_P_H_ */
