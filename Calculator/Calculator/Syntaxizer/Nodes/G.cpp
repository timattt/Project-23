/*
 * G.cpp
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#include "G.h"
#include "P.h"
#include "../../Core/Core.h"
#include "../Syntaxizer.h"

G::G(std::vector<Token*> & tokens) : Node("G") {
	ASSERT(tokens.size() > 0, "Empty line");
	Syntaxizer * snt = new Syntaxizer(tokens);
	makeTree(snt);
	delete snt;
}

G::~G() {
}

void G::makeTree(Syntaxizer *snt) {
	climbDown(new P(), snt);
}

double G::interpritate() {
	ASSERT(children.size() == 1, "Bad root children count");

	return interpritateChild(0);
}
