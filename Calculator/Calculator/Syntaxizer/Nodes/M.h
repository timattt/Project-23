/*
 * M.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_M_H_
#define CALCULATOR_SYNTAXIZER_NODES_M_H_

#include "../Node.h"

class M: public Node {
public:
	M();
	~M();
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;
};

#endif /* CALCULATOR_SYNTAXIZER_NODES_M_H_ */
