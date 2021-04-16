#ifndef ERROR_H
#define ERROR_H

#include <string>

#include "Position.h"

class Error
{
private:
	std::string m_name;
	std::string m_description;
	std::string m_filename;
	std::string m_text;
	Position start_pos;
	Position end_pos;
public:
	Error();
	Error(std::string, std::string, std::string, std::string, Position, Position);
	std::string as_string();
	bool is_null();
};


#endif//ERROR_H