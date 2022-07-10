#pragma once

#include <string>
#include <unordered_map>

class TMXMap
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
	/// Set map attributes in bulk from Parser
	/// </summary>
	/// <param name="attributes">Attributes</param>
	void setMapAttributes(std::unordered_map<std::string, std::string> attributes);
	
	/// <summary>
	/// Get an attribute value
	/// </summary>
	/// <param name="attributeName">Name of attribute</param>
	/// <returns>String</returns>
	std::string GetAttribute(std::string attributeName);

	/// <summary>
	/// Get an attribute value
	/// </summary>
	/// <param name="attributeName">Name of attribute</param>
	/// <returns>int</returns>
	int GetAttributeInt(std::string attributeName);

private:
	std::unordered_map<std::string, std::string> attributes;
	std::unordered_map<std::string, std::string> tileSets;
	std::unordered_map<std::string, std::string> layers;
};