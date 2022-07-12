#pragma once

#include "TMXNode.h"
#include "TMXImage.h"
#include <string>
#include <unordered_map>

class TMXTileSet : public TMXNode
{
public:
	TMXTileSet();
	~TMXTileSet();

	std::string getName() { return getAttribute("name"); };
	TMXImage *getImage() { return image; };

private:
	TMXImage *image;
};