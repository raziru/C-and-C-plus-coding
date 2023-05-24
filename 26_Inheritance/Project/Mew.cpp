#include "Framework.h"
#include "Mew.h"



Mew::Mew()
{
	name = "뮤";
	cout << "Mew       생성자 호출!" << endl;

}

Mew::~Mew()
{
	cout << "Mew       소멸자 호출!" << endl;

}

void Mew::ShowInfo()
{
	Character::ShowInfo();

	cout << "MP    : " << mp << endl;

}

