#include "Framework.h"

enum Menu
{
	EXIT,
	BUY,
	GIVE,
	EQUIP,
	PRINT,
	FIND,
	SHOW,
	CLEAR,
	RANDOM

};

void Buy(Player* player1, Shop* shop)
{
	while (true)
	{
		int input;
		int index;
		int use;
		cout << "0. 인벤현황 1. 장비현황 2. 구매 3. 판매 4. 플레이어 스탯 5. 나가기" << endl;
		cin >> use;
		switch (use)
		{
		case 0:
			cout << "누구의 인벤을 볼까요?" << endl;
			cout << "0. " << player1->GetName() << " 1."  << shop->GetName() << endl;
			cin >> input;
			switch (input)
			{
			case 0 :
				player1->Peek();
				break;
			case 1:
				shop->Peek();
				break;
			default:
				break;
			}

			break;
		case 1:
			player1->ShowEquip();
			break;
		case 2:
			cout << "현재 보유 돈: " << player1->ShowMoney() << endl;

			cout << "상점 보유 아이템: " << endl;

			shop->Peek();
			cout << "현재 보유 돈: " << player1->ShowMoney() << endl;
			cout << "구입할 아이템의 인덱스를 입력해주세요" << endl;
			cin >> index;
			player1->BuyShop(index, shop);
			break;
		case 3:
			cout << "0. 플레이어가 매각 1. 상인이 매각" << endl;
			cin >> input;
			switch (input)
			{
			case 0:
				cout << "상점이 보유 돈: " << shop->ShowMoney() << endl;
				cout << "플레이어 보유 아이템: " << endl;
				player1->Peek();
				cout << "상점이 보유 돈: " << shop->ShowMoney() << endl;
				cout << "판매할 아이템의 인덱스를 입력해주세요" << endl;
				cin >> index;
				player1->SellItem(index, shop);
				break;
			case 1:
				cout << "판매할 아이템의 인덱스를 입력해주세요" << endl;
				cin >> index;
				shop->BreakItem(index);
				break;
			default:
				break;
			}
			break;
		case 4:
			
			player1->ShowInfo();
			break;

		default:
			break;
		}
		if (use == 5)
		{
			break;
		}

	}

}

void Give(Player* player1, Player* player2)
{
	while (true)
	{
		int input;
		int index;
		int use;
		cout << "0. 인벤현황 1. 장비현황 2. 받기 3. 주기 5. 나가기" << endl;
		cin >> use;
		switch (use)
		{
		case 0:
			cout << "누구의 인벤을 볼까요?" << endl;
			cout << "0. " << player1->GetName() << " 1." << player2->GetName() << endl;
			cin >> input;
			switch (input)
			{
			case 0:
				player1->Peek();
				break;

			case 1:
				player2->Peek();

				break;
			default:
				break;
			}

			break;
		case 1:
			player1->ShowEquip();
			break;
		case 2:
			player2->Peek();
			cout << "받을 아이템의 인덱스를 입력해주세요" << endl;
			cin >> index;
			player2->GivePlayer(index, player1);
			break;
		case 3:
			player1->Peek();
			cout << "보낼 아이템의 인덱스를 입력해주세요" << endl;
			cin >> index;
			player1->GivePlayer(index, player2);
			break;

		default:
			break;
		}
		if (use == 5)
		{
			break;
		}

	}
}

void Equip(Player* player)
{
	while (true)
	{
		int input;
		int index;
		int use;
		Type type;
		cout << "0. 인벤현황 1. 장비현황 2. 착용 3. 해제 5. 나가기" << endl;
		cin >> use;
		switch (use)
		{
		case 0:
			player->Peek();
			break;
		case 1:
			player->ShowEquip();
			break;
		case 2:
			cout << "착용할 아이템의 인덱스를 입력해주세요." << endl;
			cin >> index;
			player->Equiping(index);
			break;
		case 3:
			cout << "해제할 장비 부위를 입력해주세요. 0. Weapon 1. Armor 2. Helmet 3. Brooch" << endl;
			scanf_s(" %d", &type);
			player->Unequiping(type);
			break;

		default:
			break;
		}
		if (use == 5)
		{
			break;
		}
	}
}

