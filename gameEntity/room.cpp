//
//  main.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//

#include "room.h"

room::room()
{

}

room::room(int id)
{
    //stringstream ss;
    //ss<<id;
    //string roomID = ss.str();
    
    char tmp[32];
    sprintf(tmp, "%d", id);
    string roomID(tmp);
    //string roomID = new string(tmp); 
    readCsvData("room.csv");
}

bool room::canPass(direction dir)
{
	switch (dir)
	{
	case direction::up:
		if (this->up == 1)
		{
			return true;
		}
		break;
	case direction::down:
		if (this->down == 1)
		{
			return true;
		}
		break;
	case direction::left:
		if (this->left == 1)
		{
			return true;
		}
		break;
	case direction::right:
		if (this->right == 1)
			return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}