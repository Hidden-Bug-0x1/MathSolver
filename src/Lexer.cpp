#include "Lexer.h"

#define EOI -2

bool Lexer::in(char target, std::string string)
{
	for (char cur : string) {
		if (cur == target) return true;
	}
	return false;
}

Token * Lexer::make_number()
{
	std::string number = "" + current_char;
	Tokens type = Tokens::INTEGER;
	int decimals = 0;
	
	// parse the input
	while (!in(current_char, " \t\n")) {
		
		number += current_char;
		if (current_char == '.') {
			decimals++;
			type = Tokens::FLOAT;
		}
		advance();
	}
	
	if (decimals > 1) {
		throw "Too many decimals in float"; // create new error files??
	}

	return new Token(type, number);
}

Token * Lexer::make_identifier()
{
	std::string identifier = "";

	while (!in(current_char, " \t\n")) {
		identifier += current_char;
		// need to validate if its a variable or function
		advance();
	}

	return new Token(Tokens::VARIABLE, identifier);
}

Token * Lexer::make_binary_operation()
{
	return nullptr;
}

Token * Lexer::make_unary_operation()
{
	return nullptr;
}

Lexer::Lexer(std::string input_text, std::string filename)
{
	m_filename = filename;
	m_text = input_text;
	m_index = new Position(-1, 0, -1, filename, input_text);
	current_char = NULL;
}

void Lexer::advance()
{
	m_index->advance(current_char) ; // move to the next character

	// if the next character is past the end of my text
	if (m_index->get("index") > (signed long)m_text.length()) {
		m_index->set("index", EOF); // indicate at end of "file"
		current_char = NULL; // set the current char to null
		return; // safely exit function
	}

	//else
	current_char = tolower(m_text[m_index->get("index")]); // get and set the current char
}

std::pair<std::vector<Token*>*, Error*> Lexer::generate_tokens()
{
	std::vector<Token*>* tokens = new std::vector<Token*>();

	do {
		advance(); // load the next character in

		// check the current char for .....
		if (in(current_char, " \t")) {
			// don't care about spaces
			continue;
		}
		else if (in(current_char, "1234567890")) {
			// make a number
			Token* token = make_number();
			tokens->push_back(token);
		}
		else if (in(current_char, "abcdefghijklmnopqrstuvwxyz")) {
			Token* token = make_identifier();
			tokens->push_back(token);
		} 
		else if (current_char == '+') {
			tokens->push_back(new Token(Tokens::PLUS, ""));
		}
		else if (current_char == '-') {
			tokens->push_back(new Token(Tokens::MINUS, ""));
		}
		else if (current_char == '*') {
			tokens->push_back(new Token(Tokens::MULTIPLY, ""));
		}
		else if (current_char == '/') {
			tokens->push_back(new Token(Tokens::DIVIDE, ""));
		}
		else if (current_char == '=') {
			tokens->push_back(new Token(Tokens::EQUAL, ""));
		}
		else if (current_char == '(') {
			tokens->push_back(new Token(Tokens::OPEN_PARENTHESES, ""));
		}
		else if (current_char == ')') {
			tokens->push_back(new Token(Tokens::CLOSE_PARENTHESES, ""));
		}
		else {
			Position* copy = m_index->copy();
			char cur_char = current_char;
			advance();
			std::string desc = "'" + cur_char;
			desc += "'";
			return std::make_pair(new std::vector<Token*>(), new Error("IllegalChar", desc, m_filename, m_text, *copy, *m_index));
		}
		
	} while (m_index->get("index") != EOI);

	tokens->push_back(new Token(Tokens::END, ""));

	return std::make_pair(tokens, new Error());
}
