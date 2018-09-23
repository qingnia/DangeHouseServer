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
    this->m_strength = 3;
    this->m_speed = 4;
    this->m_knowledge = 4;
    this->m_spirit = 4;
    this->pos = position(50, 50);
}

gameMap* player::getMyMap()
{
	gameMgr* gm = gameMgr::getGameMgr();
	gameMap* myMap = gm->getMap(this->mapID);
	return myMap;
}

int player::getStrength()
{
    return this->m_strength;
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

list<int> player::excuteExam(examType et)
{
	int diceNum;
	switch(et)
	{
	case speed:
		diceNum = this->m_speed;
		break;
	case strength:
		diceNum = this->m_strength;
		break;
	case spirit:
		diceNum = this->m_spirit;
		break;
	case knowledge:
		diceNum = this->m_knowledge;
		break;
	default:
		//todo 错误处理
		break;
	};
	list<int> diceNums(diceNum);
	for(int i = 0; i < diceNum; i++)
	{
		int num = random(2);
		diceNums.push_back(num);
	}
	return diceNums;
}

int player::move()
{
    //行动值在停止行动时清零
    //一次移动一格，移动距离达到速度停止
    if (this->moveNum >= this->m_speed)
    {
        return -1;
    }

	direction dir = this->inputDir();

	gameMap* myMap = this->getMyMap();
	roomCard* thisRoom = myMap->getRoom(this->pos);
	if (!thisRoom->canPass(dir))
	{
		return -1;
	}
	position* nextPos = (this->pos).getNeibourPos(dir);
	roomCard* nextRoom = myMap->getRoom(*nextPos);
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
	gameMap* myMap = this->getMyMap();
	issueCard* newIssue;
	resCard* newRes;
	switch (ct)
	{
	case issue:
		newIssue = myMap->getNewIssue();
		break;
	case res:
		newRes = myMap->getNewRes();
		this->resList.push_back(newRes);
		break;
	case info:
		break;
	default:
		break;
	};
	return 0;
}

int player::getID()
{
    return this->id;
}

int player::incrSpeed(int num)
{
	this->m_speed += num;
	if (this->m_speed <= 0)
	{
		//死亡
	}
	return this->m_speed;
}

int player::incrStrength(int num)
{
	this->m_strength += num;
	if (this->m_strength <= 0)
	{
		//死亡
	}
	return this->m_strength;
}

int player::incrSpirit(int num)
{
	this->m_spirit += num;
	if(this->m_spirit <= 0)
	{
		//死亡
	}
	return this->m_spirit;
}

int player::incrKnowledge(int num)
{
	this->m_knowledge += num;
	if(this->m_knowledge <= 0)
	{
		//死亡
	}
	return this->m_knowledge;
}