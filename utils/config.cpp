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

fileConfig getConfig(configType type)
{
	fileConfig fc;
	switch (type)
	{
	case roomCard:
		break;
	case issueCard:
		break;
	case itemCard:
		break;
	case infoCard:
		break;
	default:
		break;
	}
	return fc;
}

bool config::initRoomConfig()
{
	//string filename=
	//readCsvData("")
	return false;
}
map<int, string> config::getRoomConfig()
{
	map<int, string> myMap;
	return myMap;
}