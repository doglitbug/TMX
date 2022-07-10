#include "TMXMap.h"

TMXMap::TMXMap()
{
}

TMXMap::~TMXMap()
{
}

void TMXMap::loadTileSets(rapidxml::xml_node<>* node)
{
	//Loop over all tileSet nodes and push them to tileSet Array
    for (rapidxml::xml_node<>* tileset_node = node->first_node("tileset"); tileset_node; tileset_node = tileset_node->next_sibling("tileset")) {
        TMXTileSet tmpTileSet;
        tmpTileSet.loadAttributes(tileset_node);

        //TODO Go and load from tsx file if need be!
        if (tmpTileSet.GetAttribute("source") != "") {
            std::cout << "Need to load TSX file: " << tmpTileSet.GetAttribute("source") << std::endl;
        }
        tileSets.push_back(tmpTileSet);
    }
}

TMXTileSet *TMXMap::getTileSet(std::string tileSetName)
{
    for (unsigned idx{ 0 }; idx < tileSets.size(); ++idx)
        if (tileSets[idx].getName() == tileSetName)
            return &tileSets[idx];
    return nullptr;
}
