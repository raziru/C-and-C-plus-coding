#include "Framework.h"

int main()
{
	Player* player = new Player;

	player->AddItem("천갑옷", 300, ARMOR);
	player->AddItem("롱소드", 350, WEAPON);
	player->AddItem("라바돈", 360, HELMET);



	player->ShowInventory();

	cout << "장착할 아이템의 이름을 입력하세요!" << endl;

	string name;

	cin >> name;
	player->EquipItem(name);
	player->ShowEquipList();

	player->ShowInventory();

	cout << "해제할 아이템의 타입을 입력하세요! 1. WEAPON, 2. ARMOR, 3. HELMET " << endl;

	int type;

	cin >> type;
	player->UnEquipItem(ItemType(type-1));

	player->ShowEquipList();

	player->ShowInventory();

	delete player;

	//rfor로 intellisense 호출
	/*auto a = 0;
	auto b = 0.0;
	auto c = 0.0f;
	auto d = 0l;
	auto e = new Player();

	for (auto& i : {0,1,2,23})
	{
		cout << i << endl;
	}*/




	return 0;
}