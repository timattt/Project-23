/*
 * K.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "K.h"
#include "../Syntaxizer.h"
#include "E.h"

K::K() : Node("K") {
}

K::~K() {
}

void K::makeTree(Syntaxizer *snt) {
	climbDown(new E(), snt);
	while (snt->tryConsumeOperator(this, '/')) {
		climbDown(new E(), snt);
	}
}

double K::interpritate() {
	double result = interpritateChild(0);
	for (unsigned i = 2; i < children.size(); i+=2) {
		result /= interpritateChild(i);
	}
	return result;
}
