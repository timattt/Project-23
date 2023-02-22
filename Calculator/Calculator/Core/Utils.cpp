#include "Core.h"
#include "../Syntaxizer/Node.h"

int dfsToDotFile(Token * root, std::ofstream & dest, bool top) {
	if (top) {
		dest << "digraph  G {";
	}

	// это индекс данной вершины
	int index = rand() % 100000;//совпадение индексов очень маловероятно

	// для вершин не листьев
	Node * nd = (Node*) dynamic_cast<Node*>(root);

#ifdef DEBUG
	if (nd != nullptr) {
	dest << "vert" << index << "[label=" << '"' << root->toString() << "=" << nd->interpritate() << '"' << "]\n";
	} else
#endif
	dest << "vert" << index << "[label=" << '"' << root->toString()  << '"' << "]\n";

	// ребра
	if (nd != nullptr) {
		std::vector<int> indices;
		for (Token *tk : nd->children) {
			indices.push_back(dfsToDotFile(tk, dest, false));
		}

		for (int ind : indices) {
			dest << "vert" << index << " -> " << "vert" << ind << "\n";
		}
	}
	if (top) {
		dest << "}";
	}

	return index;
}

void makeGraph(Token *root) {
	std::remove("tmp.dot");
	std::remove("calc.png");
	std::ofstream dot;
	dot.open("tmp.dot");
	dfsToDotFile(root, dot, 1);
	dot.close();
	system("dot -Tpng tmp.dot -o calc.png");
	std::remove("tmp.dot");
}

void printFancyInfoAboutTokensError(const std::vector<Token*> & tokens, int bad) {
	std::string res = {};
	for (int i = 0; i < bad; i++) {
		Token * t = tokens[i];
		res += t->toString();
	}
	std::cout << res << "\n";
	for (unsigned i = 0; i < res.length(); i++) {
		printf(" ");
	}
	printf("^\n");
	for (unsigned i = 0; i < res.length(); i++) {
		printf(" ");
	}
	printf("|\n");
	for (unsigned i = 0; i < res.length(); i++) {
		printf("-");
	}
	printf("+\n");
}
