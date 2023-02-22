/*
 * Node.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_NODE_H_
#define CALCULATOR_SYNTAXIZER_NODE_H_

#include "../Core/Core.h"
#include "../Tokenizer/Token.h"

/**
 * Класс представляет собой вершину в графе рекурсивного спуска. Наследуется от токена,
 * так что токен тоже может быть вершиной, но только листом.
 *
 * Есть поле с детьми и имя.
 * От этого класса нужно наследовать все нетерминалы.
 */
class Node : public Token {
public:

	// Constructor and destructor
	Node(std::string name);
	~Node();

	// Public fields

	/**список указателей на вершины-дети*/
	std::vector<Token*> children;

	// Public methods

	/**добавляем токен-вершину-ребенка */
	void addToken(Token * tkn);

	/**выводит имя нетерминала*/
	std::string toString() final override;

protected:

	// Protected methods

	/**метод, через который происходит спуск в новый нетерминал в рек спуске
	 */
	void climbDown(Node * tkn, Syntaxizer * snt);

	/**позволяет посчитать значение нужного ребенка.
	 * Например, если это просто число - оно вернет это число.
	 * Если нетерминал, то вернет его посчитанное значение.
	 */
	double interpritateChild(int i);

	/**Основной метод алгоритма рек спуска - строит поддерерво для этой вершины,
	 * используя токены из токенайзера. Для каждого нетерминала надо переопределеить
	 */
	virtual void makeTree(Syntaxizer * snt);

	/**Считает значение поддерева этого нетерминала
	 */
	virtual double interpritate();

private:

	// private fields

	/**имя данного нетерминала*/
	std::string name;

};

#endif /* CALCULATOR_SYNTAXIZER_NODE_H_ */
