#include "TMXMap.h"

TMXMap::TMXMap()
{
	attributes = std::unordered_map<std::string, std::string>();
}

TMXMap::~TMXMap()
{
	attributes.clear();
}

void TMXMap::setMapAttributes(std::unordered_map<std::string, std::string> attributes)
{
	this->attributes = attributes;
}

std::string TMXMap::GetAttribute(std::string attributeName)
{
	//TODO Return null if not found
	return attributes[attributeName];
}

int TMXMap::GetAttributeInt(std::string attributeName)
{
	//TODO return 0 if not found
	return stoi(GetAttribute(attributeName));
}