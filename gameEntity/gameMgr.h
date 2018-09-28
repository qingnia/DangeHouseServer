//
//  gameMgr.h
//  testC
//
//  Created by 陈帅 on 2018/9/17.
//

#ifndef gameMgr_h
#define gameMgr_h

#include <stdio.h>
#include <map>
#include "gameMap.h"

class gameMgr
{
private:
	static gameMgr* gm;
	map<int, gameMap*> id2Map;
	gameMgr();

	int mapIncrValue;

	map<int, int> choosePart(vector<int> roleIDList);
public:
	~gameMgr();
	static gameMgr* getGameMgr();

	gameMap* getMap(int mapID);
	gameMap* initNewMap(vector<int> roleIDList);

	void update();
};

#endif