void Print(Player* player1, Player* player2, Shop* shop)
{
	while (true)
	{
		int use;
		cout << "0. " << player1->GetName() << " 1." << player2->GetName() << " 2." << shop->GetName() <<
			" 5. 나가기" << endl;
		cin >> use;
		switch (use)
		{
		case 0:
			player1->Print();
			break;
		case 1:
			player2->Print();
			break;
		case 2:
			shop->Print();
			break;


		default:
			break;
		}
		if (use == 5)
		{
			break;
		}

	}
}


void Random(Player* player1, Player* player2, Shop* shop)
{
	while (true)
	{
		int use;
		int size;
		cout << "0. " << player1->GetName() << " 1. " << player2->GetName() << " 2. " << shop->GetName() <<
			" 5. 나가기" << endl;
		cin >> use;
		switch (use)
		{
		case 0:
			cout << player1->GetName() << "에게 몇개를 생성하겠습니까?" << endl;
			
			cin >> size;
			player1->RandomItem(size);
			player1->Print();
			break;
		case 1:
			cout << player2->GetName() << "에게 몇개를 생성하겠습니까?" << endl;
			
			cin >> size;
			player2->RandomItem(size);
			player2->Print();
			break;
		case 2:
			cout << shop->GetName() << "에게 몇개를 생성하겠습니까?" << endl;
			
			cin >> size;
			shop->RandomItem(size);
			shop->Print();
			break;


		default:
			break;
		}
		if (use == 5)
		{
			break;
		}

	}
}

void Find(Player* player1, Player* player2, Shop* shop)
{
	Type type;
	cout << "찾는 장비 타입을 입력하세요. 0. Weapon 1. Armor 2. Helmet 3. Brooch" << endl;
	scanf_s(" %d", &type);
	player1->Find(type);
	cout << "-------------------------------------" << endl;
	player2->Find(type);
	cout << "-------------------------------------" << endl;
	shop->Find(type);
	cout << "-------------------------------------" << endl;


}
void Clear(Player* player1, Player* player2, Shop* shop)
{
	int input;
	while (true)
	{
		cout << "누구를 초기화하나요?" << endl;
		cout << "0. " << player1->GetName() << " 1." << player2->GetName() << " 2." << shop->GetName() <<
			" 5. 나가기"<< endl;
		cin >> input;
		switch (input)
		{
		case 0:
			player1->Clear();
			cout << player1->GetName() << "을(를) 초기화했습니다." << endl;
			break;
		case 1:
			player2->Clear();
			cout << player2->GetName() << "을(를) 초기화했습니다." << endl;

			break;
		case 2:
			shop->Clear();
			cout << shop->GetName() << "을(를) 초기화했습니다." << endl;

			break;


		default:
			break;
		}
		if (input == 5)
		{
			break;
		}
	}
	
	
}

int main()
{
	srand(time(NULL));
	cout << "이름을 정해주세요" << endl;
	string name;
	cin >> name;
	Player* player = new Player(name);

	Player* enemy = new Player("다른 사람");

	Shop* shop = new Shop("상인");


	while (true)
	{
		Menu input = EXIT;
		cout << "0. 종료       1. 아이템 구매 및 판매 2. 아이템 주기 3. 장비장착 4. 인벤출력" << endl;
		cout << "5. 아이템 검색 6. 캐릭터 스탯확인 7. 인벤토리 비우기 8. 무작위 아이템 생성" << endl;
		scanf_s(" %d", &input);
		switch (input)
		{
		case EXIT:
			cout << "종료합니다." << endl;
			delete player, enemy, shop;
			return 0;
			break;
		case BUY:
			Buy(player, shop);
			break;
		case GIVE:
			Give(player, enemy);
			break;
		case EQUIP:
			Equip(player);
			break;
		case PRINT:
			Print(player, enemy, shop);
			break;
		case FIND:
			Find(player, enemy, shop);
			break;
		case SHOW:
			player->ShowInfo();
			break;
		case CLEAR:
			Clear(player, enemy, shop);
			break;
		case RANDOM:
			Random(player, enemy, shop);
			break;
		default:
			break;
		}
	}


    return 0;
}

