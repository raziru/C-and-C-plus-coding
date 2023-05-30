#include "Framework.h"
#include "Warrior.h"

Warrior::Warrior()
{
	cout << this->name << "����� �����߽��ϴ�!" << endl;

	this->hp = 500;
	this->attack = 30;
	this->defense = 50;
}

Warrior::Warrior(string name)
{
	this->name = name;
	cout << this->name << "��(��) ����� �����߽��ϴ�!" << endl;

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
	cout << "����:  ����" << endl;

}

void Warrior::Attack(Character* other)//�⺻����
{
	this->shield += 10;
	cout << this->name << "�� �⺻ ����:" << endl;
	other->GetDamged(this->attack);
}

void Warrior::Skill_1(Character* other)//���� ���ĳ���
{
	this->shield -= 10;
	cout << this->name << "�� ���� ���ĳ���:" << endl;
	cout << this->name << "��(��) �� 10�� �Ҿ���!" << endl;
	other->GetDamged(this->attack*2 + this -> shield * 4);

}

void Warrior::Skill_2(Character* other)
{
	cout << this->name << "�� ���� �μ���:" << endl;
	cout << this->name << "�� ���� 0�� �ƴ�!" << endl;
	other->GetDamged(this->shield * 10);
	this->shield = 0;
	
}

void Warrior::Skill_3(Character* other)//���� �μ��� //�� ����
{
	this->shield += 50;
	cout << this->name << "�� �� ����:" << endl;
	cout << this->name << "��(��) �� 50�� �����!" << endl;

	

}

void Warrior::Skill_4(Character* other)//��
{

	this->attack  += 10;
	this->defense += 10;

	cout << this->name << "�� ��:" << endl;
	cout << this->name << "�� �ɷ�ġ�� �ö���!" << endl;

}

void Warrior::Passive() //Get shield
{
	this->shield += 10;
	cout << this->name << "�� �нú�:" << endl;

	cout << this->name << "��(��) �� 10�� �����!" << endl;

}

void Warrior::GetDamged(int damage)
{
	damage = damage * (1/(1+(this->defense)*0.1f));
	this->shield -= damage;
	if (this->shield > damage)
	{
		this->shield -= damage;
		cout << this->name << "��(��) ���з� " << damage << "�� ���ظ� ���Ҵ�!" << endl;

		
	}
	else
	{
		this->shield -= damage;
		this->hp += this->shield;

		cout << this->name << "�� ���а� �ı��ƴ�!" << endl;
		cout << this->name << "��(��) "<<(- 1) * this->shield << "�� ���ظ� �Ծ���!" << endl;
		this->shield = 0;
	}
	
	
}

void Warrior::ShowTrait()
{
	cout << "����� ���� Ȱ���Ͽ� ������ �����ϴ� Ŭ�����Դϴ�." << endl;
	cout << "1. �⺻���� 2. ���� ���ĳ��� 3. ���� �μ��� 4. �� ���� 5. ��" << endl;
	cout << "���� ���ظ� �氨�ϰ� ������ �� ����� �� �ֽ��ϴ�." << endl;


}

void Warrior::Reset()
{
	cout << this->name << "��(��) �غ��ŵ�ϴ�!" << endl;
	this->shield = 0;
	this->hp = 500;
	this->attack = 30;
	this->defense = 50;
}
