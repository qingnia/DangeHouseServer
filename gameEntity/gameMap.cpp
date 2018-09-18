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

int gameMap::initPlayerList(int playerNum)
{
    for(int i = 0; i < playerNum; i++)
    {
        player p(i, this->id);
        this->playerList.push_back(p);
    }
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
        action startAct(atMove, *iter);
        this->actionList.push_back(startAct);

        action stopAct(atStop, *iter);
        this->actionList.push_back(stopAct);
	}

    action overAct(atOver);
    this->actionList.push_back(overAct);

    this->nextAction = this->actionList.begin();
    return 0;
}

gameMap::gameMap(int playerNum)
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

    this->height = 1;
    this->length = 100;
    this->widht = 100;

    int** ret = (int**)malloc(this->length * sizeof(int));
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->widht; j++) {
            ret[i] = (int*)malloc(this->widht * sizeof(int));
        }
    }
    ret[50][50] = 1;
    ret[51][50] = 2;
    ret[52][50] = 3;
    this->pos2room = ret;

    this->initPlayerList(playerNum);
}


room* gameMap::getRoom(position pos)
{

    int x = pos.x;
    int y = pos.y;
    int roomID = this->pos2room[x][y];

    map<int, room*>::iterator iter;
    iter = this->id2room.find(roomID);
    if (iter != this->id2room.end())
    {
        return iter->second;
    }

    room* newRoom = new room(roomID);
    this->id2room.insert(pair<int, room*>(roomID, newRoom));
    return nullptr;
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

int gameMap::run()
{
    action act = *(this->nextAction);
    player p = act.p;
	position pos;
    switch(act.at)
    {
    case atStart:
        break;
    case atMove:
		p.move();
        break;
    case atStop:
        break;
    case atOver:
        break;
    default:
        break;
    }
    return 0;
}

position gameMap::inputPosition()
{
    int x, y;
    cin>>x;
    cin>>y;
    return position(x, y);
}