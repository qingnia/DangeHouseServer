//
//  client.hpp
//  testC
//
//  Created by 陈帅 on 2018/10/10.
//

#ifndef clientMgr_hpp
#define clientMgr_hpp

#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;
class clientMgr
{
private:
	map<int32_t, int64_t> role2Handle;
	clientMgr();
	static clientMgr* mgr;

public:
	static clientMgr* getSingleMgr();
	~clientMgr();

	int32_t roleLogin(int32_t roleID, int32_t roomID, int64_t handle);
};

#endif