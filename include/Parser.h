#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

#include "TMXMap.h"

#define DEBUG true

class Parser
{
public:
	Parser();
	~Parser();

	bool loadMap(std::string mapName, std::string filename);
	/// <summary>
	/// Get a reference to a map with the provided name
	/// </summary>
	/// <param name="mapName">Name of map</param>
	/// <returns>nullptr if not found</returns>
	TMXMap* getMap(std::string mapName);

private:
	/// <summary>
	/// Container for loaded maps
	/// </summary>
	std::unordered_map<std::string, TMXMap*> mapContainer;
};