#include "Framework.h"
#include "Vampire.h"


Vampire::Vampire()
{
	cout << this->name << "�����̾�� �����߽��ϴ�!" << endl;
	this->hp = 300;
	this->attack = 20;
	this->defense = 30;
}

Vampire::Vampire(string name)
{
	this->name = name;
	cout << this->name << "��(��) �����̾�� �����߽��ϴ�!" << endl;
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
	cout << "�Ǳ���: " << this->blood << endl;
	cout << "����:  �����̾�" << endl;
}

void Vampire::Attack(Character* other)
{
	cout << this->name << "�� �⺻ ����:" << endl;
	other->GetDamged(this->attack);
	this->GetDamged(10);
}

void Vampire::Skill_1(Character* other)
{
	if (blood > 50)
	{
		this->hp += 50;
		this->blood = 0;
		cout << this->name << "�� ����:" << endl;
		other->GetDamged(this->attack * 5);
	}
	else
	{
		cout << this->name << "�� ����:" << endl;
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
		cout << this->name << "�� ������:" << endl;
		other->GetDamged(this->attack * 5);
	}
	else if (blood > 50)
	{
		this->hp += 50;
		this->blood = 0;
		cout << this->name << "�� ����:" << endl;
		other->GetDamged(this->attack * 3);
	}
	else
	{
		cout << this->name << "�� ����:" << endl;
		other->GetDamged(this->attack * 2);
		this->GetDamged(20);
	}

}

void Vampire::Skill_3(Character* other)
{
	this->hp += 30;
	cout << this->name << "�� ����:" << endl;
	this->GetDamged(70);

}

void Vampire::Skill_4(Character* other)
{
	this->hp += 60;
	this->attack += 20;
	this->defense += 20;
	cout << this->name << "�� ġ��:"<<endl<<"ü���� ȸ���ϰ� ������ �����մϴ�!" << endl;
}

void Vampire::Passive()
{
	cout << this->name << "�� �нú�:" << endl;
	cout << this->name << "��(��) �Ǳ����� �����մϴ�!" << endl;
	this->GetDamged(5);


}

void Vampire::GetDamged(int damage)
{
	int temp = damage / 2;
	
	damage = damage * (1 / (1 + (this->defense) * 0.01f));
	this->hp -= damage;
	cout << this->name << "��(��) " << damage << "�� ���ظ� �Ծ���!" << endl;
	if (this->hp <= 0)
	{
		cout << "���� ���ظ� �Ծ� �Ǳ����� ȸ���մϴ�." << endl;
		this->hp += this->blood;
		this->blood = 0;
	}
	this->blood += temp;
	cout << this->name << "��(��) " << temp << "��ŭ �Ǳ����� �����ߴ�!" << endl;
}

void Vampire::ShowTrait()
{
	cout << "�����̾�� ���ظ� �Ͽ� ���ط��� ��ȭ�ϴ� Ŭ�����Դϴ�." << endl;
	cout << "1. �⺻���� 2. ����/���� 3. ����/����/������ 4. ���� 5. ġ��" << endl;
	cout << "���ظ� ������ �Ǳ����� ����ǰ� ���� ��ġ�� �Ǹ� ��ȭ�� ����� ����մϴ�." << endl;
	cout << "�����̾�� ���� ���ظ� ������ �Ǳ����� Ȱ���Ͽ� ��Ȱ�մϴ�." << endl;



}

void Vampire::Reset()
{
	this->hp = 400;
	this->attack = 10;
	this->defense = 30;
	this->blood = 0;
}
