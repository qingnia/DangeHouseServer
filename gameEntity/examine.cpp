//
//  examine.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//
#include "examine.hpp"

examine::examine(int examID)
{
	config* conf = config::getSingleConfig();
    map<string, string> examConfig = conf->getConfig(exam, examID);
    //房间初始化
    map<string, string>::iterator iter;
 	string key, value;

	for (iter = examConfig.begin(); iter != examConfig.end(); iter++)
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
        else if(key == "examType")
        {
            this->et = stringToNum<examType>(value);
        }
        else if(key == "effect")
        {
            //要求配置比较复杂：et1_min1_max1_eNum1|et2_min2_max2_eNum2|....
            vector<string> effectConfig = split<string>(value, "|");
            vector<string>::iterator iter;
            for(iter = effectConfig.begin(); iter != effectConfig.end(); iter++)
            {
                this->efList.push_back(effect(*iter));
            }
        }
	}
}

void examine::showMsg()
{
    printf("你必须以 %d 进行能力考验\n", (int)(this->et));
    list<effect>::iterator iter;
    for(iter = this->efList.begin(); iter != this->efList.end(); iter++)
    {
        printf("如果得分在%d和%d之间，则%d收到%d点损伤\n", iter->min, iter->max, iter->et, iter->eNum);
    }
    //string roomID(tmp);
    //string roomID = new string(tmp)
    string info = "你必须以%d进行能力考验";
    cout<<""<<endl;
}

void examine::affect(player p, int num, int compareNum = 0)
{
    if(this->needAttack)
    {
        if(num < compareNum)
        {
        }
        else
        {
        }
    }
    list<effect>::iterator iter;
    for (iter = this->efList.begin();
		iter != this->efList.end(); iter++)
	{
        effect ef = *iter;
        if (num < ef.min || num > ef.max)
        {
            continue;
        }
        switch(ef.et)
        {
        case speed:
            break;
        case strength:
            break;
        case spirit:
            break;
        case knowledge:
            break;
        case physicalDamage:
            break;
        case mindDamage:
            break;
        default:
            break;
        }
        break;
	}
}