#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << this->name << "������� �����߽��ϴ�!" << endl;
	this->hp = 300;
	this->attack = 40;
	this->defense = 20;
}

Mage::Mage(string name)
{
	this->name = name;
	cout << this->name << "��(��) ������� �����߽��ϴ�!" << endl;
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
	cout << "����:   ������" << endl;

}

void Mage::Attack(Character* other)//�⺻ ����
{
	this->mp += 10;
	cout << this->name << "�� �⺻ ����:" << endl;
	other->GetDamged(this->attack);
}

void Mage::Skill_1(Character* other)//�⺻ ���
{
	if (mp >= 20)
	{
		if (powerup)
		{
			this->mp -= 20;
			cout << this->name << "�� ��ȭ�� ���̾:" << endl;
			powerup = false;
			other->GetDamged(this->attack * 3);
		}
		else
		{
			this->mp -= 20;
			cout << this->name << "�� ���̾:" << endl;
			other->GetDamged(this->attack * 2);
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
			this->mp -= 80;
			cout << this->name << "�� ���ڵ�:" << endl;
			powerup = false;
			other->GetDamged(this->attack * 8);
		}
		else
		{
			this->mp -= 80;
			cout << this->name << "�� ����â:" << endl;
			other->GetDamged(this->attack * 5);
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
	cout << this->name << "�� ����ȸ��:"<<endl<<"������ ȸ���ǰ� ��ų�� ��ȭ�˴ϴ�!" << endl;

}

void Mage::Skill_4(Character* other)//���� ��ȭ
{
	this->powerup = true;
	this->attack  += 30;
	this->defense += 30;
	cout << this->name << "�� ��������:" << endl << " ���Ȱ� ��ų�� ��ȭ�˴ϴ�!" << endl;
	cout << "������ �޴� ���ذ� �����մϴ�!" << endl;

}

void Mage::Passive()
{
	this->mp += 10;
	cout << this->name << "�� �нú�:" << endl;

	cout << this->name << "�� ������ 10 ȸ���˴ϴ�." << endl;
}

void Mage::GetDamged(int damage)
{
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	
	if (powerup)
	{
		this->hp -= (int)(damage * (1.2f));
		cout << this->name << "��(��) " << (int)(damage * (1.2f)) << "�� ��ȭ�� ���ظ� �Ծ���!" << endl;


	}
	else
	{
		this->hp -= damage;
		cout << this->name << "��(��) " << damage << "�� ���ظ� �Ծ���!" << endl;

	}
}

void Mage::ShowTrait()
{
	cout << "������� ������ ����ϰ� ������ Ȱ���� ����� ��ȭ�ϴ� Ŭ�����Դϴ�." << endl;
	cout << "1. �⺻���� 2. ���̾/��ȭ�� ���̾ 3. ����â/���ڵ� 4. ����ȸ�� 5. ��������" << endl;
	cout << "����ȸ���� ���������� Ȱ���ϸ� ��ȭ�� ����� ����� �� �ֽ��ϴ�." << endl;
	cout << "��ȭ�� ���¸� �޴� ���ذ� �����մϴ�." << endl;



}

void Mage::Reset()
{
	cout << this->name << "��(��) �غ��ŵ�ϴ�!" << endl;
	this->mp = 0;
	this->hp = 300;
	this->attack = 40;
	this->defense = 20;
}
