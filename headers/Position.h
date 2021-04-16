#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position
{
private:
	long m_index;
	long m_line;
	long m_column;
	std::string m_filename;
	std::string m_filetext;
public:
	Position(); // nothing to do
	Position(long, long, long, std::string, std::string);
	Position* advance(char);
	Position* copy();
	long get(std::string);
	void set(std::string, long);
};


#endif//POSITION_H