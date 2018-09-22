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

template <class Iterator, class T>
Iterator myFind(Iterator begin, Iterator end, const T &value);

template <class Type>
vector<Type> split(const string &str, const string &pattern);

//要求：1.主键在首列，2.主键是数字,3.首行忽略
map<int, map<string, string>> readCsvData(string fname);

#endif /* commonFun_h */