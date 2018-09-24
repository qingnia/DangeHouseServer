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
