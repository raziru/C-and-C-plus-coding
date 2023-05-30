#include "Framework.h"
#include "Fighter.h"


Fighter::Fighter()
{
	cout << this->name << "�������� �����߽��ϴ�!" << endl;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}

Fighter::Fighter(string name)
{
	this->name = name;
	cout << this->name << "��(��) �������� �����߽��ϴ�!" << endl;
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
	cout << "�޺�: " << this->combo << endl;
	cout << "����:  ������" << endl;
}

void Fighter::Attack(Character* other)
{
	this->combo += 1;
	cout << this->name << "�� �⺻ ����:" << endl;
	other->GetDamged(this->attack);
}

void Fighter::Skill_1(Character* other)
{
	if (combo>3)
	{
		this->combo = 0;
		cout << this->name << "�� ����ġ:" << endl;
		other->GetDamged(this->attack * 4);
	}
	else
	{
		this->combo++;
		cout << this->name << "�� ��ġ:" << endl;
		other->GetDamged(this->attack * 2);
	}
	

	
}

void Fighter::Skill_2(Character* other)
{
	if (combo > 4)
	{
		this->combo = 0;
		cout << this->name << "�� ������ġ!" << endl;
		other->GetDamged(this->attack * 6);
	}
	else
	{
		this->combo++;
		cout << this->name << "�� ��ġ:" << endl;
		other->GetDamged(this->attack * 3);
	}
}

void Fighter::Skill_3(Character* other)
{
	this->combo += 5;
	cout << this->name << "�� ǰ��:"<<endl<<"�޺��� 5�����մϴ�!" << endl;
}

void Fighter::Skill_4(Character* other)
{
	this->hp += 30;
	this->attack += 20;
	this->defense += 20;
	cout << this->name << "�� ������:"<< endl<<" ü�°� ������ �����մϴ�!" << endl;

}

void Fighter::Passive()
{
	this->attack += 5;
	cout << this->name << "�� �нú�:" << endl;
	cout << this->name << "�� ���ݷ��� 5 �����մϴ�." << endl;

}

void Fighter::GetDamged(int damage)
{
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	this->hp -= damage;
	cout << this->name << "��(��) " << damage << "�� ���ظ� �Ծ���!" << endl;

}

void Fighter::ShowTrait()
{
	cout << "�������� ��������� �޺��� �װ� ��Ʈ���� ��ȭ�ϴ� Ŭ�����Դϴ�." << endl;
	cout << "1. �⺻���� 2. ��ġ(����ġ)  3. ��ġ(������ġ) 4. ǰ�� 5. ������" << endl;
	cout << "���� �޺��� �����ϸ� ��ȭ�� ����� ����մϴ�." << endl;


}

void Fighter::Reset()
{
	cout << this->name << "��(��) �غ��ŵ�ϴ�!" << endl;
	this->combo = 0;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}
