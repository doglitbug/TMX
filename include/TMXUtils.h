#pragma once

#include <unordered_map>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

class TMXUtils
{
public:
	/// <summary>
	/// Get a dictionary of all attributes from given node
	/// </summary>
	/// <param name="node">Input node</param>
	/// <returns>Dictionary</returns>
	static std::unordered_map<std::string, std::string> getAttributesFromNode(rapidxml::xml_node<>* node);
};