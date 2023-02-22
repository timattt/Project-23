/*
 * P.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "P.h"
#include "../Syntaxizer.h"
#include "M.h"

P::P() : Node("P") {
}

P::~P() {
}

void P::makeTree(Syntaxizer *snt) {
	climbDown(new M(), snt);
	while (snt->tryConsumeOperator(this, '+')) {
		climbDown(new M(), snt);
	}
}

double P::interpritate() {
	double result = interpritateChild(0);
	for (unsigned i = 2; i < children.size(); i+=2) {
		result += interpritateChild(i);
	}
	return result;
}
