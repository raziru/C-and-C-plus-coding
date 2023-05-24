#pragma once



class Character
{
public:
	Character();
	~Character();

	void ShowInfo();
	string GetName() { return name;	};
	float GetHP() { return hp; };
	float GetDamage() { return damage; };

	void Attack(Character* other);

protected:
	string name   = "";
	int    level  = 0;
	float  hp     = 0.0f;
	float  damage = 0.0f;

};



