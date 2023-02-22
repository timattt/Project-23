/*
 * T.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "T.h"
#include "K.h"
#include "../Syntaxizer.h"

T::T() : Node("T") {
}

T::~T() {
}

void T::makeTree(Syntaxizer *snt) {
	snt->tryConsumeOperator(this, '-');
	climbDown(new K(), snt);
	while (snt->tryConsumeOperator(this, '*')) {
		climbDown(new K(), snt);
	}
}

double T::interpritate() {
	int start = 0;
	if (children[0]->isOperator('-')) {
		start = 1;
	}
	double result = interpritateChild(start);
	for (unsigned i = 2+start; i < children.size(); i+=2) {
		result *= interpritateChild(i);
	}

	if (start == 1) {
		result = -result;
	}

	return result;
}
