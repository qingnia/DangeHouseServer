//
//  player.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/11.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include "position.h"

#include "../utils/diyType.h"
#include "resCard.h"
#include "roomCard.h"
#include "infoCard.hpp"

class gameMgr;
using namespace std;
class player {

    int m_floor;
    position pos;

    string name;
    int age;
    int m_id, mapID, m_roleID;
    
    map<examType, int> et2level;
    map<examType, vector<int> > etLevel2value;
    list<resCard*> resList;
 //   list<infoCard*> infoList;
    list<int> skills;

    int moveNum;

    int gainNewItem(configType);

    int incrETLevel(examType, int);
    int getETValue(examType);
public:
    player();
    player(int roleID, int mapID, map<string, string>);

    int getID();
    roomCard* getMyRoom();

//    oper getOperate();
    int start();
	int move();
    int stop();

    int attack(int id);
    int useSkill(int id);

    direction inputDir();
    list<int> rollDice(examType, int forceDiceNum = 0);
	bool enterRoom(roomCard*);
	bool leaveRoom(roomCard*);   //从上一回合进入，这一回合离开，是“离开房间”
    bool passRoom(roomCard*);    //这一回合进入，这一回合离开，是“通过房间”
    int moveTo(direction);

    int excuteExam(examine);
    int excutePunish(effect);

    bool gainBuff(cardUseType, card*);

    bool getReality();

    int changeNewRoomRotation(direction, roomCard*);

};

#endif /* player_hpp */
