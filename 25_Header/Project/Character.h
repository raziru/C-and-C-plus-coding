#pragma once

/*
�̸� �����ϵ� ���(Pre-compiled header, pch.h) -- �ѹ� �����ϵǸ� ���̻� �������� �ʿ���� ������� ��Ƶδ� ���
����ð��� �����ϴµ� ����� �� �ִ�.

stdafx.h(STandard Applicatioin Framework eXtensioin) // visualstudio 13���� ���

framework.h//���� �ַ� ���Ǵ� ���

*/

#define MAX_STAT 100//�ڵ尡 �ƴ϶� ����Ŭ���� �Ⱥ���

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


