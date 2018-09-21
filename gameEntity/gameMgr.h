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
	map<int, resItem*> id2Res;
	gameMgr();

	int mapIncrValue;


public:
	~gameMgr();
	static gameMgr* getGameMgr();

	gameMap* getMap(int mapID);
	gameMap* initNewMap(int playerNum);

	void update();
};

#endif