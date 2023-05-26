#include "Framework.h"
#include "Warrior.h"

Warrior::Warrior()
{
	cout << this->name << "가 전사로 전직했습니다!" << endl;

	this->hp = 500;
	this->attack = 30;
	this->defense = 50;
}

Warrior::~Warrior()
{
}

void Warrior::ShowInfo()
{
	Character::ShowInfo();
	cout << "방어도: " << this->shield << endl;

}

void Warrior::Attack(Character* other)//기본공격
{
	other->GetDamged(this->attack);
	this->shield += 10;
	cout << this->name << "의 기본 공격!" << endl;
}

void Warrior::Skill_1(Character* other)//방패 밀쳐내기
{
	other->GetDamged(this->attack + 50);
	this->shield -= 20;
	cout << this->name << "의 방패 밀쳐내기!" << endl;
	cout << this->name << "는 방어도 20을 잃었다!" << endl;

}

void Warrior::Skill_2(Character* other)
{
	this->shield += 50;
	cout << this->name << "의 방어도 증가!" << endl;
	cout << this->name << "는 방어도 50을 얻었다!" << endl;

}

void Warrior::Skill_3(Character* other)//방패 부수기 //방어도 증가
{

	other->GetDamged(this->shield * 5);
	this->shield = 0;
	cout << this->name << "의 방패부수기!" << endl;
	cout << name << "의 방패가 파괴됐다!" << endl;

}

void Warrior::Skill_4(Character* other)//고무
{

	this->attack  += 10;
	this->defense += 10;

	cout << this->name << "의 고무!" << endl;
	cout << this->name << "의 능력치가 올랐다!" << endl;

}

void Warrior::Passive() //Get shield
{
	this->shield += 10;
	cout << this->name << "는 방어도 10을 얻었다!" << endl;

}

void Warrior::GetDamged(int damage)
{
	damage = damage * (1/(1+(this->defense)*0.01f));
	this->shield -= damage;
	if (this->shield > damage)
	{
		this->shield -= damage;
		
	}
	else
	{
		this->shield -= damage;
		this->hp += this->shield;

		cout << this->name << "의 방패가 파괴됐다!" << endl;
		cout << this->name << "이(가)"<<(- 1) * this->shield << "의 피해를 입었다!" << endl;
		this->shield = 0;
	}
	
	
}
