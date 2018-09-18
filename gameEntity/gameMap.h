//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef gameMap_h
#define gameMap_h

#include <stdio.h>
#include <map>
#include <vector>
#include "position.h"
#include "room.h"
#include "player.hpp"
#include "action.h"
#include "../utils/commonFun.h"

class gameMap{
    int id;
    int widht;
    int length;
    int height;

    list<action>::iterator nextAction;

    int** pos2room;

    map<int, room*> id2room;

    list<player> playerList;
    list<action> actionList;

    vector<int>::iterator roomIter, itemIter, issueIter, infoIter;
    vector<int>           roomList, itemList, issueList, infoList;

    int initPlayerList(int playerNum);
    int initActionList();
    int initCardList();

    //等待输入函数
    position inputPosition();
public:
	gameMap();
    gameMap(int playerNum);

    room* getRoom(position pos);
    room* getRoomByID(int roomID);
    player getPlayer(int id);

    room* getNewRoom(int floor, direction);

    int run();
};

#endif /* gameMap_h */