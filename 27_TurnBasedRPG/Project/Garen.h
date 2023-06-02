#pragma once

//class Neeko; --Neeko의 함수나 요소를 참조하지않고 같은 클래스인 other을 호출하기 때문에 전방 선언은 필요하지 않다!!
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
	// Character을(를) 통해 상속됨

};


