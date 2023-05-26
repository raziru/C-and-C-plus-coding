#pragma once
class Mage;
class Mew : public Character
{
public:
	Mew();
	~Mew();
	void ShowInfo();
	void Test() {};
private:
	float mp = 0.0f;
};
