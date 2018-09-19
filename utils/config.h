//
//  config.h
//  testC
//
//  Created by 陈帅 on 2018/9/19.
//

#ifndef config_h
#define config_h

#include <stdio.h>
#include "commonFun.h"

class config
{
private:
	config();
	static config* gameConfig;

	map<int, vector<string>> roomConfig, itemConfig, infoConfig, issueConfig;

	bool initRoomConfig();
public:
	config* getSingleConfig();
	~config();

	map<int, string> getRoomConfig();
};

#endif