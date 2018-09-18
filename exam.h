//
//  main.hpp
//  testC
//
//  Created by 陈帅 on 2018/9/16.
//

#ifndef exam_h
#define exam_h

#include <stdio.h>
#include <list>
#include "gameEntity\player.hpp"
using namespace std;

enum examType{
    speed,
    strength,
    spirit,
    knowledge,
    physicalDamage,
    mindDamage,
    none,
};

typedef struct{
    //影响类型
    examType et;
    int min;
    int max;
    int eNum;
}effect;

class exam{

public:
    examType et;
    bool needAttack;

    //区间判定
    //（1，3，6）氛围0-1，2-3，4-6三个区间
    list<effect> efList;

    void affect(player p, int num, int compareNum);
};

#endif /* exam_hpp */
