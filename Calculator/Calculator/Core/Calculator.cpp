#include "../Syntaxizer/Nodes/G.h"
#include "Core.h"

//#define DEBUG

double calculate(std::string line) {
	// TOKENIZATION
	std::vector<Token*> tokens;
	tokenize(line, tokens);
#ifdef DEBUG
	printTokens(tokens);
#endif

	// SYNTAX ANALISYS AND TREE BUILD
	G * tree = new G(tokens);
#ifdef DEBUG
	makeGraph(tree);
#endif

	// INTERPRITATION
	double result = tree->interpritate();

	// CLEANUP
	delete tree;

	return result;
}
