#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

enum class Tokens {
	INTEGER,			// eg: 981
	FLOAT,				// eg: 1.20
	PLUS,				// +
	MINUS,				// -
	MULTIPLY,			// *
	DIVIDE,				// /
	MODULO,				// %
	OPEN_PARENTHESES,	// (
	CLOSE_PARENTHESES,	// )
	EQUAL,				// =
	FUNCTION,			// sin, cos, tan, etc...
	VARIABLE,			// anything not a recognized function
	END,				// end of input
};

class Token
{
private:
	Tokens m_type;
	std::string m_content;
protected:
	std::string token_string(Tokens); // turns the token into a string
public:
	Token(Tokens, std::string); // takes in a type and value
	std::string to_string(); // for printing out to stdout
};

#endif//TOKENIZER_H