#pragma once
class Neeko :public Character
{
public:
	Neeko();
	~Neeko();

	virtual void ShowInfo() override;

	virtual void Skill(Character* other) override;

	virtual void AutoBattle(Character* other) override;
private:

	int regen;
	// Character��(��) ���� ��ӵ�

};

