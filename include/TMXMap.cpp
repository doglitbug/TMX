#include "TMXMap.h"

TMXMap::TMXMap()
{
}

TMXMap::~TMXMap()
{
}

void TMXMap::setMapAttributes(std::unordered_map<std::string, std::string> attributes)
{
	this->attributes = attributes;
}