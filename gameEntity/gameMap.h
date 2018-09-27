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
#include "infoCard.hpp"
#include "player.hpp"
#include "action.h"
#include "../utils/commonFun.h"

class gameMap{
    int m_id, m_width, m_length, m_height, m_infoNum, m_process;
    
    list<action>::iterator nextAction;

    //int** pos2room;
	map<int, map<int, int> > pos2room;

    map<int, card* > id2room, id2issue, id2res, id2info;

    list<player> playerList;
    list<action> actionList;

    list<int>::iterator roomIter, resIter, issueIter, infoIter;
    list<int>           roomList, resList, issueList, infoList;

    int initPlayerList(int playerNum);
    int initActionList();
    int initCardList();

    //等待输入函数
    position inputPosition();
public:
	gameMap();
    gameMap(int playerNum, int mapID);

    roomCard* getRoom(position pos);
    roomCard* getRoomByID(int roomID);
    player getPlayer(int id);

    roomCard* bindNewRoom(int floor, position pos);
	resCard* getNewRes();
    issueCard* getNewIssue();
    infoCard* getNewInfo();

    int run();


    int getInfoNum();
    int getProcess();
    int incrProcess();
    
	~gameMap();
};

#endif /* gameMap_h */