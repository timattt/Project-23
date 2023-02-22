/*
 * E.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "E.h"
#include "../Syntaxizer.h"
#include "P.h"

E::E() : Node("E") {
}

E::~E() {
}

void E::makeTree(Syntaxizer *snt) {
	snt->tryConsumeOperator(this, '-');
	if (!snt->tryConsumeNumber(this)) {
		snt->consumeOperator(this, '(');
		climbDown(new P(), snt);
		snt->consumeOperator(this, ')');
	}
}

double E::interpritate() {
	int start = 0;
	if (children[0]->isOperator('-')) {
		start = 1;
	}
	double result = -1;
	if (children.size() <= 2) {
		result = interpritateChild(start);
	}
	if (children.size() >= 3) {
		result = interpritateChild(start+1);
	}
	if (start == 1) {
		result = -result;
	}

	return result;
}
