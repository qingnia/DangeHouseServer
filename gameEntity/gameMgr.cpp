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

gameMap* gameMgr::getMap(int32_t mapID)
{
	map<int32_t, gameMap*>::iterator iter;
	iter = this->id2Map.find(mapID);
	if (iter != this->id2Map.end())
	{
		return iter->second;
	}

	//错误处理
	return nullptr;
}

player gameMgr::getPlayer(int32_t roleID)
{
	int32_t mapID = roleID2MapID[roleID];
	gameMap* map = getMap(mapID);
	player p = map->getPlayer(roleID);
	return p;
}

int32_t gameMgr::getPlayerByHandle(int64_t handle, player& p)
{
	map<int64_t, int32_t>::iterator iter = this->handle2Role.find(handle);
	if (iter == this->handle2Role.end())
	{
		return -1;
	}
	p = getPlayer(iter->second);
	return 0;
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
		while(partIter != leftPartList.end())
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

int32_t gameMgr::roleLogin(int32_t roleID, int32_t mapID, int64_t handle)
{
	roleID2MapID[roleID] = mapID;
	gameMap* map = getMap(mapID);
	int ret = map->addNewPlayer(roleID);
	
	role2Handle[roleID] = handle;
	return 0;
}
	
int32_t gameMgr::modifyStatus(int64_t handle, int32_t cmd)
{
	player p = player();
	int32_t ret = getPlayerByHandle(handle, p);
	p.modifyStatus(cmd);
	return 0;
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
