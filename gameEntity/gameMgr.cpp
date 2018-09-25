//
//  gameMgr.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/17.
//

#include "gameMgr.h"

gameMgr* gameMgr::gm = new gameMgr();

gameMgr::gameMgr()
{
	this->mapIncrValue = 0;
}

gameMgr::~gameMgr()
{
}

gameMgr* gameMgr::getGameMgr()
{
	return gm;
}

gameMap* gameMgr::getMap(int mapID)
{
	map<int, gameMap*>::iterator iter;
	iter = this->id2Map.find(mapID);
	if (iter != this->id2Map.end())
	{
		return iter->second;
	}

	//错误处理
	return nullptr;
}

gameMap* gameMgr::initNewMap(int playerNum)
{
	gm->mapIncrValue++;
	gameMap* newMap = new gameMap(playerNum, gm->mapIncrValue);
	gm->id2Map.insert(pair<int, gameMap*>(gm->mapIncrValue, newMap));
	
	return nullptr;
}

void gameMgr::update()
{
	map<int, gameMap*>::iterator iter;
	for (iter = gm->id2Map.begin(); iter != gm->id2Map.end(); iter++)
	{
		gameMap* thisMap = iter->second;
		thisMap->run();
	}

	return;
}
