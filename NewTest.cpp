//
//  main.h
//  testC
//
//  Created by 陈帅 on 2018/9/21.
//

// NewTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>
#include "gameEntity/gameMgr.h"

std::list<int> myList;
std::mutex myMutex;

void mainGame()
{
	gameMgr* gm = gameMgr::getGameMgr();
	vector<int> roleIDList = {1001, 1002, 1003};
	gm->initNewMap(roleIDList);
	while (true)
	{
		std::lock_guard<std::mutex> guard(myMutex);
		for(auto &iter: myList)
			std::cout<<iter<<",";

		gm->update();
	}
}

void serverSocket(int max, int interval)
{
	std::lock_guard<std::mutex> guard(myMutex);
	for(int i=0;i<max;++i) {
		if(i%interval==0)
			myList.push_back(i);
	}


}
int main()
{
	int max = 15;
	std::thread t1(serverSocket, max, 1);
	std::thread t2(mainGame);
	t1.join();
	t2.join();

	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
