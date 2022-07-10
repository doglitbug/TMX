#include "Parser.h"
#include "TMXUtils.h"
#include <iostream>

Parser::Parser()
{
}

Parser::~Parser()
{
	//TODO Clear mapContainer
}

bool Parser::loadMap(std::string mapName,  std::string filename)
{
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<>* mapNode;
	rapidxml::file<> file(filename.c_str());
	doc.parse<0>(file.data());

	//Get root node "map"
	mapNode = doc.first_node("map");

	//And new map to the mapContainer
	mapContainer[mapName] = new TMXMap();

	//Load the maps data

	//Load map
	mapContainer[mapName]->setMapAttributes(TMXUtils::getAttributesFromNode(mapNode));
	//mapContainer[mapName]->loadTileSets(getAttributesFromNode(mapNode));
	
	return true;
}

TMXMap* Parser::getMap(std::string mapName)
{
	return mapContainer[mapName];
}