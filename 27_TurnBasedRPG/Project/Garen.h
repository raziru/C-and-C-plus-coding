#pragma once

//class Neeko; --Neeko�� �Լ��� ��Ҹ� ���������ʰ� ���� Ŭ������ other�� ȣ���ϱ� ������ ���� ������ �ʿ����� �ʴ�!!
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


