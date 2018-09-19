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
#include "diyType.h"

enum configReadType
{
	numberInt,
	numberFloat,
	stringDesc,
	arrayValue,
	mapKey,
	mapValue,
};

struct fileConfig
{
	string fname;
	map<string, > kvMap;		//完全依赖表里面的字段名
};
enum configType
{
	roomCard,
	issueCard,
	itemCard,
	infoCard,
};

class config
{
private:
	config();
	static config* gameConfig;

	map<int, vector<string>> roomConfig, itemConfig, infoConfig, issueConfig;

	bool initRoomConfig();
	fileConfig getConfig(configType);
public:
	config* getSingleConfig();
	~config();

	map<int, string> getRoomConfig();
};

#endif