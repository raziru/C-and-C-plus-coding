#include "Framework.h"
#include "Character.h"

Character::Character()
{
	cout << "Character ������ ȣ��!" << endl;
}

Character::~Character()
{
	cout << "Character �Ҹ��� ȣ��!" << endl;

}

void Character::ShowInfo()
{
	cout << "-----Character Info-----" << endl;


	cout << "Name  : " << name << endl;
	cout << "Level : " << level << endl;
	cout << "HP    : " << hp << endl;
	cout << "Damage: " << damage << endl;

}

void Character::Attack(Character* other)
{
	cout << this->name << "��(��) " << other->name << "��(��) ����!" << endl;
}

void Character::SetCombat()
{
}


