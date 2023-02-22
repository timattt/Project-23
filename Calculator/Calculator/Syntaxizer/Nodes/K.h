/*
 * K.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_K_H_
#define CALCULATOR_SYNTAXIZER_NODES_K_H_

#include "../Node.h"

class K: public Node {
public:
	K();
	~K();
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;
};

#endif /* CALCULATOR_SYNTAXIZER_NODES_K_H_ */
