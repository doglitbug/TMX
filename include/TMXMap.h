#pragma once

#include <string>
#include <unordered_map>
#include "TMXTileSet.h"
#include "TMXNode.h"

class TMXMap : public TMXNode
{
public:
	TMXMap();
	~TMXMap();

	/// <summary>
	/// Get map width in tiles
	/// </summary>
	/// <returns>int</returns>
	int getWidth() { return GetAttributeInt("width"); };

	/// <summary>
	/// Get map height in tiles
	/// </summary>
	/// <returns>int </returns>
	int getHeight() { return GetAttributeInt("height"); };

	/// <summary>
	/// Get tile width in pixels
	/// </summary>
	/// <returns>int</returns>
	int getTileWidth() { return GetAttributeInt("tilewidth"); };

	/// <summary>
	/// Get tile height in pixels
	/// </summary>
	/// <returns>int</returns>
	int getTileHeight() { return GetAttributeInt("tileheight"); };

	/// <summary>
	/// Set map attributes in bulk from Parser
	/// </summary>
	/// <param name="attributes">Attributes</param>
	void setMapAttributes(std::unordered_map<std::string, std::string> attributes);

private:
	std::unordered_map<std::string, TMXTileSet*> tileSets;
};