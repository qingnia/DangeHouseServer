//
//  infoCard.h
//  testC
//
//  Created by 陈帅 on 2018/9/24.
//

#ifndef infoCard_h
#define infoCard_h

#include <stdio.h>
#include "card.h"
#include "../utils/config.h"

class infoCard:public card
{
private:
	infoCard();

public:
	infoCard(map<string, string>);
	virtual ~infoCard();

};

#endif