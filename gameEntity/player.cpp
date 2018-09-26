//
//  player.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/11.
//

#include "player.hpp"
#include "gameMgr.h"
#include "gameMap.h"

/***************************内部常用函数**********************************/
gameMap* getMyMap(int mapID)
{
	gameMgr* gm = gameMgr::getGameMgr();
	gameMap* myMap = gm->getMap(mapID);
	return myMap;
}

/***************************内部常用函数**********************************/
player::player()
{
	this->moveNum = 0;
	this->m_floor = 1;
    this->pos = position(50, 50);
}

player::player(int id, int mapID)
{
	stringstream ss;
	ss<<"初始化玩家"<<id<<"玩家速度："<<4<<"，力量："<<3<<"，知识："<<4<<"精神："<<4;
	logInfo(ss.str());
	this->moveNum = 0;
	this->mapID = mapID;
    this->m_id = id;
    this->m_strength = 3;
    this->m_speed = 4;
    this->m_knowledge = 4;
    this->m_spirit = 4;
	this->m_floor = 1;
    this->pos = position(50, 50);
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
		dir = dirUp;
        break;
    case 's':
		dir = dirDown;
        break;
    case 'a':
		dir = dirLeft;
        break;
    case 'd':
		dir = dirRight;
        break;
    default:
        break;
    }
    return dir;
}

list<int> player::rollDice(examType et, int forceDiceNum)
{
	int diceNum;
	switch(et)
	{
	case etSpeed:
		diceNum = this->m_speed;
		break;
	case etStrength:
		diceNum = this->m_strength;
		break;
	case etSpirit:
		diceNum = this->m_spirit;
		break;
	case etKnowledge:
		diceNum = this->m_knowledge;
		break;
	default:
		diceNum = forceDiceNum;
		//todo 错误处理
		break;
	};
	stringstream ss;
	ss<<"掷骰子，骰子数量为："<<diceNum<<"，每个骰子点数分别为：";
	list<int> diceNums(diceNum);
	for(int i = 0; i < diceNum; i++)
	{
		int num = random(2);
		ss<<num<<",  ";
		diceNums.push_back(num);
	}
	ss<<"掷骰结束。";
	logInfo(ss.str());
	return diceNums;
}

int player::move()
{
	stringstream ss;
	ss<<"轮到玩家"<<this->getID()<<"移动,玩家速度："<<this->m_speed<<"当前移动步数："<<this->moveNum;
	logInfo(ss.str());
	ss.clear();
    //行动值在停止行动时清零
    //一次移动一格，移动距离达到速度停止
    if (this->moveNum >= this->m_speed)
    {
        return -1;
    }

	direction dir = this->inputDir();

	gameMap* myMap = getMyMap(this->mapID);
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
        nextRoom = myMap->getNewRoom(this->m_floor, dir);
        if (nextRoom == nullptr)
        {
            //新房间也没，卡池已空
            return -2;
        }
		ss << "玩家进入新房间：" << nextRoom->getName() << "\n\t," << nextRoom->getDesc();
		logInfo(ss.str());
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
	gameMap* myMap = getMyMap(this->mapID);
	issueCard* newIssue;
	resCard* newRes;
	infoCard* newInfo;

	stringstream ss;
	switch (ct)
	{
	case ctIssue:
		newIssue = myMap->getNewIssue();
		ss<<"房间类型为：事件/n/t     "<<newIssue->getName()<<"/n/t  "<<newIssue->getDesc();
		logInfo(ss.str());
		//一次性的考验直接不保存，如果是持续性的，需要保存状态
//		newIssue->cardExam.affect(*this);
		break;
	case ctRes:
		newRes = myMap->getNewRes();
		ss<<"房间类型为：物品/n/t     "<<newRes->getName()<<"/n/t  "<<newRes->getDesc();
		logInfo(ss.str());
		this->resList.push_back(newRes);
		break;
	case ctInfo:
		newInfo = myMap->getNewInfo();
		ss<<"房间类型为：预兆/n/t     "<<newInfo->getName()<<"/n/t  "<<newInfo->getDesc();
		logInfo(ss.str());
		//如果不是作祟阶段，需要进行揭露真相
		break;
	default:
		break;
	};
	return 0;
}

int player::getID()
{
    return this->m_id;
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