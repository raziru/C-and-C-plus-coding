#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << this->name << "캐릭터 생성!" << endl;
}

void Character::SetName(string name)
{
	this->name = name;
}

void Character::ShowInfo()
{
	cout << "-------- 현재 상태 --------" << endl;
	cout << "이름:   " << this->name    << endl;
	cout << "체력:   " << this->hp      << endl;
	cout << "공격력: " << this->attack  << endl;
	cout << "방어력: " << this->defense << endl;

	cout << "승리수: " << this->win     << endl;
	cout << "패배수: " << this->lose    << endl;

}



int Character::GetWin()
{
	return this->win;
}

void Character::SetWin(int temp)
{
	this->win = temp + this->win;
}

int Character::GetLose()
{
	return this->lose;
}

void Character::SetLose(int temp)
{
	this->lose = temp + this->lose;
}

int Character::GetHP()
{
	return this->hp;
}

Character::~Character()
{
	cout << name << "캐릭터 소멸!" << endl;

}