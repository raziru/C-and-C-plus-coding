#pragma once

class Neeko;
class Garen:public Character
{
public:
	Garen();
	~Garen();

	virtual void ShowInfo() override;

	virtual void Skill(Character* other) override;
	
	virtual void AutoBattle(Character* other) override;
private:

	int regen;
	// Character��(��) ���� ��ӵ�

};


