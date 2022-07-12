#pragma once

#include <string>
#include <unordered_map>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

class TMXNode
{
public:
	TMXNode();
	~TMXNode();

	void loadAttributes(rapidxml::xml_node<>* node);

	std::string getAttribute(std::string attribute);
	int getAttributeInt(std::string attribute);
protected:
	std::unordered_map<std::string, std::string> attributes;
};