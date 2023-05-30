#include "Framework.h"
#include "Warrior.h"

Warrior::Warrior()
{
	cout << this->name << "전사로 전직했습니다!" << endl;

	this->hp = 500;
	this->attack = 30;
	this->defense = 50;
}

Warrior::Warrior(string name)
{
	this->name = name;
	cout << this->name << "이(가) 전사로 전직했습니다!" << endl;

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
	cout << "직업:  전사" << endl;

}

void Warrior::Attack(Character* other)//기본공격
{
	this->shield += 10;
	cout << this->name << "의 기본 공격:" << endl;
	other->GetDamged(this->attack);
}

void Warrior::Skill_1(Character* other)//방패 밀쳐내기
{
	this->shield -= 10;
	cout << this->name << "의 방패 밀쳐내기:" << endl;
	cout << this->name << "은(는) 방어도 10을 잃었다!" << endl;
	other->GetDamged(this->attack*2 + this -> shield * 4);

}

void Warrior::Skill_2(Character* other)
{
	cout << this->name << "의 방패 부수기:" << endl;
	cout << this->name << "의 방어도가 0이 됐다!" << endl;
	other->GetDamged(this->shield * 10);
	this->shield = 0;
	
}

void Warrior::Skill_3(Character* other)//방패 부수기 //방어도 증가
{
	this->shield += 50;
	cout << this->name << "의 방어도 증가:" << endl;
	cout << this->name << "은(는) 방어도 50을 얻었다!" << endl;

	

}

void Warrior::Skill_4(Character* other)//고무
{

	this->attack  += 10;
	this->defense += 10;

	cout << this->name << "의 고무:" << endl;
	cout << this->name << "의 능력치가 올랐다!" << endl;

}

void Warrior::Passive() //Get shield
{
	this->shield += 10;
	cout << this->name << "의 패시브:" << endl;

	cout << this->name << "은(는) 방어도 10을 얻었다!" << endl;

}

void Warrior::GetDamged(int damage)
{
	damage = damage * (1/(1+(this->defense)*0.1f));
	this->shield -= damage;
	if (this->shield > damage)
	{
		this->shield -= damage;
		cout << this->name << "이(가) 방패로 " << damage << "의 피해를 막았다!" << endl;

		
	}
	else
	{
		this->shield -= damage;
		this->hp += this->shield;

		cout << this->name << "의 방패가 파괴됐다!" << endl;
		cout << this->name << "이(가) "<<(- 1) * this->shield << "의 피해를 입었다!" << endl;
		this->shield = 0;
	}
	
	
}

void Warrior::ShowTrait()
{
	cout << "전사는 방어도를 활용하여 전투를 유지하는 클래스입니다." << endl;
	cout << "1. 기본공격 2. 방패 밀쳐내기 3. 방패 부수기 4. 방어도 증가 5. 고무" << endl;
	cout << "방어도로 피해를 경감하고 공격할 때 사용할 수 있습니다." << endl;


}

void Warrior::Reset()
{
	cout << this->name << "을(를) 준비시킵니다!" << endl;
	this->shield = 0;
	this->hp = 500;
	this->attack = 30;
	this->defense = 50;
}
