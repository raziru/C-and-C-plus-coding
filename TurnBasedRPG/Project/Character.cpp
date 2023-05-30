#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << this->name << "ĳ���� ����!" << endl;
	this->win = 0;
	this->lose = 0;
}



void Character::ShowInfo()
{
	cout << "-------- ���� ���� --------" << endl;
	cout << "�̸�:   " << this->name    << endl;
	cout << "ü��:   " << this->hp      << endl;
	cout << "���ݷ�: " << this->attack  << endl;
	cout << "����: " << this->defense << endl;

	

}

void Character::ShowRecord()
{
	cout << "----------- ���� ---------" << endl;

	cout << "�¸���: " << this->win << endl;
	cout << "�й��: " << this->lose << endl;
	if (this->lose+this->win == 0)
	{
		cout << "�·�  : -" << endl;

	}
	else
	{
		cout << "�·�  : " << this->win / (float)(this->lose + this->win) * 100.0f << "%" << endl;

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
	cout << name << "ĳ���� �Ҹ�!" << endl;

}