//
//  main.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//

#include "gameMap.h"

gameMap::gameMap()
{
}

gameMap::~gameMap()
{
}

int gameMap::initPlayerList(int playerNum)
{
    char msg[128];
    sprintf(msg, "新地图生成，玩家一共%d人", playerNum);
    logInfo(msg);
    for(int i = 0; i < playerNum; i++)
    {
        player p(i, this->m_id);
        this->playerList.push_back(p);
    }
    return 0;
}

int gameMap::initCardList()
{
	map<int, map<string, string> >::iterator confIter;
    card* newCard;
	config* conf = config::getSingleConfig();
    
    //房间初始化
    this->roomList = myShuffle2List(conf->roomConfig.size());
    for(confIter = conf->roomConfig.begin(); confIter != conf->roomConfig.end(); confIter++)
    {
        this->id2room[confIter->first] = (card*) new roomCard(confIter->second);
    }
    this->roomIter = this->roomList.begin();
    
    //物品初始化
    this->resList = myShuffle2List(conf->resConfig.size());
    for(confIter = conf->resConfig.begin(); confIter != conf->resConfig.end(); confIter++)
    {
        this->id2res[confIter->first] = (card*) new resCard(confIter->second);
    }
    this->resIter = this->resList.begin();
    
    //事件初始化
    this->issueList = myShuffle2List(conf->issueConfig.size());
    for(confIter = conf->issueConfig.begin(); confIter != conf->issueConfig.end(); confIter++)
    {
        this->id2issue[confIter->first] = (card*) new issueCard(confIter->second);
    }
    this->issueIter = this->issueList.begin();
    
    this->infoList = myShuffle2List(conf->infoConfig.size());
	for (confIter = conf->infoConfig.begin(); confIter != conf->infoConfig.end(); confIter++)
	{
		this->id2info[confIter->first] = (card*) new infoCard(confIter->second);
	} 
    this->infoIter = this->infoList.begin();
    return 0;
}

int gameMap::initActionList()
{
    action act = action(atStart);
    this->actionList.push_back(act);
	list<player>::iterator iter;
	for (iter = playerList.begin();
		iter != playerList.end(); iter++)
	{
        //actionType at = move;
        action startAct(atMove, &(*iter));
        this->actionList.push_back(startAct);

        action stopAct(atStop, &(*iter));
        this->actionList.push_back(stopAct);
	}

    action overAct(atOver);
    this->actionList.push_back(overAct);

    this->nextAction = this->actionList.begin();
    return 0;
}

gameMap::gameMap(int playerNum, int mapID)
{
    if(this->pos2room[50][50])
    {
		return;
    }

    if (playerNum == 0)
    {
        //错误处理
    }
    //x,y是坐标,楼梯位置是（50，50）
    //为了保证可用，地图大小100*100
    //大厅看作连通的两个房间加上楼梯

    this->m_height = 1;
    this->m_length = 100;
    this->m_width = 100;
	this->m_id = mapID;

	/**
    int** ret = (int**)malloc(this->m_length * sizeof(int));
    for (int i = 0; i < this->m_length; i++) {
        for (int j = 0; j < this->m_width; j++) {
            ret[i] = (int*)malloc(this->m_width * sizeof(int));
        }
    }
	
	for (int i = 0; i < this->m_length; i++)
	{
		this->pos2room[i] = map<int, int> newMap(50);
	}
	*/
	this->pos2room[50][50] = 1;
	this->pos2room[51][50] = 2;
	this->pos2room[52][50] = 3;
    //ret[50][50] = 1;
    //ret[51][50] = 2;
    //ret[52][50] = 3;
    //this->pos2room = ret;
    this->initPlayerList(playerNum);
    this->initCardList();
	this->initActionList();
}

roomCard* gameMap::getRoomByID(int roomID)
{
    map<int, card*>::iterator iter;
    iter = this->id2room.find(roomID);
    if (iter != this->id2room.end())
    {
        return dynamic_cast<roomCard*>(iter->second);
    }
    return nullptr;
}

roomCard* gameMap::getRoom(position pos)
{
    int x = pos.x;
    int y = pos.y;
    int roomID = this->pos2room[x][y];

    return this->getRoomByID(roomID);
    //roomCard* newRoom = new roomCard(roomID);
    //this->id2room.insert(pair<int, roomCard*>(roomID, newRoom));
    //return nullptr;
}

player gameMap::getPlayer(int id)
{
    list<player>::iterator iter;
    for(iter = this->playerList.begin(); iter != this->playerList.end(); iter++)
    {
        if ((*iter).getID() == id)
        {
            return *iter;
        }
    }
    //错误处理
    //todo
	return player();
}

roomCard* gameMap::bindNewRoom(int floor, position pos)
{
    roomCard* newRoom;
    while(true)
    {
		int roomID = this->roomList.front();
		this->roomList.pop_front();
		newRoom = this->getRoomByID(roomID);
		if (in_vector(floor, newRoom->suiteLayer))
		{
			this->pos2room[pos.x][pos.y] = roomID;
			break;
		}
		this->roomList.push_back(roomID);
    }
    return newRoom;
}

issueCard* gameMap::getNewIssue()
{
    issueCard* newIssue;
	int issueID = this->issueList.front();
	this->issueList.pop_front();
    
    config* conf = config::getSingleConfig();
    map<string, string> issueConfig = conf->getConfig(ctIssue, issueID);
    newIssue = new issueCard(issueConfig);
    return newIssue;
}

infoCard* gameMap::getNewInfo()
{
    infoCard* newInfo;
	int infoID = this->infoList.front();
	this->infoList.pop_front();
    
    config* conf = config::getSingleConfig();
    map<string, string> infoConfig = conf->getConfig(ctInfo, infoID);
    newInfo = new infoCard(infoConfig);
    return newInfo;
}

resCard* gameMap::getNewRes()
{
	resCard* newRes;
	int infoID = this->resList.front();
	this->resList.pop_front();

	config* conf = config::getSingleConfig();
	map<string, string> resConfig = conf->getConfig(ctInfo, infoID);
	newRes = new resCard(resConfig);
	return newRes;
}

bool gameMap::getReality(player p1)
{
    if (this->m_process > 0)
    {
        return true;
    }
    //cout<<"尝试揭露真相吧"<<endl;
    int infoNum = this->m_infoNum;
    list<int> diceNums = p1.rollDice(etNone, infoNum);
    int score = accumulate(diceNums.begin(), diceNums.end(), 0);
    if (score > 6)
    {
        this->m_process++;
        return true;
    }
    return false;
}

//用action作回调，实际效果不好，还不如轮流查询。
//中间状态作用于其他人身上，会作为补充询问在中间某个流程内发起，不影响整体流程
//如万箭齐发，作为格外流程处理
int gameMap::run()
{
	stringstream ss;
    action act = *(this->nextAction);
    player* p = act.p;
	position pos;
    char msg[128];
    switch(act.at)
    {
    case atStart:
		ss << "新一轮开始，开始阶段："; 
		logInfo(ss.str());
        break;
    case atMove:
		p->move();
        break;
    case atStop:
		p->stop();
        break;
    case atOver:
		ss << "本轮结束";
		logInfo(ss.str());
		this->initActionList();
        break;
    default:
        break;
    }
	this->nextAction++;
    return 0;
}

position gameMap::inputPosition()
{
    int x, y;
    cin>>x;
    cin>>y;
    return position(x, y);
}