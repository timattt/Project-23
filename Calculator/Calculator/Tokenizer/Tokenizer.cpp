#include "../Core/Core.h"
#include "Token.h"

bool isNumber(char c) {
	return c >= '0' && c < '0'+ 10;
}

bool isOperator(char c) {
	for (unsigned i = 0; i < sizeof(OPERATORS); i++) {
		if (c == OPERATORS[i]) {
			return true;
		}
	}

	return false;
}

bool isDelimiter(char c) {
	for (unsigned i = 0; i < sizeof(DELIMITERS); i++) {
		if (c == DELIMITERS[i]) {
			return true;
		}
	}

	return false;
}

void tokenize(std::string line, std::vector<Token*> & result) {
	int numberStart = -1;
	for (unsigned i = 0; i < line.length(); i++) {
		char cur = line[i];

		// number
		if (isNumber(cur)) {
			if (numberStart == -1) {
				numberStart = i;
			}
			continue;
		} else {
			if (numberStart != -1) {
				int numberEnd = i;
				std::string num = line.substr(numberStart, numberEnd);
				result.push_back(new Token(std::stoi(num)));
				numberStart = -1;
			}
		}
		// operator
		if (isOperator(cur)) {
			result.push_back(new Token(cur));
			continue;
		}
		// delimiter
		if (isDelimiter(cur)) {
			continue;
		}
		// strange thing
		printf("[%c]\n", cur);
		ERROR("Strange symbol while tokenizing");
	}

	// if number is last
	if (numberStart != -1) {
		int numberEnd = line.length();
		std::string num = line.substr(numberStart, numberEnd);
		result.push_back(new Token(std::stoi(num)));
		numberStart = -1;
	}
}

void printTokens(std::vector<Token*> & tokens) {
	printf("[");
	for (unsigned i = 0; i < tokens.size(); i++) {
		if (tokens[i]->operat == 0) {
			printf("num=%d", tokens[i]->number);
		} else {
			printf("op=%c", tokens[i]->operat);
		}
		if (i + 1 < tokens.size()) {
			printf(", ");
		}
	}
	printf("]\n");
}
