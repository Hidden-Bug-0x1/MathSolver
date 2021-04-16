#include "../headers/MathSolver.h"

Error::Error()
{
	m_name = "";
	m_description = "";
	m_filename = "";
	m_text = "";
	start_pos = *new Position();
	end_pos = *new Position();
}

Error::Error(std::string name, std::string description, std::string filename, std::string text, Position start, Position end)
{
	m_name = name;
	m_description = description;
	m_filename = filename;
	m_text = text;
	start_pos = start;
	end_pos = end;
}

std::string Error::as_string()
{
	if (m_description == "") return m_name + ": " + m_description;
	else return m_name;
}

bool Error::is_null()
{
	return m_name == "";
}
