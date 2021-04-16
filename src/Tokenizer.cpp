#include "../headers/Tokenizer.h"

#define str(value) #value
std::string Token::token_string(Tokens type)
{
	switch (type) {
	case Tokens::INTEGER:
		return str(INTEGER);
	case Tokens::FLOAT:
		return str(FLOAT);
	case Tokens::PLUS:
		return str(PLUS);
	case Tokens::MINUS:
		return str(MINUS);
	case Tokens::MULTIPLY:
		return str(MULTIPLY);
	case Tokens::DIVIDE:
		return str(DIVIDE);
	case Tokens::MODULO:
		return str(MODULO);
	case Tokens::OPEN_PARENTHESES:
		return str(OPEN_PARENTHESES);
	case Tokens::CLOSE_PARENTHESES:
		return str(CLOSE_PARENTHESES);
	case Tokens::EQUAL:
		return str(EQUAL);
	case Tokens::FUNCTION:
		return str(FUNCTION);
	case Tokens::VARIABLE:
		return str(VARIABLE);
	case Tokens::END:
		return str(END);
	default:
		return "INVALID";
	}
}

Token::Token(Tokens type, std::string content)
{
	m_type = type;
	m_content = content;
}

std::string Token::to_string()
// like the java toString() overrideable method
{
	return "<" + token_string(m_type) + " : " + m_content + ">";
}
