#pragma once

class Garen;

class Teemo:public Character
{
public:
	Teemo();
	~Teemo();

	// Character을(를) 통해 상속됨
	virtual void ShowInfo() override;

	virtual void Initialize() override;

	virtual void BaseAttack(Character* other) override;

	virtual void Skill(Character* other) override;

	
private:

	int curMP = 0;
	int maxMP = 0;

};
