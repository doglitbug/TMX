#include "TMXData.h"

TMXData::TMXData()
{
	rawData = "";
}

TMXData::~TMXData()
{
}

void TMXData::setRawData(std::string rawData)
{
	this->rawData = rawData;
	processRawData();
}

void TMXData::processRawData()
{
	std::string encoding = getAttribute("encoding");
	if (encoding.compare("csv") == 0) {
		processCSV();
	} else {
		std::cout << "Unknown encoding type" << std::endl;
	}
}

void TMXData::processCSV() {
	std::stringstream ss(rawData);
	while (ss.good())   // loop will continue if string stream is error free
	{
		std::string number;
		getline(ss, number, ',');
		data.push_back(stoi(number));
	}
}