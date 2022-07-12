#pragma once
#include "TMXNode.h"
#include <iostream>
#include <sstream>

class TMXData : public TMXNode
{
public:
	TMXData();
	~TMXData();

	/// <summary>
	/// Get raw data
	/// </summary>
	/// <returns>raw data</returns>
	std::string getRawData() { return rawData; };
	int getData(int i) { return data[i]; };

	/// <summary>
	/// Set the raw data
	/// </summary>
	/// <param name="data">Data to set</param>
	void setRawData(std::string rawData);

private:
	/// <summary>
	/// Process raw data into a 1d array
	/// </summary>
	void processRawData();
	void processCSV();

	/// <summary>
	/// Raw data from XML file
	/// </summary>
	std::string rawData;

	/// <summary>
	/// Processed data
	/// </summary>
	std::vector<int> data;
};