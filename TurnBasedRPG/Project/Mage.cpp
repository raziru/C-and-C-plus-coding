#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << this->name << "가 마법사로 전직했습니다!" << endl;
	this->hp = 300;
	this->attack = 40;
	this->defense = 20;
}

Mage::~Mage()
{
}

void Mage::ShowInfo()
{
	Character::ShowInfo();
	cout << "마나량: " << this->mp << endl;
	cout << "강화상태: " << (this->powerup ? "강화됨" : "일반") << endl;

}

void Mage::Attack(Character* other)//기본 공격
{
	other->GetDamged(this->attack);
	this->mp += 10;
	cout << this->name << "의 기본 공격!" << endl;
}

void Mage::Skill_1(Character* other)//기본 기술
{
	if (mp >= 20)
	{
		if (powerup)
		{
			other->GetDamged(this->attack * 3);
			this->mp -= 20;
			cout << this->name << "의 강화된 파이어볼!" << endl;
			powerup = false;
		}
		else
		{
			other->GetDamged(this->attack * 2);
			this->mp -= 20;
			cout << this->name << "의 파이어볼!" << endl;
		}
	}
	else
	{
		cout << this->name << "의 마나가 부족합니다!" << endl;

	}
}

void Mage::Skill_2(Character* other)//필살기
{
	if (mp >= 80)
	{
		if (powerup)
		{
			other->GetDamged(this->attack * 8);
			this->mp -= 80;
			cout << this->name << "의 필살 메테오!" << endl;
			powerup = false;
		}
		else
		{
			other->GetDamged(this->attack * 5);
			this->mp -= 80;
			cout << this->name << "의 파이어볼!" << endl;
		}
	}
	else
	{
		cout << this->name << "의 마나가 부족합니다!" << endl;

	}
}

void Mage::Skill_3(Character* other)//자원생성
{

	this->mp += 30;
	this->powerup = true;
	cout << this->name << "의 마나회복! 스킬이 강화됩니다!" << endl;

}

void Mage::Skill_4(Character* other)//스탯 강화
{
	this->powerup = true;
	this->attack  += 10;
	this->defense += 10;
	cout << this->name << "의 강화! 스탯과 스킬이 강화됩니다!" << endl;
	cout << "하지만 받는 피해가 증가합니다!" << endl;

}

void Mage::Passive()
{
	this->mp += 10;
	cout << this->name << "의 마나가 10 회복됩니다." << endl;
}

void Mage::GetDamged(int damage)
{
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	
	if (powerup)
	{
		this->hp -= damage * (1.2f);

	}
	else
	{
		this->hp -= damage;
	}
}
