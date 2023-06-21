#include "Framework.h"
#include "GameManager.h"
GameManager::GameManager()
{
	player = new Player;
	store = new Store;
}

GameManager::~GameManager()
{
	delete player;

	delete store;
}

void GameManager::ManagePlayer()
{
	while (true)
	{
		int input;
		cout << "메뉴를 선택하세요! 1. 인벤토리 출력, 2. 장착아이템 출력, 3. 아이템 장착, 4. 아이템 해제 5. 나가기" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			player->ShowInventory();
			break;
		case 2:
			player->ShowEquipList();

			break;
		case 3:
		{//switch문안에서 변수를 선언하게 될경우 지역변수이기 때문에 지역을 선언하기위해 중괄호를 사용한다.
			string name;
			cout << "장착할 아이템의 이름을 입력하세요!" << endl;
			player->ShowInventory();
			cin >> name;

			player->EquipItem(name);
			player->ShowEquipList();
		}

			break;//break위치는 상관없다.
		case 4:
		{
			int type;
			cout << "해제할 아이템의 종류를 입력하세요! 1. WEAPON 2. ARMOR 3. HELMET" << endl;

			player->ShowEquipList();
			cin >> type;
			player->UnEquipItem((ItemType)type);
		}
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
	}
}

void GameManager::ManageStore()
{
	while (true)
	{
		int input;
		cout << "메뉴를 선택하세요! 1. 상점리스트 출력, 2. 아이템 구매, 3. 아이템 판매 4. 나가기" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			store->ShowItems();
			break;
		
		case 2:
		{//switch문안에서 변수를 선언하게 될경우 지역변수이기 때문에 지역을 선언하기위해 중괄호를 사용한다.
			string name;
			cout << "구매할 아이템의 이름을 입력하세요!" << endl;
			store->ShowItems();

			cin >> name;

			player->BuyItem(store,name);
			player->ShowInventory();
		}

		break;//break위치는 상관없다.
		case 3:
		{
			string name;
			cout << "판매 아이템의 이름을 입력하세요!" << endl;
			player->ShowInventory();

			cin >> name;

			player->SellItem(store, name);
			store->ShowItems();
		}
		break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
