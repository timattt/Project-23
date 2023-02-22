/*
 * G.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODES_G_H_
#define CALCULATOR_SYNTAXIZER_NODES_G_H_

#include "../Node.h"

/**
 * Класс корневого нетерминала.
 * Чтобы построить граф нужно список токенов запихать в объект этого класса.
 */
class G: public Node {
public:

	// contructor and destructor
	G(std::vector<Token*> & tokens);
	~G();

public:

	// public methods
	void makeTree(Syntaxizer *snt) override;
	double interpritate() override;

};

#endif /* CALCULATOR_SYNTAXIZER_NODES_G_H_ */
