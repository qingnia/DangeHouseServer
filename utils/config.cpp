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

bool config::initRoomConfig()
{
	//readCsvData("../")
}
map<int, string> config::getRoomConfig()
{

}