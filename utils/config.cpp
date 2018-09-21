//
//  config.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/19.
//

#include "config.h"

config* config::gameConfig = new config();
config::config()
{
}

config::~config()
{
}

config* config::getSingleConfig()
{
	if (gameConfig == nullptr)
	{
		gameConfig = new config();
	}
	return gameConfig;
}

map<string, string> config::getConfig(configType type, int id)
{
	//map<string, string> fc;
	map<int, map<string, string>>::iterator iter;
	switch (type)
	{
	case roomCard:
		if (this->roomConfig.size() <= 0)
		{
			this->roomConfig = readCsvData("../tables/Room.csv");
		}
		iter = this->roomConfig.find(id);
		if (iter != this->roomConfig.end())
		{
			return iter->second;
		}
		//fc.fname = "../config/Room.csv";
		//fc.kvMap[string("Name")] = stringDesc;
		//fc.kvMap[string("enlishName")] = stringDesc;
		//fc.kvMap[string("layer")] = vectorInt;
		//fc.kvMap[string("type")] = numberInt;
		//this->roomConfig = loadConfig(fc);
		break;
	case issueCard:
		break;
	case resCard:
		break;
	case infoCard:
		break;
	default:
		break;
	}
	return iter->second;
}
