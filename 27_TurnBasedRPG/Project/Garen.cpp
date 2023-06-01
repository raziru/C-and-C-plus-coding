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
	//__super::ShowInfo(); //�ٷ� �� �θ��� ������ �����ϴ� ��ɾ�
	cout << "Regen :" << this->regen << endl;

}



void Garen::Skill(Character* other)
{
	cout << this->name << "�� ��ų ���!" << endl;

	this->curHP += this->regen;

	cout << this->name << "��(��) " << this->regen << "�� ü���� ȸ���߽��ϴ�!" << endl;
}

void Garen::AutoBattle(Character* other)
{
	BaseAttack(other);
	     Skill(other);
}
