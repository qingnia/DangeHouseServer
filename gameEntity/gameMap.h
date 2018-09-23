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
#include "roomCard.h"
#include "issueCard.h"
#include "resCard.h"
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

    map<int, card*> id2room, id2issue, id2res, id2info;

    list<player> playerList;
    list<action> actionList;

    vector<int>::iterator roomIter, resIter, issueIter, infoIter;
    vector<int>           roomList, resList, issueList, infoList;

    int initPlayerList(int playerNum);
    int initActionList();
    int initCardList();

    //等待输入函数
    position inputPosition();
public:
	gameMap();
    gameMap(int playerNum);

    roomCard* getRoom(position pos);
    roomCard* getRoomByID(int roomID);
    player getPlayer(int id);

    roomCard* getNewRoom(int floor, direction);
	class resCard* getNewRes();
    class issueCard* getNewIssue();



    int run();
};

#endif /* gameMap_h */