#pragma once

class Neeko;
class Garen;

class Teemo:public Character
{
public:
	Teemo();
	~Teemo();

	// Character��(��) ���� ��ӵ�
	virtual void ShowInfo() override;

	virtual void Initialize() override;

	virtual void BaseAttack(Character* other) override;

	virtual void Skill(Character* other) override;

	virtual void AutoBattle(Character* other) override;

private:

	int curMP = 0;
	int maxMP = 0;


	int count = 0;
};
