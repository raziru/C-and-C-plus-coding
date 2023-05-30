#pragma once
class Vampire:public Character
{
public:
	Vampire();
	Vampire(string name);
	~Vampire();
	// Character��(��) ���� ��ӵ�


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

	int blood = 0;
	
	virtual void Reset() override;


	

};

