#include "Framework.h"
#include "Garen.h"


Garen::Garen()
{
	this->name = "Garen";
	attackDamage = 20;
	maxHP = 200;
	regen = 20;
}

Garen::~Garen()
{
}

void Garen::ShowInfo()
{
	Character::ShowInfo();
	//__super::ShowInfo(); //�ٷ� �� �θ��� ������ �����ϴ� ��ɾ�
	
}

void Garen::Initialize()
{
	curHP = maxHP;
}

void Garen::BaseAttack(Character* other)
{
}

void Garen::Skill(Character* other)
{
}
