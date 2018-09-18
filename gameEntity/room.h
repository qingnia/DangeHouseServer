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
#include "../utils/file.h"
#include "../utils/diyType.h"

using namespace std;

class room{
    room();
public:
    room(int id);

    vector<int> suiteLayer;

    int left;
    int right;
    int up;
    int down;

	bool canPass(direction);
};

#endif /* room_hpp */