#include "Framework.h"
#include "PIkachu.h"

Pikachu::Pikachu()
{
	name = "피카츄";


	cout << "Pikachu   생성자 호출!" << endl;



}

Pikachu::~Pikachu()
{
	cout << "Pikachu   소멸자 호출!" << endl;

}

void Pikachu::ShowInfo()
{
	Character::ShowInfo();

	cout << "Energy: " << energy << endl;

}

//void Pikachu::Attack(Mew* other)
//{
//	//피카츄가 뮤르ㅜㄹ 공격
//	// 뮤의 체력을 피카츄의 공격력만큼 감소
//
//	cout << this->name << "이(가) " << other->GetName() << "을(를) 공격!" << endl;
//}

