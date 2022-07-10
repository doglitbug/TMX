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
		if (tmpTileSet.GetAttribute("source") != "") {
			//TODO Un-hardcode the filePath
			loadTileSet(tmpTileSet, "Assets/maps/");
		}

		tileSets.push_back(tmpTileSet);
	}
}

TMXTileSet* TMXMap::getTileSet(std::string tileSetName)
{
	for (unsigned idx{ 0 }; idx < tileSets.size(); ++idx)
		if (tileSets[idx].getName() == tileSetName)
			return &tileSets[idx];
	return nullptr;
}

void TMXMap::loadTileSet(TMXTileSet &tileSet, std::string filePath)
{
	//Get file name from profile tileSet
	std::string fileName = tileSet.GetAttribute("source");

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
