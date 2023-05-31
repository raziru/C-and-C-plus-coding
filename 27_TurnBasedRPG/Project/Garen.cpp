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
	//__super::ShowInfo(); //바로 위 부모의 정보에 접근하는 명령어
	
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
