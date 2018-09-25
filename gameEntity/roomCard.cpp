//
//  main.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//

#include "roomCard.h"

roomCard::roomCard()
{

}

roomCard::~roomCard()
{
}

roomCard::roomCard(map<string, string> roomConfig)
{
	//config* conf = config::getSingleConfig();
	//map<string, string> roomConfig = conf->getConfig(roomCard, id);

	map<string, string>::iterator iter;
	string key, value;
	for (iter = roomConfig.begin(); iter != roomConfig.end(); iter++)
	{
		key = iter->first;
		value = iter->second;
		if (key == "name")
		{
			this->m_name = value;
		}
		else if(key == "enlishName")
		{
			this->m_enlishName = value;
		}
		else if (key == "layer")
		{
			this->suiteLayer = split<int>(value, "|");
		}
		else if (key == "canPassArray")
		{
			this->exportArray = split<int>(value, "|");
		}
		else if (key == "type")
		{
			this->type = configType(stringToNum<int>(value));
		}
		else if (key == "examID")
		{
			this->cardExam = examine(stringToNum<int>(value));
		}
	}
	//map<string, string>::iterator iter = myFind(roomConfig.begin(), roomConfig.end(), "name");
    //stringstream ss;
    //ss<<id;
    //string roomID = ss.str();
    
    //char tmp[32];
    //sprintf(tmp, "%d", id);
    //string roomID(tmp);
    //string roomID = new string(tmp); 
    //readCsvData("room.csv");
	//return true;
}

bool roomCard::canPass(direction dir)
{
	int checkDir = (int)dir;
	if (this->exportArray[checkDir] == 1)
	{
		return true;
	}
	return false;
	/**
	switch (dir)
	{
	case dirUp:
		if (this->up == 1)
		{
			return true;
		}
		break;
	case dirDown:
		if (this->down == 1)
		{
			return true;
		}
		break;
	case dirLeft:
		if (this->left == 1)
		{
			return true;
		}
		break;
	case dirRight:
		if (this->right == 1)
			return true;
		break;
	default:
		return false;
		break;
	}
	*/
	//return false;
}