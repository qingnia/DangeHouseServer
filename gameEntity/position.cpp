#include "../pch.h"
//
//  main.cpp
//  testC
//
//  Created by 陈帅 on 2018/9/10.
//

#include "position.h"

position::position()
{

}

position::position(int x, int y)
{
    this->x = x;
    this->y = y;
}

position* position::getNeibourPos(direction dir)
{
	position* pos = nullptr;
	switch (dir)
	{
	case up:
		pos = new position(this->x, this->y + 1);
		break;
	case down:
		pos = new position(this->x, this->y - 1);
		break;
	case direction::left:
		pos = new position(this->x - 1, this->y);
		break;
	case direction::right:
		pos = new position(this->x + 1, this->y);
		break;
	default:
		break;
	}
	return pos;
}