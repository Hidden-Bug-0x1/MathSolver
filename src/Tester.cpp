#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MathSolver.h"

std::pair<std::vector<Token*>*, Error*> run(std::string text) {
	Lexer* lexer = new Lexer("test.txt", text);

	std::pair<std::vector<Token*>*, Error*> tokens = lexer->generate_tokens();

	if (!tokens.second->is_null()) {
		std::cout << tokens.second->as_string() << "\n";
	}
	else {
		for (auto token : *tokens.first) {
			std::cout << (*token).to_string() << ", ";
		}
		std::cout << std::endl;
	}
	return tokens;
}

int main(int argc, char* argv[]) {
	std::ifstream file;
	file.open("test.text", 'r');

	std::string line = "";
	while (line != "EOF") {
		file >> line;
		run(line);
	}

	return 0;
}