//
//  main.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//
#include "exam.h"


void exam::affect(player p, int num, int compareNum = 0)
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