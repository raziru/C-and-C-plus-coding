#pragma once

class Fighter;
class Vampire;
class Mage:public Character
{
public:
	Mage();
	Mage(string name);
	~Mage();

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

	int mp = 100;
	bool powerup = false;
	
	


	// Character��(��) ���� ��ӵ�
	virtual void Reset() override;

};



