#include "Framework.h"
#include "Teemo.h"

Teemo::Teemo()//생성자는 자주 호출하는 의도를 가지면 안된다.
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
	//__super::ShowInfo(); //바로 위 부모의 정보에 접근하는 명령어
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
		//마나가 없음
		cout << "마나가 부족합니다!" << endl;

		BaseAttack(other);
	}
	else
	{
		//마나가 있음

		cout << this->name << " 의 스킬 사용!" << endl;

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

