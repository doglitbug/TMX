#include "Parser.h"
#include <iostream>

dlb::Parser::Parser(const char* filename)
{
	std::cout << "Request to load " << filename << std::endl;
}

dlb::Parser::Parser()
{
}

dlb::Parser::~Parser()
{
}