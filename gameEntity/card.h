//
//  card.h
//  testC
//
//  Created by 陈帅 on 2018/9/22.
//

#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <string>
#include "examine.hpp"

using namespace std;

class card
{
private:
protected:
	int id;
	string name, enlishName;
public:
	card();
	virtual ~card();

};

#endif