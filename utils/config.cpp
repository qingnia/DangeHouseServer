﻿//
//  config.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/19.
//

#include "config.h"

config* config::gameConfig = new config();
config::config()
{
	//this->roomConfig = readCsvData("../tables/Room.csv");
	this->roomConfig = readCsvData("E:/vsProjects/Serious/tables/Room.csv");
	this->issueConfig = readCsvData("E:/vsProjects/Serious/tables/issue.csv");
	this->examConfig = readCsvData("E:/vsProjects/Serious/tables/Examine.csv");
}

config::~config()
{
}

config* config::getSingleConfig()
{
	if (gameConfig == nullptr)
	{
		gameConfig = new config();
	}
	return gameConfig;
}

map<string, string> config::getConfig(configType type, int id)
{
	//map<string, string> fc;
	map<int, map<string, string> >::iterator iter;
	switch (type)
	{
	case ctRoom:
		if (this->roomConfig.size() <= 0)
		{
			this->roomConfig = readCsvData("../tables/Room.csv");
		}
		iter = this->roomConfig.find(id);
		if (iter != this->roomConfig.end())
		{
			return iter->second;
		}
		//fc.fname = "../config/Room.csv";
		//fc.kvMap[string("Name")] = stringDesc;
		//fc.kvMap[string("enlishName")] = stringDesc;
		//fc.kvMap[string("layer")] = vectorInt;
		//fc.kvMap[string("type")] = numberInt;
		//this->roomConfig = loadConfig(fc);
		break;
	case ctIssue:
		break;
	case ctRes:
		break;
	case ctInfo:
		break;
	case ctExam:
		if (this->examConfig.size() <= 0)
		{
			this->examConfig = readCsvData("../tables/Exam.csv");
		}
		iter = this->examConfig.find(id);
		if (iter != this->examConfig.end())
		{
			return iter->second;
		}
		break;
	default:
		break;
	}
	return iter->second;
}
