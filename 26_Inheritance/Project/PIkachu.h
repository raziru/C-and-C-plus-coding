#pragma once

//���� ����
class Mew;

class Pikachu : public Character
{
public:
	Pikachu();
	~Pikachu();


	void ShowInfo();
	//void Attack(Mew* other);
private:
	int energy = 0;
};
