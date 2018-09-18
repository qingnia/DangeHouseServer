//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef file_h
#define file_h

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

map<int, void*> readCsvData(string fname, string pKey, string pValue = "");

#endif /* file_hpp */