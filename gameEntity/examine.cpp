//
//  examine.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//
#include "examine.hpp"

void examine::showMsg()
{
    printf("你必须以 %d 进行能力考验\n", (int)(this->et));
    list<effect>::iterator iter;
    effect oneEF;
    for(iter = this->efList.begin(); iter != this->efList.end(); iter++)
    {
        oneEF = *iter;
        printf("如果得分在%d和%d之间，则%d收到%d点损伤\n", oneEF.min, oneEF.max, oneEF.et, oneEF.eNum);
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