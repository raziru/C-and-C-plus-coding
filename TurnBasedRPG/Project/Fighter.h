#pragma once


class Vampire;
class Fighter:public Character
{
public:
	Fighter();
	Fighter(string name);
	~Fighter();
	// Character을(를) 통해 상속됨
	

	virtual void ShowInfo() override;

	virtual void Attack(Character* other) override;

	virtual void Skill_1(Character* other) override;

	virtual void Skill_2(Character* other) override;

	virtual void Skill_3(Character* other) override;

	virtual void Skill_4(Character* other) override;

	virtual void Passive() override;

	virtual void GetDamged(int damage) override;

	virtual void ShowTrait() override;
private:
	int combo = 0;

	


	// Character을(를) 통해 상속됨
	virtual void Reset() override;

};



