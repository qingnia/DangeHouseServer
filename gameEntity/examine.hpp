//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef examine_h
#define examine_h

#include <stdio.h>
#include <list>
#include "player.hpp"
using namespace std;

struct effect{
    //影响类型
    examType et;
    int min, max, eNum;

    effect(string str)
    {
        vector<int> conf = split<int>(str, "_");
        this->et = (examType)conf[0];
        this->min = conf[1];
        this->max = conf[2];
        this->eNum = conf[3];
    }

    effect(examType et, int min, int max, int eNum)
    {
        this->et = et;
        this->min = min;
        this->max = max;
        this->eNum = eNum;
    }
};

class examine{

private:
    void showMsg();
public:
    examine(int);

    string name, enlishName;
    examType et;
    bool needAttack;

    //区间判定
    //（1，3，6）氛围0-1，2-3，4-6三个区间
    list<effect> efList;

    void affect(player p, int num, int compareNum);
};

#endif /* examine_hpp */
