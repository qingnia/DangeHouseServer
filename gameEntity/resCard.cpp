//
//  resCard.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/21.
//

#include "resCard.h"

resCard::resCard()
{
}

resCard::~resCard()
{
}

resCard::resCard(map<string, string> resConfig)
{
	map<string, string>::iterator iter;
	string key, value;
	for (iter = resConfig.begin(); iter != resConfig.end(); iter++)
	{
		key = iter->first;
		value = iter->second;
		if (key == "name")
		{
			this->name = value;
		}
		else if(key == "enlishName")
		{
			this->enlishName = value;
		}
	}
}