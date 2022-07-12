#pragma once

#include "TMXNode.h"
#include "TMXData.h"

class TMXLayer : public TMXNode
{
public:
	TMXLayer();
	~TMXLayer();

	/// <summary>
	/// Get layer name
	/// </summary>
	/// <returns>std::string</returns>
	std::string getName() { return getAttribute("name"); };

	/// <summary>
	/// Return reference to the data
	/// </summary>
	/// <returns>TMXData *</returns>
	TMXData *getData() { return data; };
	void loadData(rapidxml::xml_node<>* node);

private:	
	TMXData* data;
};
