#include "Framework.h"
#include "Vampire.h"


Vampire::Vampire()
{
	cout << this->name << "뱀파이어로 전직했습니다!" << endl;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}

Vampire::Vampire(string name)
{
	this->name = name;
	cout << this->name << "이(가) 뱀파이어로 전직했습니다!" << endl;
	this->hp = 400;
	this->attack = 10;
	this->defense = 30;
}

Vampire::~Vampire()
{
}



void Vampire::ShowInfo()
{

	Character::ShowInfo();
	cout << "피구슬: " << this->blood << endl;
	cout << "직업:  뱀파이어" << endl;
}

void Vampire::Attack(Character* other)
{
	cout << this->name << "의 기본 공격:" << endl;
	other->GetDamged(this->attack);
	this->GetDamged(10);
}

void Vampire::Skill_1(Character* other)
{
	if (blood > 50)
	{
		this->hp += 50;
		this->blood = 0;
		cout << this->name << "의 흡혈:" << endl;
		other->GetDamged(this->attack * 5);
	}
	else
	{
		cout << this->name << "의 수혈:" << endl;
		other->GetDamged(this->attack * 2);
		this->GetDamged(20);
	}
}

void Vampire::Skill_2(Character* other)
{
	if (blood > 100)
	{
		this->hp += 150;
		this->blood = 0;
		cout << this->name << "의 혈폭발:" << endl;
		other->GetDamged(this->attack * 5);
	}
	else if (blood > 50)
	{
		this->hp += 50;
		this->blood = 0;
		cout << this->name << "의 폭발:" << endl;
		other->GetDamged(this->attack * 3);
	}
	else
	{
		cout << this->name << "의 수혈:" << endl;
		other->GetDamged(this->attack * 2);
		this->GetDamged(20);
	}

}

void Vampire::Skill_3(Character* other)
{
	this->hp += 30;
	cout << this->name << "의 자학:" << endl;
	this->GetDamged(70);

}

void Vampire::Skill_4(Character* other)
{
	this->hp += 60;
	this->attack += 20;
	this->defense += 20;
	cout << this->name << "의 치유:"<<endl<<"체력을 회복하고 스탯이 증가합니다!" << endl;
}

void Vampire::Passive()
{
	cout << this->name << "의 패시브:" << endl;
	cout << this->name << "이(가) 피구슬을 충전합니다!" << endl;
	this->GetDamged(5);


}

void Vampire::GetDamged(int damage)
{
	int temp = damage / 2;
	
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	this->hp -= damage;
	cout << this->name << "이(가) " << damage << "의 피해를 입었다!" << endl;
	if (this->hp <= 0)
	{
		cout << "죽을 피해를 입어 피구슬로 회복합니다." << endl;
		this->hp += this->blood;
		this->blood = 0;
	}
	this->blood += temp;
	cout << this->name << "이(가) " << temp << "만큼 피구슬을 충전했다!" << endl;
}

void Vampire::ShowTrait()
{
	cout << "뱀파이어는 자해를 하여 피해량을 강화하는 클래스입니다." << endl;
	cout << "1. 기본공격 2. 흡혈/수혈 3. 수혈/폭발/혈폭발 4. 자학 5. 치유" << endl;
	cout << "피해를 입으면 피구슬에 저장되고 일정 수치가 되면 강화된 기술을 사용합니다." << endl;
	cout << "뱀파이어는 죽을 피해를 입으면 피구슬을 활용하여 부활합니다." << endl;



}

void Vampire::Reset()
{
	this->hp = 400;
	this->attack = 10;
	this->defense = 30;
	this->blood = 0;
}
