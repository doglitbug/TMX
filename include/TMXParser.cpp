#include "TMXParser.h"
#include <iostream>

TMXParser::TMXParser()
{
}

TMXParser::~TMXParser()
{
	//TODO Clear mapContainer
}

bool TMXParser::loadMap(std::string mapName,  std::string filename)
{
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<>* mapNode;
	rapidxml::file<> file(filename.c_str());
	doc.parse<0>(file.data());

	//TODO Deal with multiple maps in file, if this is a thing?
	
	//Get root node "map"
	mapNode = doc.first_node("map");

	//And new map to the mapContainer
	mapContainer[mapName] = new TMXMap();

	//Load map
	mapContainer[mapName]->loadAttributes(mapNode);
	mapContainer[mapName]->loadTileSets(mapNode);
	mapContainer[mapName]->loadLayers(mapNode);

	//TODO Free up rapidXML stuff
	return true;
}

TMXMap* TMXParser::getMap(std::string mapName)
{
	//TODO Search for map, return error if not found
	return mapContainer[mapName];
}