#include "Framework.h"
#include "Neeko.h"


Neeko::Neeko()
{
	this->name = "Neeko";
	attackDamage = 20;
	maxHP = 200;
	regen = 5;
}

Neeko::~Neeko()
{
}

void Neeko::ShowInfo()
{
	Character::ShowInfo();
	//__super::ShowInfo(); //�ٷ� �� �θ��� ������ �����ϴ� ��ɾ�
	cout << "Regen :" << this->regen << endl;

}



void Neeko::Skill(Character* other)
{
	cout << this->name << "�� ��ų ���!" << endl;

	this->curHP += this->regen;

	cout << this->name << "��(��) " << this->regen << "�� ü���� ȸ���߽��ϴ�!" << endl;
}

void Neeko::AutoBattle(Character* other)
{
	BaseAttack(other);
	Skill(other);
}