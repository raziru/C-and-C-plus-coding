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
	
	virtual void AutoBattle(Character* other);

	void ApplyDamage(int damage);

	int GetHP() { return curHP; }; //Inline �Լ� : ��ũ��ó�� �۵�(�޸� �Ҵ�X ������ �ٲ�ġ�� ����

	string GetName() { return name; }; //Inline �Լ� : ��ũ��ó�� �۵�(�޸� �Ҵ�X ������ �ٲ�ġ�� ����


protected:
	string name = "";

	int curHP = 0;
	int maxHP = 0;

	int attackDamage = 0;


};

