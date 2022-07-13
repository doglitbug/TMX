#include "TMXMap.h"

TMXMap::TMXMap() {}
TMXMap::~TMXMap() {}

void TMXMap::loadTileSets(rapidxml::xml_node<>* node)
{
	//Loop over all tileSet nodes and push them to tileSet Array
	for (rapidxml::xml_node<>* tileset_node = node->first_node("tileset"); tileset_node; tileset_node = tileset_node->next_sibling("tileset")) {
		TMXTileSet tmpTileSet;
		tmpTileSet.loadAttributes(tileset_node);

		//Go and load from tsx file if need be!
		if (tmpTileSet.getAttribute("source") != "") {
			//TODO Un-hardcode the filePath
			loadTileSet(tmpTileSet, "Assets/maps/");
		}

		tileSets.push_back(tmpTileSet);
	}
}

void TMXMap::loadTileSet(TMXTileSet& tileSet, std::string filePath)
{
	//Get file name from profile tileSet
	std::string fileName = tileSet.getAttribute("source");

	rapidxml::xml_document<> doc;
	rapidxml::xml_node<>* node;
	rapidxml::file<> file((filePath + fileName).c_str());
	doc.parse<0>(file.data());

	node = doc.first_node("tileset");
	tileSet.loadAttributes(node);

	//Load image
	tileSet.getImage()->loadAttributes(node->first_node("image"));

	//TODO Load tiles
}

void TMXMap::loadLayers(rapidxml::xml_node<>* node)
{
	//Loop over all tileSet nodes and push them to tileSet Array
	for (rapidxml::xml_node<>* layer_node = node->first_node("layer"); layer_node; layer_node = layer_node->next_sibling("layer")) {
		TMXLayer tmpLayer;
		tmpLayer.loadAttributes(layer_node);

		//Load data
		tmpLayer.loadData(layer_node->first_node("data"));

		layers.push_back(tmpLayer);
	}
}

TMXTileSet* TMXMap::getTileSet(std::string tileSetName)
{
	for (unsigned idx{ 0 }; idx < tileSets.size(); ++idx)
		if (tileSets[idx].getName() == tileSetName)
			return &tileSets[idx];
	return nullptr;
}

TMXTileSet* TMXMap::getTileSetForTileID(int tileID)
{
	//Step backwards through tileSets until we get the correct one
	for (int idx = tileSets.size() - 1; idx >= 0; idx--) {
		if (tileSets[idx].getAttributeInt("firstgid") <= tileID) {
			return &tileSets[idx];
		}
	}
	return nullptr;
}

TMXLayer* TMXMap::getLayer(std::string layerName)
{
	for (unsigned idx{ 0 }; idx < layers.size(); ++idx) {
		if (layers[idx].getName() == layerName) {
			return &layers[idx];
		}
	}
	return nullptr;
}
