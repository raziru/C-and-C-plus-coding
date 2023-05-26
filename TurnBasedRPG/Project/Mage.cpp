#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << this->name << "�� ������� �����߽��ϴ�!" << endl;
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
	cout << "������: " << this->mp << endl;
	cout << "��ȭ����: " << (this->powerup ? "��ȭ��" : "�Ϲ�") << endl;

}

void Mage::Attack(Character* other)//�⺻ ����
{
	other->GetDamged(this->attack);
	this->mp += 10;
	cout << this->name << "�� �⺻ ����!" << endl;
}

void Mage::Skill_1(Character* other)//�⺻ ���
{
	if (mp >= 20)
	{
		if (powerup)
		{
			other->GetDamged(this->attack * 3);
			this->mp -= 20;
			cout << this->name << "�� ��ȭ�� ���̾!" << endl;
			powerup = false;
		}
		else
		{
			other->GetDamged(this->attack * 2);
			this->mp -= 20;
			cout << this->name << "�� ���̾!" << endl;
		}
	}
	else
	{
		cout << this->name << "�� ������ �����մϴ�!" << endl;

	}
}

void Mage::Skill_2(Character* other)//�ʻ��
{
	if (mp >= 80)
	{
		if (powerup)
		{
			other->GetDamged(this->attack * 8);
			this->mp -= 80;
			cout << this->name << "�� �ʻ� ���׿�!" << endl;
			powerup = false;
		}
		else
		{
			other->GetDamged(this->attack * 5);
			this->mp -= 80;
			cout << this->name << "�� ���̾!" << endl;
		}
	}
	else
	{
		cout << this->name << "�� ������ �����մϴ�!" << endl;

	}
}

void Mage::Skill_3(Character* other)//�ڿ�����
{

	this->mp += 30;
	this->powerup = true;
	cout << this->name << "�� ����ȸ��! ��ų�� ��ȭ�˴ϴ�!" << endl;

}

void Mage::Skill_4(Character* other)//���� ��ȭ
{
	this->powerup = true;
	this->attack  += 10;
	this->defense += 10;
	cout << this->name << "�� ��ȭ! ���Ȱ� ��ų�� ��ȭ�˴ϴ�!" << endl;
	cout << "������ �޴� ���ذ� �����մϴ�!" << endl;

}

void Mage::Passive()
{
	this->mp += 10;
	cout << this->name << "�� ������ 10 ȸ���˴ϴ�." << endl;
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
