#pragma once
class Garen:public Character
{
public:
	Garen();
	~Garen();

	virtual void ShowInfo() override;

	virtual void Initialize() override;

	virtual void BaseAttack(Character* other) override;

	virtual void Skill(Character* other) override;
private:

	int regen;
	// Character을(를) 통해 상속됨

};


