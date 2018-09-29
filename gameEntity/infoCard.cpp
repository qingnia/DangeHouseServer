﻿//
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
		else if (key == "enlishName")
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
		else if (key == "buff")
		{
			//要求配置比较复杂：et1_eNum1|et2_eNum2|....
			vector<string> effectConfig = split<string>(value, "|");
			vector<string>::iterator iter;
			for (iter = effectConfig.begin(); iter != effectConfig.end(); iter++)
			{
				vector<int> tmpVec = split<int>(*iter, "_");
				examType et = (examType)tmpVec[0];
				this->buff[et] = tmpVec[1];
			}
		}
		else if (key == "deBuff")
		{
			//要求配置比较复杂：et1_eNum1|et2_eNum2|....
			vector<string> effectConfig = split<string>(value, "|");
			vector<string>::iterator iter;
			for (iter = effectConfig.begin(); iter != effectConfig.end(); iter++)
			{
				vector<int> tmpVec = split<int>(*iter, "_");
				examType et = (examType)tmpVec[0];
				this->deBuff[et] = tmpVec[1];
			}
		}
		else if( key == "examType")
		{
			this->useType = (cardUseType)stringToNum<int>(value);
		}
		else if (key == "examID")
		{
			this->cardExam = examine(stringToNum<int>(value));
		}
	}
}