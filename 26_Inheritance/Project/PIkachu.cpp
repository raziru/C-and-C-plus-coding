#include "Framework.h"
#include "PIkachu.h"

Pikachu::Pikachu()
{
	name = "��ī��";


	cout << "Pikachu   ������ ȣ��!" << endl;



}

Pikachu::~Pikachu()
{
	cout << "Pikachu   �Ҹ��� ȣ��!" << endl;

}

void Pikachu::ShowInfo()
{
	Character::ShowInfo();

	cout << "Energy: " << energy << endl;

}

//void Pikachu::Attack(Mew* other)
//{
//	//��ī�� �¸��̤� ����
//	// ���� ü���� ��ī���� ���ݷ¸�ŭ ����
//
//	cout << this->name << "��(��) " << other->GetName() << "��(��) ����!" << endl;
//}

