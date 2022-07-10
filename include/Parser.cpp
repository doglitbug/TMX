#include "Parser.h"
#include <iostream>

dlb::Parser::Parser()
{
}

dlb::Parser::~Parser()
{
	//TODO Clear mapContainer
}

bool dlb::Parser::loadMap(std::string mapName,  std::string filename)
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
	mapContainer[mapName]->setMapAttributes(getAttributesFromNode(mapNode));
	//mapContainer[mapName]->loadTileSets(getAttributesFromNode(mapNode));
	
	return true;
}

TMXMap* dlb::Parser::getMap(std::string mapName)
{
	return mapContainer[mapName];
}

std::unordered_map<std::string, std::string> dlb::Parser::getAttributesFromNode(rapidxml::xml_node<>* node)
{
	std::unordered_map < std::string, std::string> output;

	for (rapidxml::xml_attribute<char>* attr = node->first_attribute(); attr; attr = attr->next_attribute())
	{
		output[attr->name()] = attr->value();
	}
	return output;
}
