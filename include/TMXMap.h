#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "TMXNode.h"
#include "TMXTileSet.h"
#include "TMXLayer.h"

class TMXMap : public TMXNode
{
public:
	TMXMap();
	~TMXMap();

#pragma region Attributes
	/// <summary>
	/// Get map width in tiles
	/// </summary>
	/// <returns>int</returns>
	int getWidth() { return getAttributeInt("width"); };

	/// <summary>
	/// Get map height in tiles
	/// </summary>
	/// <returns>int </returns>
	int getHeight() { return getAttributeInt("height"); };

	/// <summary>
	/// Get tile width in pixels
	/// </summary>
	/// <returns>int</returns>
	int getTileWidth() { return getAttributeInt("tilewidth"); };

	/// <summary>
	/// Get tile height in pixels
	/// </summary>
	/// <returns>int</returns>
	int getTileHeight() { return getAttributeInt("tileheight"); };

#pragma endregion

	/// <summary>
	/// Load up tileSets from XML node
	/// </summary>
	/// <param name="node">Node to load TileSets from</param>
	void loadTileSets(rapidxml::xml_node<>* node);

	/// <summary>
	/// Load up layers from XML Node
	/// </summary>
	/// <param name="node">Node to load Layers from</param>
	void loadLayers(rapidxml::xml_node<>* node);

	/// <summary>
	/// Get reference to a TileSet
	/// </summary>
	/// <param name="tileSetName">Name of TileSet</param>
	/// <returns>TMXTileSet *</returns>
	TMXTileSet* getTileSet(std::string tileSetName);

	/// <summary>
	/// Get tile set that contains this tile ID
	/// </summary>
	/// <param name="tileID">Global ID for tile</param>
	/// <returns>TMXTileSet *</returns>
	TMXTileSet* getTileSetForTileID(int tileID);

	/// <summary>
	/// Get reference to a layer by name
	/// </summary>
	/// <param name="layerName">Name of layer</param>
	/// <returns>TMXLayer *</returns>
	TMXLayer* getLayer(std::string layerName);

private:
	std::vector<TMXTileSet> tileSets;
	std::vector<TMXLayer> layers;
	/// <summary>
	/// Load a TileSet from TSX file
	/// </summary>
	/// <param name="tileSet">TileSet to load into</param>
	/// <param name="filePath">Base folder for TSX file</param>
	void loadTileSet(TMXTileSet& tileSet, std::string filePath);
};