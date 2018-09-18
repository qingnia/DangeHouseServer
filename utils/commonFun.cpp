//
//  commonFun.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/19.
//

#include "commonFun.h"

vector<int> myShuffle(int num)
{
	vector<int> tmpVec(num);
  
    for (int i = 0; i < num; ++i) {  
        tmpVec.push_back (i);  
    }  

    // obtain a time-based seed:  
    unsigned seed = chrono::system_clock::now().time_since_epoch().count ();
    shuffle(tmpVec.begin(), tmpVec.end(), default_random_engine(seed));  
	return tmpVec;
}

direction reverseDir(direction dir)
{
    direction revDir = up;
    switch(dir)
    {
    case up:
        revDir = down;
        break;
    case down:
        revDir = up;
        break;
    case direction::left:
        revDir = direction::right;
        break;
    case direction::right;
        revDir = direction::left;
        break;
    default:
        break;
    }
    return revDir;
}

bool in_vector(int value, vector<int> vec)
{
    vector<int>::iterator it;
    
    it=find(vec.begin(),vec.end(),value);
    if (it!=vec.end())
    {
        return true;
    }
    return false;
}