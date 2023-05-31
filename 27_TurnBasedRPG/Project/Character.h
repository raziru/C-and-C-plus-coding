#pragma once
class Character
{
public:
	Character();
	virtual ~Character(); //소멸자를 virtual로 두어야 상속한 자식도 같이 소멸한다. cout이 없으면 확인되지 않기때문이다.
	//상속을 안하더라도 습관적으로 virtual을 붙이는게 좋다.
	
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


