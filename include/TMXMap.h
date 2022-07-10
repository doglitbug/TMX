#pragma once

#include <string>
#include <iostream>
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
	/// Load up tileSets from XML
	/// </summary>
	/// <param name="node"></param>
	void loadTileSets(rapidxml::xml_node<>* node);

	TMXTileSet *getTileSet(std::string tileSetName);

	//TODO make private?
	std::vector<TMXTileSet> tileSets;
};