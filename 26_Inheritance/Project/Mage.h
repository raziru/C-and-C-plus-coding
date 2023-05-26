#pragma once
class Mage : public Character
{
public:
	Mage();
	
	~Mage();

	void ShowInfo();
	

	virtual void SetCombat() override;
	virtual void Test() override {} ;
private:
	float   MP = 0.0f;
	int     Ap = 0;
	int combat = 0;
};


