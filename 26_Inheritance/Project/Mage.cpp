#include "Framework.h"
#include "Mage.h"

Mage::Mage()
{
	cout << "������ ����!" << endl;
}

Mage::~Mage()
{
	cout << "������ ����!" << endl;

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
	cout << "�ɷ� ����" << endl;
	this->combat = this->Ap + this->level;
}
