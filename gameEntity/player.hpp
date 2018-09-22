﻿//
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

struct oper{
	direction dir;
    char input;
    position pos;

public:
    oper(char c)
    {
        this->input = c;
    }
    oper(position pos)
    {
        this->pos = pos;
    }
};

class gameMgr;
using namespace std;
class player {

    int floor;
    position pos;
	int mapID;

    string name;
    int age;
    int id;

    int strength, speed, spirit, knowledge;
    list<int> items;
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

    int getRoom();

//    oper getOperate();
	int move();
    int stop();
    int attack(int id);
    int useSkill(int id);

    direction inputDir();
	void enterNewRoom(room*);

};

#endif /* player_hpp */
