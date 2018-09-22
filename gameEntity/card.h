//
//  card.h
//  testC
//
//  Created by 陈帅 on 2018/9/22.
//

#ifndef Card_h
#define Card_h

#include <stdio.h>

class card
{
private:
	int id;

public:
	card();
	bool virtual init(int)
	~card();

};

#endif