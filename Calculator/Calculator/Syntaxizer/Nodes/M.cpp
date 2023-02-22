/*
 * M.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "M.h"
#include "T.h"
#include "../Syntaxizer.h"

M::M() : Node("M") {
}

M::~M() {
}

void M::makeTree(Syntaxizer *snt) {
	climbDown(new T(), snt);
	while (snt->tryConsumeOperator(this, '-')) {
		climbDown(new T(), snt);
	}
}

double M::interpritate() {
	double result = interpritateChild(0);
	for (unsigned i = 2; i < children.size(); i+=2) {
		result -= interpritateChild(i);
	}
	return result;
}
