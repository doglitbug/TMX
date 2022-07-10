#pragma once

#include "TMXNode.h"
#include <string>
#include <unordered_map>

class TMXTileSet :public TMXNode
{
public:
	TMXTileSet();
	~TMXTileSet();

	std::string getName() { return GetAttribute("name"); };
};