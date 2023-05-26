#pragma once
class Mage:public Character
{
public:
	Mage();
	
	~Mage();

	// Character을(를) 통해 상속됨

	virtual void ShowInfo() override;

	virtual void Attack(Character* other) override;

	virtual void Skill_1(Character* other) override;

	virtual void Skill_2(Character* other) override;

	virtual void Skill_3(Character* other) override;

	virtual void Skill_4(Character* other) override;

	virtual void Passive() override;

	virtual void GetDamged(int damage) override;

private:

	int mp = 100;
	bool powerup = true;
	
	

};



