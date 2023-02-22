#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Calculator/Calculator.h"

/**
 * Сравниваем результат вычисления на питоне и через код.
 * Выводим в консоль
 */
bool compare(std::string line) {
	std::string cmd = "python -c \"print("+line+")\"";

	FILE *in = popen(cmd.c_str(), "r");

	double trueResult = 0;
	fscanf(in, "%lf", &trueResult);

	pclose(in);

	double calcRes = calculate(line);
	bool ok = abs(trueResult - calcRes) < 0.01;

	printf("%s\n", line.c_str());

	if (ok) {
		printf("OK ");
	}

	printf("True=%0.1lf, Calc=%0.1lf\n", trueResult, calcRes);
	fflush(stdout);

	return ok;
}

/**
 * Тесты, которые генерируют рандомные выражения
 */
//=====================================================
std::string genSimpleTest1(int k) {
	std::string res = "";
	for (int i = 0; i < k; i++) {
		res+=std::to_string(rand()%100);
		switch(rand()%2) {
		case 0: res+="-";break;
		case 1: res+="+";break;
		}
	}
	res+=std::to_string(rand()%100);
	return res;
}

std::string genSimpleTest2(int k) {
	std::string res = "";
	for (int i = 0; i < k; i++) {
		res+=std::to_string(-5+rand()%50);
		switch(rand()%2) {
		case 0: res+="*";break;
		case 1: res+="+";break;
		}
	}
	res+=std::to_string(rand()%100);
	return res;
}

std::string genTest1(int k) {
	if (k <= 1) {
		return std::to_string(rand()%10);
	}
	std::string res = "";
	for (int i = 0; i < k; i++) {
		if (rand() % 5 == 1) {
			res+="(" + genTest1(k-1)+")";
		} else
			res+=std::to_string(-5+(rand()%10));
		switch(rand()%2) {
		case 0: res+="*";break;
		case 1: res+="+";break;
		}
	}
	res+=std::to_string(rand()%10);
	return res;
}

std::string genTest2(int k) {
	if (k <= 1) {
		return std::to_string(1+rand()%10);
	}
	std::string res = "";
	for (int i = 0; i < k; i++) {
		if (rand() % 5 == 1) {
			res+="(" + genTest2(k-1)+")";
		} else
			res+=std::to_string(1+(rand()%10));
		switch(rand()%4) {
		case 0: res+="*";break;
		case 1: res+="+";break;
		case 2: res+="-";break;
		case 3: res+="/";break;
		}
	}
	res+=std::to_string(1+rand()%10);
	return res;
}
//=====================================================

/**
 * Запускает шаблонный тест. Возвращает кол успешных итераций.
 */
int pattern(std::string (*testFunc)(int), int total, int len) {
	int err = 0;
	for (int i = 0; i < total; i++) {
		std::string test = testFunc(len);
		if (!compare(test)) {
			err++;
			printf("ERROR: %s\n", test.c_str());
			break;
		}
	}

	return total-err;
}

int main() {
#define TOTAL_PER_TEST 50
#define TEST(FUNC, LEN) oks.push_back(pattern(FUNC, TOTAL_PER_TEST, LEN));

	std::vector<int> oks;

	TEST(genSimpleTest1, 50)
	TEST(genSimpleTest2, 50)
	TEST(genTest1, 7)
	TEST(genTest2, 7)

	for (unsigned i = 0; i < oks.size(); i++) {
		printf("%d/%d\n", oks[i], TOTAL_PER_TEST);
	}

	return 0;
}
