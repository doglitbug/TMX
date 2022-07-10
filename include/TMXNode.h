#pragma once

#include <string>
#include <unordered_map>

class TMXNode
{
public:
	TMXNode();
	~TMXNode();

	std::string GetAttribute(std::string attribute);
	int GetAttributeInt(std::string attribute);
protected:
	std::unordered_map<std::string, std::string> attributes;
};