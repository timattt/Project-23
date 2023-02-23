#pragma once

// INCLUDES
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Classes.h"


// DEFINES
#define ERROR(MES) printf("Something bad happens in [%s] on [%d] -> [%s]\n", __FILE__, __LINE__, MES); exit(0);
#define ASSERT(COND, MES) if (!(COND)) {ERROR(MES);}


// CONSTANTS
/**
 * Список операторов. Использует при токенизации
 */
const char OPERATORS[] = {'+', '-', '/', '*', '(', ')'};
/**
 * Список разделителей не учитывается при токениации.
 */
const char DELIMITERS[] = {' '};


// PRIVATE METHODS
//tokenizer
/**
 * Разбиваем строку на токены и кладем их в вектор
 */
void tokenize(const std::string & line, std::vector<Token*> & result);
/**
 * ыводи в консоль вектор из токенов
 */
void printTokens(const std::vector<Token*> & tokens);

// utilities
/**
 * Создаем картинку дерева
 */
void makeGraph(Token * root);
/**
 * Если какой-то токен не подходит под грамматику, то можно этой функцией вывести красиво в консоль сообщение ошибке
 */
void printFancyInfoAboutTokensError(const std::vector<Token*> & tokens, int bad);
