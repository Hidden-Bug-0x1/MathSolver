#include "../headers/MathSolver.h"

Position::Position() {
	m_index = -1;
	m_line = 1;
	m_column = 0;
	m_filename = "";
	m_filetext = "";
}

Position::Position(long index, long line, long column, std::string filename, std::string text) {
	m_index = index;
	m_line = line;
	m_column = column;
	m_filename = filename;
	m_filetext = text;
}

Position* Position::advance(char current_char) {
	m_index++;
	m_column++;

	if (current_char == '\n') {
		m_line++;
		m_column = 0;
	}

	return this;
}

Position* Position::copy() {
	return new Position(m_index, m_line, m_column, m_filename, m_filetext);
}

long Position::get(std::string property) {
	if (property == "index") {
		return m_index;
	}
	else if (property == "line") {
		return m_line;
	}
	else if (property == "column") {
		return m_column;
	}
	else {
		return -2;
	}
}

void Position::set(std::string property, long value)
{
	if (property == "index") {
		m_index = value;
	}
	else if (property == "line") {
		m_line = value;
	}
	else if (property == "column") {
		m_column = value;
	}
}
