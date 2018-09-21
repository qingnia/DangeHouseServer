//
//  resItem.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/21.
//

#include "resItem.h"

resItem::resItem()
{
}

resItem::~resItem()
{
}

int resItem::initItem(int id)
{
	config* gameConf = config::getSingleConfig();
	map<string, string> resConf = gameConf->getConfig(resCard, id);
	return true;
}