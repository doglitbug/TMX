#include "TMXLayer.h"

TMXLayer::TMXLayer() {
	data = new TMXData();
}
TMXLayer::~TMXLayer() {}

void TMXLayer::loadData(rapidxml::xml_node<>* node)
{
	data->loadAttributes(node);
	data->setRaw(node->value());
}
