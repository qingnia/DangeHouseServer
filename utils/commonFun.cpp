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

	for (int i = 0; i < num; i++) {
		tmpVec[i] = i;
	}

	// obtain a time-based seed:  
	unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();
	shuffle(tmpVec.begin(), tmpVec.end(), default_random_engine(seed));
	return tmpVec;
}

direction reverseDir(direction dir)
{
	direction revDir = dirUp;
	switch (dir)
	{
	case dirUp:
		revDir = dirDown;
		break;
	case dirDown:
		revDir = dirUp;
		break;
	case dirLeft:
		revDir = dirRight;
		break;
	case dirRight:
		revDir = dirLeft;
		break;
	default:
		break;
	}
	return revDir;
}

bool in_vector(int value, vector<int> vec)
{
	vector<int>::iterator it;

	it = find(vec.begin(), vec.end(), value);
	if (it != vec.end())
	{
		return true;
	}
	return false;
}

string Trim(string& str)
{
	str.erase(0, str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
	return str;
}

map<int, map<string, string>> readCsvData(string fname)
{
	map<int, map<string, string>> fileInfo;
	ifstream fin(fname);
	string line;

	//统一忽略首行
	getline(fin, line);

	string field;

	//第二行是字段名
	getline(fin, line);
	istringstream sin(line);
	vector<string> keys;
	while (getline(sin, field, ','))
	{
		keys.push_back(field);
	}

	string value;
	int pKey;	//每一行的主键,主键必须是数字
	string key;		//具体的字段名
	int fieldPos;
	while (getline(fin, line))
	{
		istringstream sin(line);
		map<string, string> kv;

		fieldPos = 0;
		while (getline(sin, value, ','))
		{
			//首列是key
			if (fieldPos == 0)
			{
				pKey = stringToNum<int>(value);
			}
			kv[keys[fieldPos]] = value;
			
			fieldPos++;
		}
		fileInfo[pKey] = kv;
	}
	return fileInfo;
}


template <class Iterator, class T>
Iterator myFind(Iterator begin, Iterator end, const T &value)
{
	while (begin != end && *begin != value) {
		++begin;
	}
	return begin;
}
