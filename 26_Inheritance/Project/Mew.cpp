#include "Framework.h"
#include "Mew.h"



Mew::Mew()
{
	name = "��";
	cout << "Mew       ������ ȣ��!" << endl;

}

Mew::~Mew()
{
	cout << "Mew       �Ҹ��� ȣ��!" << endl;

}

void Mew::ShowInfo()
{
	Character::ShowInfo();

	cout << "MP    : " << mp << endl;

}

