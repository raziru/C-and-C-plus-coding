#include "Framework.h"
#include "Fighter.h"


Fighter::Fighter()
{
	cout << this->name << "격투가로 전직했습니다!" << endl;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}

Fighter::Fighter(string name)
{
	this->name = name;
	cout << this->name << "이(가) 격투가로 전직했습니다!" << endl;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}

Fighter::~Fighter()
{
}


void Fighter::ShowInfo()
{

	Character::ShowInfo();
	cout << "콤보: " << this->combo << endl;
	cout << "직업:  격투가" << endl;
}

void Fighter::Attack(Character* other)
{
	this->combo += 1;
	cout << this->name << "의 기본 공격:" << endl;
	other->GetDamged(this->attack);
}

void Fighter::Skill_1(Character* other)
{
	if (combo>3)
	{
		this->combo = 0;
		cout << this->name << "의 강펀치:" << endl;
		other->GetDamged(this->attack * 4);
	}
	else
	{
		this->combo++;
		cout << this->name << "의 펀치:" << endl;
		other->GetDamged(this->attack * 2);
	}
	

	
}

void Fighter::Skill_2(Character* other)
{
	if (combo > 4)
	{
		this->combo = 0;
		cout << this->name << "의 폭발펀치!" << endl;
		other->GetDamged(this->attack * 6);
	}
	else
	{
		this->combo++;
		cout << this->name << "의 펀치:" << endl;
		other->GetDamged(this->attack * 3);
	}
}

void Fighter::Skill_3(Character* other)
{
	this->combo += 5;
	cout << this->name << "의 품새:"<<endl<<"콤보가 5증가합니다!" << endl;
}

void Fighter::Skill_4(Character* other)
{
	this->hp += 30;
	this->attack += 20;
	this->defense += 20;
	cout << this->name << "의 숨고르기:"<< endl<<" 체력과 스탯이 증가합니다!" << endl;

}

void Fighter::Passive()
{
	this->attack += 5;
	cout << this->name << "의 패시브:" << endl;
	cout << this->name << "의 공격력이 5 증가합니다." << endl;

}

void Fighter::GetDamged(int damage)
{
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	this->hp -= damage;
	cout << this->name << "이(가) " << damage << "의 피해를 입었다!" << endl;

}

void Fighter::ShowTrait()
{
	cout << "격투가는 전투기술로 콤보를 쌓고 터트리는 강화하는 클래스입니다." << endl;
	cout << "1. 기본공격 2. 펀치(강펀치)  3. 펀치(폭발펀치) 4. 품새 5. 숨고르기" << endl;
	cout << "일정 콤보에 도달하면 강화된 기술을 사용합니다." << endl;


}

void Fighter::Reset()
{
	cout << this->name << "을(를) 준비시킵니다!" << endl;
	this->combo = 0;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}
