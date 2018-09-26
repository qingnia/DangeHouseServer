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
	int mapID;

    string name;
    int age;
    int m_id;
    
    int m_strength, m_speed, m_spirit, m_knowledge;
    list<resCard*> resList;
 //   list<infoCard*> infoList;
    list<int> skills;

    int moveNum;
    

public:
    player();
    player(int id, int mapID);

    int getID();
    int getStrength();
    int getSpeed();
    int getSpirit();
    int getKnowledge();
    int gainNewItem(configType);

    int incrSpeed(int), incrStrength(int), incrSpirit(int), incrKnowledge(int);

    int getRoom();

//    oper getOperate();
	int move();
    int stop();
    int attack(int id);
    int useSkill(int id);

    direction inputDir();
    list<int> rollDice(examType, int forceDiceNum = 0);
	int enterRoom(roomCard*);
	int leaveRoom(roomCard*);   //从上一回合进入，这一回合离开，是“离开房间”
    int passRoom(roomCard*);    //这一回合进入，这一回合离开，是“通过房间”
	int moveTo(direction);

    int excuteExam(examine);
    int excutePunish(effect);

    int changeNewRoomRotation(direction, roomCard*);

};

#endif /* player_hpp */
