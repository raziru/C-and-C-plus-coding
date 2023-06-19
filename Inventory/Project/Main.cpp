#include "Framework.h"


enum Menu
{
	EXIT,
	INSERT,
	REMOVE,
	//PUSHBACK,
	//POPBACK,
	FIND,
	CHANGE,
	RANDOM,
	CLEAR,
	PRINT
};

void Insert(Inventory* inventory)
{
	Type input;
	
	string feature;
	UINT ID, price;
	Item item;
	int stat;
	cout << "무기종류를 선택해주세요. 1. 무기 2. 방어구 3. 악세" << endl;
	scanf_s(" %d", &input);
	switch (input)
	{
	case WEAPON:
		cout << "ID   : ";
		cin >> ID;
		cout << "무기 가격: ";
		cin >> price;
		cout << "스탯 : ";
		cin >> stat;
		cout << "특징 : ";
		cin >> feature;
		item.SetInfo("Weapon", ID, price, stat, feature);
		break;
	case ARMOR:
		cout << "ID   : ";
		cin >> ID;
		cout << "방어구 가격: ";
		cin >> price;
		cout << "스탯 : ";
		cin >> stat;
		cout << "특징 : ";
		cin >> feature;
		item.SetInfo("Armor", ID, price, stat, feature);
		break;
	case ACCESSORY:
		cout << "ID   : ";
		cin >> ID;
		cout << "악세 가격: ";
		cin >> price;
		cout << "스탯 : ";
		cin >> stat;
		cout << "특징 : ";
		cin >> feature;
		item.SetInfo("Accessory", ID, price, stat, feature);
		break;
	default:
		item.SetInfo("NULL", 0, 0, 0, "");
		break;

	}
	UINT index;
	cout << "몇번칸에 넣을 까요?" << endl;
	cin >> index;
	if (index>inventory->Size())
	{
		cout << "가방 크기를 초과했습니다. 가장 마지막자리에 들어갑니다." << endl;
		inventory->PushBack(item);
	}
	else
	{
		inventory->Insert(item, index);
	}
	
}

void Remove(Inventory* inventory)
{
	int index;
	cout << "삭제할 아이템의 인덱스를 적어주세요:";
	cin >> index;
	inventory->Remove(index);
}

void Find(Inventory* inventory)
{
	int index;
	cout << "찾을 아이템의 인덱스를 적어주세요:";
	cin >> index;
	if (inventory->Size() == 0)
	{
		cout << "인벤토리가 비었습니다." << endl;
	}
	else if (index > inventory->Size())
	{
		cout << "가방 크기를 초과했습니다. 가장 마지막자리를 찾습니다." << endl;
		inventory->AT(inventory->Size() - 1).ShowInfo();
	}
	else
	{
		inventory->AT(index).ShowInfo();
	}
	
}

void Change(Inventory* inventory)
{
	int index;
	cout << "바꿀 아이템의 인덱스를 적어주세요:";
	cin >> index;
	if (inventory->Size() == 0)
	{
		cout << "인벤토리가 비었습니다." << endl;
	}
	else if (index > inventory->Size())
	{
		cout << "가방 크기를 초과했습니다. 다시하세요." << endl;
	}
	else
	{
		Type input;

		string feature;
		UINT ID, price;
		Item item;
		int stat;
		cout << "무기종류를 선택해주세요. 1. 무기 2. 방어구 3. 악세" << endl;
		scanf_s(" %d", &input);
		switch (input)
		{
		case WEAPON:
			cout << "ID   : ";
			cin >> ID;
			cout << "무기 가격: ";
			cin >> price;
			cout << "스탯 : ";
			cin >> stat;
			cout << "특징 : ";
			cin >> feature;
			item.SetInfo("Weapon", ID, price, stat, feature);
			break;
		case ARMOR:
			cout << "ID   : ";
			cin >> ID;
			cout << "방어구 가격: ";
			cin >> price;
			cout << "스탯 : ";
			cin >> stat;
			cout << "특징 : ";
			cin >> feature;
			item.SetInfo("Armor", ID, price, stat, feature);
			break;
		case ACCESSORY:
			cout << "ID   : ";
			cin >> ID;
			cout << "악세 가격: ";
			cin >> price;
			cout << "스탯 : ";
			cin >> stat;
			cout << "특징 : ";
			cin >> feature;
			item.SetInfo("Accessory", ID, price, stat, feature);
			break;
		default:
			item.SetInfo("NULL", 0, 0, 0, "");
			break;

		}
		inventory->ChangeItem(item, index);
	}

}


int main()
{
	srand(time(NULL));
    Inventory* inventory = new Inventory();
	Menu input;
	while (true)
	{
		cout << "0. 종료       1. 아이템 획득        2. 아이템 제거    3. 아이템 표시" << endl;
		cout << "4. 아이템 변경 5. 무작위 아이템 생성 6. 인벤토리 비우기 7. 인벤토리 출력" << endl;
		scanf_s(" %d", &input);
		switch (input)
		{
		case EXIT:
			delete inventory;
			return 0;
			break;
		case INSERT:
			Insert(inventory);
			break;
		case REMOVE:
			Remove(inventory);
			break;
		case FIND:
			Find(inventory);
			break;
		case CHANGE:
			Change(inventory);
			break;
		case RANDOM:
			UINT i;
			cout << "몇개를 넣을까요?";
			cin >> i;
			inventory->RandomInput(i);
			break;
		case CLEAR:
			inventory->Clear();
			break;
		case PRINT:
			inventory->Print();
			break;
		default:
			break;
		}

	}

	delete inventory;


    return 0;
}

