#include "Framework.h"
#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::ShowInfo()
{
	cout << "-----" << name << " Info-----" << endl;
	cout << "CurHP :" << curHP        << endl;
	cout << "MaxHP :" << maxHP        << endl;
	cout << "AD    :" << attackDamage << endl;


}



void Character::Initialize()
{
	curHP = maxHP;
}

void Character::BaseAttack(Character* other)
{
	cout << this->name << "��(��) " << other->name << "��(��) ����!" << endl;


	other->ApplyDamage(this->attackDamage);
}

void Character::AutoBattle(Character* other)
{
	if (rand() % 2)
		BaseAttack(other);
	else
		Skill(other);
}

void Character::ApplyDamage(int damage)
{
	this->curHP -= damage;

	if (curHP<0)
	{
		curHP = 0;
	}

}


