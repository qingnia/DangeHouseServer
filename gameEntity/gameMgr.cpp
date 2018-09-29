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

map<int, int> gameMgr::choosePart(vector<int> roleIDList)
{
	map<int, int> roleID2Character;
	stringstream ss;
	config* conf = config::getSingleConfig();
	list<int> leftPartList = myShuffle2List(conf->playerConfig.size());
	vector<int>::iterator roleIter;
	list<int>::iterator partIter = leftPartList.end();
	for(roleIter = roleIDList.begin(); roleIter != roleIDList.end(); roleIter++)
	{
		string leftChara = list2String(leftPartList);
		ss<< "剩余可选人物：" << leftChara;
		logInfo(ss.str());
		ss.str("");
		int num;
		while(partIter != leftPartList.end());
		{
			cin>>num;
			partIter = find(leftPartList.begin(), leftPartList.end(), num);
		}
		roleID2Character[*roleIter] = num;
		leftPartList.erase(partIter);
		partIter = leftPartList.end();
	}
	return roleID2Character;
}

gameMap* gameMgr::initNewMap(vector<int> roleIDList)
{
	gm->mapIncrValue++;
	map<int, int> roleID2Part = this->choosePart(roleIDList);	
	gameMap* newMap = new gameMap(gm->mapIncrValue, roleID2Part);
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
