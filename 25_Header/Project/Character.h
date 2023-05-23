#pragma once

/*
미리 컴파일된 헤더(Pre-compiled header, pch.h) -- 한번 컴파일되면 더이상 컴파일이 필요없는 존재들을 모아두는 헤더
빌드시간을 단축하는데 사용할 수 있다.

stdafx.h(STandard Applicatioin Framework eXtensioin) // visualstudio 13버전 용어

framework.h//현재 주로 사용되는 용어

*/

#define MAX_STAT 100//코드가 아니라서 세미클론이 안붙음

typedef unsigned int UNIT;

struct Point
{
	int x;
	int y;
};


class Character
{
public:
	Character();
	~Character();

	void ShowInfo();


private:
	string name;
	int    level;

	Point point;
};


