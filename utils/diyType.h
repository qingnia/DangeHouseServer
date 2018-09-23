﻿//
//  diyType.h
//  testC
//
//  Created by 陈帅 on 2018/9/18.
//

#ifndef diyType_h
#define diyType_h

enum actionType {
	atStart,
	atMove,
	atStop,
	atOver,
};

enum direction {
	up,
	down,
	left,
	right,
};

enum moveRoomType
{
	enter,
	pass,
	leave,
};

enum configType
{
	room,
	issue,
	res,
	info,
};

enum examType{
    speed,
    strength,
    spirit,
    knowledge,
    physicalDamage,
    mindDamage,
    none,
};

#endif