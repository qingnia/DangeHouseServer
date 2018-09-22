//
//  player.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/11.
//

#include "player.hpp"
#include "gameMgr.h"

player::player()
{
    this->pos = position(50, 50);
}

player::player(int id, int mapID)
{
	this->mapID = mapID;
    this->id = id;
    this->strength = 3;
    this->speed = 4;
    this->knowledge = 4;
    this->spirit = 4;
    this->pos = position(50, 50);
}

int player::getStrength()
{
    return this->strength;
}

direction player::inputDir()
{
    cout<<"输入：上w,下s,左a,右d"<<endl;

    char input;
    cin>>input;

	direction dir;
    switch(input)
    {
    case 'w':
		dir = up;
        break;
    case 's':
		dir = down;
        break;
    case 'a':
		dir = direction::left;
        break;
    case 'd':
		dir = direction::right;
        break;
    default:
        break;
    }
    return dir;
}

int player::move()
{
    //行动值在停止行动时清零
    //一次移动一格，移动距离达到速度停止
    if (this->moveNum >= this->speed)
    {
        return -1;
    }

	direction dir = this->inputDir();

	gameMgr* gm = gameMgr::getGameMgr();
	gameMap* myMap = gm->getMap(this->mapID);
	room* thisRoom = myMap->getRoom(this->pos);
	if (!thisRoom->canPass(dir))
	{
		return -1;
	}
	position* nextPos = (this->pos).getNeibourPos(dir);
	room* nextRoom = myMap->getRoom(*nextPos);
	direction revDir = reverseDir(dir);
    if (nextRoom == nullptr)
	{
		//玩家要走的位置没有房间
		//1.检查这个位置从当前房间能不能通过
		//2.如果能通过，则从牌库中拿到一个新房间
		//3.执行房间事件、考验、将新房间放进地图
        nextRoom = myMap->getNewRoom(this->floor, dir);
        if (nextRoom == nullptr)
        {
            //新房间也没，卡池已空
            return -2;
        }
		//进新房间要拿东西
		this->gainNewItem(nextRoom->type);
        //新房间的事件、考验等
	}
	else
	{
		//这个位置已经有了房间
		//1.检查两个房间是否互通
		//如果互通，则通过，步数+1
		//执行房间内事件，如果遭遇敌人，步数再+1
		//检查步数，如果还未走完，则继续等待玩家输入
	}

    this->moveNum++;
    this->pos.x = pos.x;
    this->pos.y = pos.y;
	return 0;
}

int player::stop()
{
	return 0;
}

int player::gainNewItem(configType ct)
{
	switch (ct)
	{
	case issueCard:
		break;
	case resCard:
		break;
	case infoCard:
		break;
	default:
		break;
	}
}

int player::getID()
{
    return this->id;
}