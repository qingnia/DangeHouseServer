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
};

enum moveRoomType
{
	enter,
	pass,
	leave,
};

enum configType
{
	ctRoom,
	ctIssue,
	ctRes,
	ctInfo,
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