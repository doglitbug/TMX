#include "TMXUtils.h"

std::unordered_map<std::string, std::string> TMXUtils::getAttributesFromNode(rapidxml::xml_node<>* node)
{
	std::unordered_map < std::string, std::string> output;

	for (rapidxml::xml_attribute<char>* attr = node->first_attribute(); attr; attr = attr->next_attribute())
	{
		output[attr->name()] = attr->value();
	}
	return output;
}