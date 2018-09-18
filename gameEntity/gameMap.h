//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef gameMap_h
#define gameMap_h

#include <stdio.h>
#include "position.h"
#include "room.h"
#include "player.hpp"
#include "action.h"
#include <map>

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

    int initPlayerList(int playerNum);
    int initActionList();

    //等待输入函数
    position inputPosition();
public:
	gameMap();
    gameMap(int playerNum);

    room* getRoom(position pos);
    player getPlayer(int id);

    int run();
};

#endif /* gameMap_h */