#include "TMXLayer.h"

TMXLayer::TMXLayer() {
	data = new TMXData();
}
TMXLayer::~TMXLayer() {}

int TMXLayer::getData(int tx, int ty)
{
	int width = getAttributeInt("width");
	int height = getAttributeInt("height");
	//TODO Check for out of bounds

	return data->getData(ty * width + ty);
}

void TMXLayer::loadData(rapidxml::xml_node<>* node)
{
	data->loadAttributes(node);
	data->setRawData(node->value());
}