//
//  resCard.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/21.
//

#include "infoCard.hpp"

infoCard::infoCard()
{
}

infoCard::~infoCard()
{
}

infoCard::infoCard(map<string, string> infoConfig)
{
	map<string, string>::iterator iter;
	string key, value;
	for (iter = infoConfig.begin(); iter != infoConfig.end(); iter++)
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
	}
}