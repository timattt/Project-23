/*
 * Syntaxizer.h
 *
 *  Created on: 22 февр. 2023 г.
 *      Author: timat
 */

#ifndef CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_
#define CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_

#include "../Core/Core.h"

/**
 * Класс, который хранит данные о текущем рекурсивном спуске.
 * Главное - о токенах, которые сейчас обрабатыдваются.
 * Тут есть удобные методы для захвата нетерминалами новых токенов и проверки
 * на их наличие.
 */
class Syntaxizer {
public:

	// constructor and destructor
	Syntaxizer(const std::vector<Token*> & tokens);
	~Syntaxizer();

	// public methods

	/**
	 * Проверяет является ли следующий токен опреатором.
	 */
	bool tryOperator(char oper);

	/**
	 * Проверяет, является ли след токен числом
	 */
	bool tryNumber();

	/**
	 *Присоединяет токен к нетерминалу. Токен должен быть оператором заданным. Если он другого типа, то ошибка.
	 */
	void consumeOperator(Node * nd, char oper);

	/**
	 *Присоединяет токен к нетерминалу. Токен должен быть числом. Если он другого типа, то ошибка.
	 */
	void consumeNumber(Node * nd);

	/**
	 * Проверяет подходит ли токен, если да, то присоединяет.
	 */
	bool tryConsumeOperator(Node * nd, char oper);

	/**
	 * Проверяет подходит ли токен, если да, то присоединяет.
	 */
	bool tryConsumeNumber(Node * nd);

private:

	// private fields

	/**
	 * Список токенов
	 */
	const std::vector<Token*> & tokens;

	/**
	 * Номер текущего токена
	 */
	unsigned current;

	// private methods

	/**
	 * Возвращает текущий токен, или кидает ошибку, если токены кончились
	 */
	Token* currentToken();

	/**
	 * проверяет есть ли еще токены
	 */
	bool hasMoreTokens();

};

#endif /* CALCULATOR_SYNTAXIZER_SYNTAXIZER_H_ */
