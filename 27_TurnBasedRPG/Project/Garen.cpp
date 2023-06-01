#include "Framework.h"
#include "Garen.h"


Garen::Garen()
{
	this->name = "Garen";
	attackDamage = 20;
	maxHP = 200;
	regen = 5;
}

Garen::~Garen()
{
}

void Garen::ShowInfo()
{
	Character::ShowInfo();
	//__super::ShowInfo(); //바로 위 부모의 정보에 접근하는 명령어
	cout << "Regen :" << this->regen << endl;

}



void Garen::Skill(Character* other)
{
	cout << this->name << "의 스킬 사용!" << endl;

	this->curHP += this->regen;

	cout << this->name << "이(가) " << this->regen << "의 체력을 회복했습니다!" << endl;
}

void Garen::AutoBattle(Character* other)
{
	BaseAttack(other);
	     Skill(other);
}
