#include "TMXNode.h"

TMXNode::TMXNode()
{
	attributes = std::unordered_map<std::string, std::string>();
}

TMXNode::~TMXNode()
{
	attributes.clear();
}

void TMXNode::loadAttributes(rapidxml::xml_node<>* node)
{
	for (rapidxml::xml_attribute<char>* attr = node->first_attribute(); attr; attr = attr->next_attribute())
	{
		attributes[attr->name()] = attr->value();
	}
}

#pragma region Accessors
std::string TMXNode::getAttribute(std::string attributeName)
{
	//TODO Return null if not found
	return attributes[attributeName];
}

int TMXNode::getAttributeInt(std::string attributeName)
{
	//TODO return 0 if not found
	return stoi(getAttribute(attributeName));
}
#pragma endregion Accessors