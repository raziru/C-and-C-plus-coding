#pragma once
class Character
{
public:
	Character();
	virtual ~Character(); //�Ҹ��ڸ� virtual�� �ξ�� ����� �ڽĵ� ���� �Ҹ��Ѵ�. cout�� ������ Ȯ�ε��� �ʱ⶧���̴�.
	//����� ���ϴ��� ���������� virtual�� ���̴°� ����.
	
	virtual void ShowInfo();

	virtual void Initialize();

	virtual void BaseAttack(Character* other);

	virtual void Skill(Character* other) = 0;

	void ApplyDamage(int damage);


protected:
	string name = "";

	int curHP = 0;
	int maxHP = 0;

	int attackDamage = 0;


};


