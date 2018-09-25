//
//  card.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/22.
//

#include "card.h"

card::card()
{
}

card::~card()
{
}

bool card::showMsg()
{
    cout<<this->m_desc<<endl;
    return true;
}

string card::getName()
{
    return this->m_name;
}

string card::getEnlishName()
{
    return this->m_enlishName;
}

string card::getDesc()
{
    return this->m_desc;
}