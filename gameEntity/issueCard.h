//
//  issueCard.h
//  testC
//
//  Created by 陈帅 on 2018/9/22.
//

#include "card.h"
class issueCard :
	public card
{
public:
	issueCard();
	~issueCard();

	bool init(int);
};
