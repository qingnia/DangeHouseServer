//
//  commonFun.h
//  testC
//
//  Created by 陈帅 on 2018/9/19.
//

#ifndef commonFun_h
#define commonFun_h

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include "diyType.h"

using namespace std;

vector<int> myShuffle(int num);

direction reverseDir(direction);

bool in_vector(int value, vector<int> vec);

#endif /* commonFun_h */