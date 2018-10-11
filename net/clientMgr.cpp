//
//  clientMgr.cpp
//  testC
//
//  Created by 陈帅 on 2018/10/10.
//

#include "clientMgr.hpp"

clientMgr* clientMgr::mgr = new clientMgr();
clientMgr::clientMgr()
{
}

clientMgr::~clientMgr()
{
}

clientMgr* clientMgr::getSingleMgr()
{
	if (mgr == nullptr)
	{
		mgr = new clientMgr();
	}
	return mgr;
}

int32_t clientMgr::roleLogin(int32_t roleID, int32_t roomID, int64_t handle)
{
	role2Handle[roleID] = handle;
	return 0;
}
