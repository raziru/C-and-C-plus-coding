#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << this->name << "캐릭터 생성!" << endl;
	this->win = 0;
	this->lose = 0;
}



void Character::ShowInfo()
{
	cout << "-------- 현재 상태 --------" << endl;
	cout << "이름:   " << this->name    << endl;
	cout << "체력:   " << this->hp      << endl;
	cout << "공격력: " << this->attack  << endl;
	cout << "방어력: " << this->defense << endl;

	

}

void Character::ShowRecord()
{
	cout << "----------- 전적 ---------" << endl;

	cout << "승리수: " << this->win << endl;
	cout << "패배수: " << this->lose << endl;
	if (this->lose+this->win == 0)
	{
		cout << "승률  : -" << endl;

	}
	else
	{
		cout << "승률  : " << this->win / (float)(this->lose + this->win) * 100.0f << "%" << endl;

	}
}



int Character::GetWin()
{
	return this->win;
}

void Character::SetWin()
{
	this->win ++;
}

int Character::GetLose()
{
	return this->lose;
}

void Character::SetLose()
{
	this->lose++;
}

int Character::GetHP()
{
	return this->hp;
}

Character::~Character()
{
	cout << name << "캐릭터 소멸!" << endl;

}