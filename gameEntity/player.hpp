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
#include "gameMap.h"
#include "../utils/diyType.h"
#include "resCard.h"
#include "roomCard.h"

class gameMgr;
using namespace std;
class player {

    int floor;
    position pos;
	int mapID;

    string name;
    int age;
    int id;

    int m_strength, m_speed, m_spirit, m_knowledge;
    list<resCard*> resList;
 //   list<infoCard*> infoList;
    list<int> skills;

    int moveNum;
    
    gameMap* getMyMap();
public:
    player();
    player(int id, int mapID);

    int getID();
    int getStrength();
    int getSpeed();
    int getSpirit();
    int getKnowledge();
    int gainNewItem(configType);

    int getRoom();

//    oper getOperate();
	int move();
    int stop();
    int attack(int id);
    int useSkill(int id);

    direction inputDir();
    list<int> excuteExam(examType);
	void enterNewRoom(roomCard*);

};

#endif /* player_hpp */
