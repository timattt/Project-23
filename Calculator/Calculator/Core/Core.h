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
const char OPERATORS[] = {'+', '-', '/', '*', '(', ')'};
const char DELIMITERS[] = {' '};


// PRIVATE METHODS
//tokenizer
void tokenize(std::string line, std::vector<Token*> & result);
void printTokens(std::vector<Token*> & tokens);

// utilities
void makeGraph(Token * root);
void printFancyInfoAboutTokensError(std::vector<Token*> & tokens, int bad);
