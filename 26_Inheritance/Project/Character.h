#pragma once



class Character
{
public:
	Character();
	Character(string name);

	virtual ~Character(); //자식에 이런 함수가 있을 거라는 것을 암시해준다.

	virtual void ShowInfo();
	string GetName() { return name;	};
	float GetHP() { return hp; };
	float GetDamage() { return damage; };

	void Attack(Character* other);
	virtual void Skill1() {};
	virtual void Skill2() {};
	virtual void Skill3() {};



	virtual void SetCombat();
	virtual void Test() = 0;


protected:
	string name   = "";
	int    level  = 0;
	float  hp     = 0.0f;
	float  damage = 0.0f;

};



