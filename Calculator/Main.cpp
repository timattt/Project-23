#include <iostream>
#include <string>
#include <vector>

#include "Calculator/Calculator.h"

int main() {
	std::string line = {};
	std::cin >> line;
	std::cout << calculate(line);

	return 0;
}
