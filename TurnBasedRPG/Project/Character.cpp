#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << this->name << "ĳ���� ����!" << endl;
}

void Character::SetName(string name)
{
	this->name = name;
}

void Character::ShowInfo()
{
	cout << "-------- ���� ���� --------" << endl;
	cout << "�̸�:   " << this->name    << endl;
	cout << "ü��:   " << this->hp      << endl;
	cout << "���ݷ�: " << this->attack  << endl;
	cout << "����: " << this->defense << endl;

	cout << "�¸���: " << this->win     << endl;
	cout << "�й��: " << this->lose    << endl;

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
	cout << name << "ĳ���� �Ҹ�!" << endl;

}