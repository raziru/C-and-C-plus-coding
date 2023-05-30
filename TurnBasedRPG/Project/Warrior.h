#pragma once

class Mage;
class Fighter;
class Vampire;

class Warrior:public Character
{
public:
	Warrior();
	Warrior(string name);
	~Warrior();
	// Character��(��) ���� ��ӵ�

	virtual void ShowInfo() override;
	virtual void Attack(Character* other) override;

	virtual void Skill_1(Character* other) override;

	virtual void Skill_2(Character* other) override;

	virtual void Skill_3(Character* other) override;

	virtual void Skill_4(Character* other) override;

	virtual void Passive() override;

	virtual void GetDamged(int damage) override;

	virtual void ShowTrait() override; // ĳ���� ���� ���


private:

	int shield = 0; //��

	virtual void Reset() override;

	


	

};


