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

int player::excuteExam(examine exam)
{
	if (exam.et == etNone)
    {
        return 0;
    }
    exam.showMsg();
    list<int> diceNums = this->rollDice(exam.et);
    int score = accumulate(diceNums.begin(), diceNums.end(), 0);
    if(exam.attackValue > 0)
    {
        int compareNum = random(2 * exam.attackValue);
        if(score < compareNum)
        {
            this->excutePunish(exam.attackEffect);
        }
    }
    else
    {
        list<effect>::iterator iter;
        for (iter = exam.efList.begin(); iter != exam.efList.end(); iter++)
	    {
           effect ef = *iter;
           if (score >= ef.min & score <= ef.max)
           {
               this->excutePunish(ef);
               break;
           }
	    }
    }
	return 0;
}

int player::excutePunish(effect ef)
{
	stringstream ss;
	string efAttr = getETString(ef.et);
	ss << "你受到" << ef.eNum << "点" << efAttr << "损伤";
	logInfo(ss.str());
	ss.clear();

	examType attribute = ef.et;
    if (ef.et == etPhysicalDamage)
    {
        ss<<"你收到%d点物理损伤，请选择1:速度，2:力量";
		logInfo(ss.str());
        //选择
        attribute = etSpeed;
    }
    else if (ef.et == etMindDamage)
    {
        //选择
        attribute = etSpirit;
    }
    switch(attribute)
    {
    case etSpeed:
        this->incrSpeed(ef.eNum);
        break;
    case etStrength:
        this->incrStrength(ef.eNum);
        break;
    case etSpirit:
        this->incrSpirit(ef.eNum);
        break;
    case etKnowledge:
        this->incrKnowledge(ef.eNum);
        break;
    default:
        break;
    }
    return true;
}

int player::enterRoom(roomCard* room)
{
	if (room->needExam(mrtEnter))
	{
		this->excuteExam(room->cardExam);
	}
	return 0;
}

int player::leaveRoom(roomCard* room)
{
	if (room->needExam(mrtLeave))
	{
		this->excuteExam(room->cardExam);
	}
	return 0;
}

int player::passRoom(roomCard* room)
{
	if (room->needExam(mrtPass))
	{
		this->excuteExam(room->cardExam);
	}
	return 0;
}

int player::moveTo(direction dir)
{
	stringstream ss;

	gameMap* myMap = getMyMap(this->mapID);
	position* nextPos = (this->pos).getNeibourPos(dir);
	roomCard* nextRoom = myMap->getRoom(*nextPos);

	if (nextRoom == nullptr)
	{
		//玩家要走的位置没有房间
		//1.检查这个位置从当前房间能不能通过
		//2.如果能通过，则从牌库中拿到一个新房间
		//3.执行房间事件、考验、将新房间放进地图
		nextRoom = myMap->bindNewRoom(this->m_floor, *nextPos);
		if (nextRoom == nullptr)
		{
			//新房间也没，卡池已空
			return -2;
		}
		this->changeNewRoomRotation(dir, nextRoom);
		ss << "玩家进入新房间：" << nextRoom->getName() << "\n\t   " << nextRoom->getDesc();
		logInfo(ss.str());

		this->enterRoom(nextRoom);

		//进新房间要拿东西
		this->gainNewItem(nextRoom->type);
		//新房间的事件、考验等
		this->moveNum = this->m_speed;
	}
	else
	{
		direction revDir = reverseDir(dir);
		if (!nextRoom->canPass(revDir))
		{
			return -1;
		}
		this->moveNum++;
		ss << "这个房间已经被人开发过，可以进入，玩家速度："<<this->moveNum<<"房间名：" << nextRoom->getName() << "\n\t   " << nextRoom->getDesc();
		logInfo(ss.str());

		this->enterRoom(nextRoom);
		//这个位置已经有了房间
		//1.检查两个房间是否互通
		//如果互通，则通过，步数+1
		//执行房间内事件，如果遭遇敌人，步数再+1
		//检查步数，如果还未走完，则继续等待玩家输入
		this->moveNum++;
	}

	this->pos.x = nextPos->x;
	this->pos.y = nextPos->y;
	return 0;
}

int player::move()
{
	stringstream ss;
	ss<<"轮到玩家"<<this->getID()<<"移动,玩家速度："<<this->m_speed<<"当前移动步数："<<this->moveNum;
	logInfo(ss.str());
	ss.clear();
    //行动值在停止行动时清零
    //一次移动一格，移动距离达到速度停止
	while (this->moveNum < this->m_speed)
	{
		direction dir = this->inputDir();
		if (dir == dirStop)
		{
			break;
		}
		gameMap* myMap = getMyMap(this->mapID);
		roomCard* thisRoom = myMap->getRoom(this->pos);
		if (!thisRoom->canPass(dir))
		{
			return -1;
		}
		if (this->moveNum == 0)
		{
			this->leaveRoom(thisRoom);
		}
		else
		{
			this->passRoom(thisRoom);
		}

		this->moveTo(dir);
	}

	return 0;
}

int player::stop()
{
	//检查房间，看是否有停止时生效的

	//移动结束后把行动力恢复
	this->moveNum = 0;
	return 0;
}

int player::changeNewRoomRotation(direction fromDir, roomCard* room)
{
	direction dir = dirUp;
	while(! room->changeRotation(fromDir, dir))
	{
		if (room->canChangeRotation())
		{
			dir = this->inputDir();
		}
	}
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
		ss<<"房间类型为：事件\n\t     "<<newIssue->getName()<<"\n\t  "<<newIssue->getDesc();
		logInfo(ss.str());
		//一次性的考验直接不保存，如果是持续性的，需要保存状态
		//事件一定有考验
		this->excuteExam(newIssue->cardExam);
//		newIssue->cardExam.affect(*this);
		break;
	case ctRes:
		newRes = myMap->getNewRes();
		ss<<"房间类型为：物品\n\t     "<<newRes->getName()<<"\n\t  "<<newRes->getDesc();
		logInfo(ss.str());
		this->resList.push_back(newRes);
		break;
	case ctInfo:
		newInfo = myMap->getNewInfo();
		ss<<"房间类型为：预兆\n\t     "<<newInfo->getName()<<"\n\t  "<<newInfo->getDesc();
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