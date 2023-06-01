#include "Framework.h"
#include "Teemo.h"

Teemo::Teemo()//�����ڴ� ���� ȣ���ϴ� �ǵ��� ������ �ȵȴ�.
{
	name = "Teemo";

	maxHP = 100;
	maxMP = 100;

	attackDamage = 40;
}

Teemo::~Teemo()
{
}

void Teemo::ShowInfo()
{
	Character::ShowInfo();
	//__super::ShowInfo(); //�ٷ� �� �θ��� ������ �����ϴ� ��ɾ�
	cout << "CurMP :" << curMP << endl;
	cout << "MaxMP :" << maxMP << endl;
	
}

void Teemo::Initialize()
{
	Character::Initialize();

	curMP = maxMP;
}

void Teemo::BaseAttack(Character* other)
{
	Character::BaseAttack(other);

	count = 3;
}

void Teemo::Skill(Character* other)
{

	int mpCost = 30;

	if (mpCost > curMP)
	{
		//������ ����
		cout << "������ �����մϴ�!" << endl;

		BaseAttack(other);
	}
	else
	{
		//������ ����

		cout << this->name << " �� ��ų ���!" << endl;

		curMP -= mpCost;

		float rate = 1.2f;

		other->ApplyDamage(rate * attackDamage);
	}
}

void Teemo::AutoBattle(Character* other)
{
	if (count>0)
	{
		int damage = 5;

		other->ApplyDamage(damage);

		count--;
	}

	Character::AutoBattle(other);
}

