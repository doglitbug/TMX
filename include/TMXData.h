#pragma once
#include "TMXNode.h"

class TMXData : public TMXNode
{
public:
	TMXData();
	~TMXData();

	/// <summary>
	/// Get raw data
	/// </summary>
	/// <returns>raw data</returns>
	std::string getRaw() { return data; };

	/// <summary>
	/// Set the raw data
	/// </summary>
	/// <param name="data">Data to set</param>
	void setRaw(std::string data);

private:
	/// <summary>
	/// Raw data from XML file
	/// </summary>
	std::string data;
};