#include "TMXData.h"

TMXData::TMXData()
{
	data = "";
}

TMXData::~TMXData()
{
}

void TMXData::setRaw(std::string data)
{
	this->data = data;
}
