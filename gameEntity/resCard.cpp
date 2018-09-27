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
			this->m_name = value;
		}
		else if(key == "enlishName")
		{
			this->m_enlishName = value;
		}
		else if (key == "preDesc")
		{
			this->m_preDesc = value;
		}
		else if (key == "desc")
		{
			this->m_desc = value;
		}
	}
}