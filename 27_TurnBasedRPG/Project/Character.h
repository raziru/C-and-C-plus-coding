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
	
	virtual void AutoBattle(Character* other);

	void ApplyDamage(int damage);

	int GetHP() { return curHP; }; //Inline 함수 : 매크로처럼 작동(메모리 할당X 문장을 바꿔치는 느낌

	string GetName() { return name; }; //Inline 함수 : 매크로처럼 작동(메모리 할당X 문장을 바꿔치는 느낌


protected:
	string name = "";

	int curHP = 0;
	int maxHP = 0;

	int attackDamage = 0;


};

