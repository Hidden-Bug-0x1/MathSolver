#pragma once

/*
	The first step in parsing input
*/

#include <fstream>
#include <string>
#include <vector>

#include "Tokenizer.h"
#include "Error.h"

// allows unique parameters to be passed into one function
struct Data {

};

class Lexer
{
private:
	std::string m_filename; // file of m_text
	std::string m_text; // data to analyze
	char current_char;	// char at index
	Position* m_index;		// index of current char
protected:
	bool in(char, std::string); // see if char is in string
	Token* make_number(); // makes a number token
	Token* make_identifier(); // makes an identifier
	Token* make_binary_operation(); // makes a binary operation
	Token* make_unary_operation(); // makes a unary operation
public:
	Lexer(std::string, std::string);
	void advance(); // advance the current_char
	std::pair<std::vector<Token*>*, Error*> generate_tokens(); // generate the tokens from m_text
};

