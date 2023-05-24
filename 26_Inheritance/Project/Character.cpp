#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << "Character 생성자 호출!" << endl;
}

Character::~Character()
{
	cout << "Character 소멸자 호출!" << endl;

}

void Character::ShowInfo()
{
	cout << "-----Character Info-----" << endl;


	cout << "Name  : " << name  << endl;
	cout << "Level : " << level << endl;
	cout << "HP    : " << hp    << endl;
	cout << "Damage: " << damage << endl;

}

void Character::Attack(Character* other)
{
	cout << this->name << "이(가) " << other->name << "을(를) 공격!" << endl;
}



