//
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
	dirUp,
	dirDown,
	dirLeft,
	dirRight,
	dirStop,
};

enum moveRoomType
{
	enter,
	pass,
	leave,
};

enum configType
{
	ctIssue,
	ctRes,
	ctInfo,
	ctRoom,
	ctExam,
};

enum examType{
    etSpeed,
    etStrength,
    etSpirit,
    etKnowledge,
    etPhysicalDamage,
    etMindDamage,
    etNone,
};

#endif