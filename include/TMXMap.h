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

#pragma region Accessors
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

#pragma endregion

	/// <summary>
	/// Load up tileSets from XML node
	/// </summary>
	/// <param name="node">Node to load TileSets from</param>
	void loadTileSets(rapidxml::xml_node<>* node);

	/// <summary>
	/// Get reference to a TileSet
	/// </summary>
	/// <param name="tileSetName">Name of TileSet</param>
	/// <returns>TMXTileSet *</returns>
	TMXTileSet* getTileSet(std::string tileSetName);	

private:
	std::vector<TMXTileSet> tileSets;
	/// <summary>
	/// Load a TileSet from TSX file
	/// </summary>
	/// <param name="tileSet">TileSet to load into</param>
	/// <param name="filePath">Base folder for TSX file</param>
	void loadTileSet(TMXTileSet& tileSet, std::string filePath);
};