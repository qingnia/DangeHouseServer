//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef room_h
#define room_h

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "card.h"
#include "../utils/commonFun.h"
#include "../utils/diyType.h"
#include "../utils/config.h"

using namespace std;

class room:card{
	string name, enlishName;
    room();
public:
    bool init(map<string, string> roomConfig);

    vector<int> suiteLayer;

    int left, right, up, down;

	moveRoomType testType;

	configType type;
	bool canPass(direction);
};

#endif /* room_hpp */