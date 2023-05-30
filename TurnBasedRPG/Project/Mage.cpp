#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << this->name << "마법사로 전직했습니다!" << endl;
	this->hp = 300;
	this->attack = 40;
	this->defense = 20;
}

Mage::Mage(string name)
{
	this->name = name;
	cout << this->name << "이(가) 마법사로 전직했습니다!" << endl;
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
	cout << "직업:   마법사" << endl;

}

void Mage::Attack(Character* other)//기본 공격
{
	this->mp += 10;
	cout << this->name << "의 기본 공격:" << endl;
	other->GetDamged(this->attack);
}

void Mage::Skill_1(Character* other)//기본 기술
{
	if (mp >= 20)
	{
		if (powerup)
		{
			this->mp -= 20;
			cout << this->name << "의 강화된 파이어볼:" << endl;
			powerup = false;
			other->GetDamged(this->attack * 3);
		}
		else
		{
			this->mp -= 20;
			cout << this->name << "의 파이어볼:" << endl;
			other->GetDamged(this->attack * 2);
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
			this->mp -= 80;
			cout << this->name << "의 블리자드:" << endl;
			powerup = false;
			other->GetDamged(this->attack * 8);
		}
		else
		{
			this->mp -= 80;
			cout << this->name << "의 얼음창:" << endl;
			other->GetDamged(this->attack * 5);
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
	cout << this->name << "의 마나회복:"<<endl<<"마나가 회복되고 스킬이 강화됩니다!" << endl;

}

void Mage::Skill_4(Character* other)//스탯 강화
{
	this->powerup = true;
	this->attack  += 30;
	this->defense += 30;
	cout << this->name << "의 정신집중:" << endl << " 스탯과 스킬이 강화됩니다!" << endl;
	cout << "하지만 받는 피해가 증가합니다!" << endl;

}

void Mage::Passive()
{
	this->mp += 10;
	cout << this->name << "의 패시브:" << endl;

	cout << this->name << "의 마나가 10 회복됩니다." << endl;
}

void Mage::GetDamged(int damage)
{
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	
	if (powerup)
	{
		this->hp -= (int)(damage * (1.2f));
		cout << this->name << "이(가) " << (int)(damage * (1.2f)) << "의 강화된 피해를 입었다!" << endl;


	}
	else
	{
		this->hp -= damage;
		cout << this->name << "이(가) " << damage << "의 피해를 입었다!" << endl;

	}
}

void Mage::ShowTrait()
{
	cout << "마법사는 마나를 사용하고 비축을 활용해 기술을 강화하는 클래스입니다." << endl;
	cout << "1. 기본공격 2. 파이어볼/강화된 파이어볼 3. 얼음창/블리자드 4. 마나회복 5. 정신집중" << endl;
	cout << "마나회복과 정신집중을 활용하면 강화된 기술을 사용할 수 있습니다." << endl;
	cout << "강화된 상태면 받는 피해가 증가합니다." << endl;



}

void Mage::Reset()
{
	cout << this->name << "을(를) 준비시킵니다!" << endl;
	this->mp = 0;
	this->hp = 300;
	this->attack = 40;
	this->defense = 20;
}
