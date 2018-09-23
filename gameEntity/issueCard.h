//
//  issueCard.h
//  testC
//
//  Created by 陈帅 on 2018/9/22.
//

#include "card.h"
#include<map>

using namespace std;
class issueCard :
	public card
{
	issueCard();
public:
	issueCard(map<string, string>);
	virtual ~issueCard();

};
