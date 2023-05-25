#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << "메이지 생성!" << endl;
}

Mage::~Mage()
{
	cout << "메이지 생성!" << endl;

}

void Mage::ShowInfo()
{
		Character::ShowInfo();
		cout << "MP    : " << MP << endl;
		cout << "AP    : " << Ap << endl;
		cout << "Combat: " << combat << endl;


	
}

void Mage::SetCombat()
{
	cout << "능력 설정" << endl;
	this->combat = this->Ap + this->level;
}
