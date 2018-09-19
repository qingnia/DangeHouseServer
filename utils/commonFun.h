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
#include <map>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>
#include "diyType.h"

using namespace std;

vector<int> myShuffle(int num);

direction reverseDir(direction);

bool in_vector(int value, vector<int> vec);

template <class Type>
Type stringToNum(const string str);

map<int, vector<string>> readCsvData(string fname, int pKeyPos = 0);

#endif /* commonFun_h */