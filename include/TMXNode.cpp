#include "TMXNode.h"

TMXNode::TMXNode()
{
	attributes = std::unordered_map<std::string, std::string>();
}

TMXNode::~TMXNode()
{
	attributes.clear();
}

std::string TMXNode::GetAttribute(std::string attributeName)
{
	//TODO Return null if not found
	return attributes[attributeName];
}

int TMXNode::GetAttributeInt(std::string attributeName)
{
	//TODO return 0 if not found
	return stoi(GetAttribute(attributeName));
}