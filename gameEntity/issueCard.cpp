//
//  gameMgr.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/17.
//


#include "issueCard.h"



issueCard::issueCard()
{
}


issueCard::~issueCard()
{
}

issueCard::issueCard(map<string, string> issueConfig)
{
	map<string, string>::iterator iter;
	string key, value;
	for (iter = issueConfig.begin(); iter != issueConfig.end(); iter++)
	{
		key = iter->first;
		value = iter->second;
		if (key == "name")
		{
			this->name = value;
		}
		else if (key == "enlishName")
		{
			this->enlishName = value;
		}
		else if (key == "desc")
		{
			this->m_desc = value;
		}
		else if (key == "examID")
		{
			this->cardExam = examine(stringToNum<int>(value));
		}
	}
}
