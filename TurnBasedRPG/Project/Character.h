#pragma once
class Character
{
public:
	Character();
	

	

	virtual void ShowInfo();
	virtual void ShowRecord();



	virtual void Reset() = 0;

	virtual void Attack(Character* other) = 0; // 기본공격
	virtual void Skill_1(Character* other) = 0; // 기본 기술
	virtual void Skill_2(Character* other) = 0; // 필살기
	virtual void Skill_3(Character* other) = 0 ; // 자원 생성
	virtual void Skill_4(Character* other) = 0; // 스탯 강화


	virtual void Passive() = 0; // 턴 종료되면 발동하는 능력
	virtual void GetDamged(int damage) = 0;  // 피해를 받았을 때
	virtual void ShowTrait() = 0; // 캐릭터 설명 출력
	
	int GetWin();
	void SetWin();

	int GetLose();
	void SetLose();

	int GetHP();


	virtual ~Character();

protected:
	string name = "";
	int hp = 0;
	int attack = 0;//공격력
	int defense = 0;//방어력

	int win = 0;
	int lose = 0;

};



