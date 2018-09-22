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

bool resCard::init(int id)
{
	config* gameConf = config::getSingleConfig();
	map<string, string> resConf = gameConf->getConfig(resCard, id);
	return true;
}