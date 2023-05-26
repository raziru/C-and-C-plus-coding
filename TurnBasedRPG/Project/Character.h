#pragma once
class Character
{
public:
	Character();
	virtual void SetName(string name);

	virtual void ShowInfo();

	virtual void Attack(Character* other) = 0; // �⺻����
	virtual void Skill_1(Character* other) = 0; // �⺻ ���
	virtual void Skill_2(Character* other) = 0; // �ʻ��
	virtual void Skill_3(Character* other) = 0 ; // �ڿ� ����
	virtual void Skill_4(Character* other) = 0; // ���� ��ȭ


	virtual void Passive() = 0; // �� ����Ǹ� �ߵ��ϴ� �ɷ�
	virtual void GetDamged(int damage) = 0;  // ���ظ� �޾��� ��
	
	int GetWin();
	void SetWin(int temp);

	int GetLose();
	void SetLose(int temp);

	int GetHP();


	virtual ~Character();

protected:
	string name = "";
	int hp = 0;
	int attack = 0;//���ݷ�
	int defense = 0;//����

	int win = 0;
	int lose = 0;

};



