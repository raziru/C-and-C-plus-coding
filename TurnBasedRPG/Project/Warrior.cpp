#include "Framework.h"
#include "Warrior.h"

Warrior::Warrior()
{
	cout << this->name << "�� ����� �����߽��ϴ�!" << endl;

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
	cout << "��: " << this->shield << endl;

}

void Warrior::Attack(Character* other)//�⺻����
{
	other->GetDamged(this->attack);
	this->shield += 10;
	cout << this->name << "�� �⺻ ����!" << endl;
}

void Warrior::Skill_1(Character* other)//���� ���ĳ���
{
	other->GetDamged(this->attack + 50);
	this->shield -= 20;
	cout << this->name << "�� ���� ���ĳ���!" << endl;
	cout << this->name << "�� �� 20�� �Ҿ���!" << endl;

}

void Warrior::Skill_2(Character* other)
{
	this->shield += 50;
	cout << this->name << "�� �� ����!" << endl;
	cout << this->name << "�� �� 50�� �����!" << endl;

}

void Warrior::Skill_3(Character* other)//���� �μ��� //�� ����
{

	other->GetDamged(this->shield * 5);
	this->shield = 0;
	cout << this->name << "�� ���кμ���!" << endl;
	cout << name << "�� ���а� �ı��ƴ�!" << endl;

}

void Warrior::Skill_4(Character* other)//��
{

	this->attack  += 10;
	this->defense += 10;

	cout << this->name << "�� ��!" << endl;
	cout << this->name << "�� �ɷ�ġ�� �ö���!" << endl;

}

void Warrior::Passive() //Get shield
{
	this->shield += 10;
	cout << this->name << "�� �� 10�� �����!" << endl;

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

		cout << this->name << "�� ���а� �ı��ƴ�!" << endl;
		cout << this->name << "��(��)"<<(- 1) * this->shield << "�� ���ظ� �Ծ���!" << endl;
		this->shield = 0;
	}
	
	
}
