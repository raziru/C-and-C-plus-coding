#pragma once

//���� ����
class Mew;
class Mage;
class Pikachu : public Character
{
public:
	Pikachu();
	~Pikachu();


	void ShowInfo();
	//void Attack(Mew* other);

	void Test() {};
private:
	int energy = 0;
};
