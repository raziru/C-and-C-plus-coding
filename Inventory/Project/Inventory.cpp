#include "Framework.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::PushBack(Item item)
{
	
	list.push_back(item);
}

void Inventory::PopBack()
{
	list.pop_back();
}

void Inventory::Insert(Item item, UINT index)
{
	list.insert(list.begin() + index, item);
}

void Inventory::Remove(UINT index)
{
	list.erase(list.begin() + index);
}

void Inventory::RandomInput(UINT input)
{
	for (int i = 0; i < input; i++)
	{
		Type input = (Type)(rand() % 3 + 1 );
		string type = "";
		UINT   ID = 0;
		UINT   price = 0;
		int    stat = 0;
		string feature = "";
		switch (input)
		{
		case WEAPON:
			type = "Weapon";
			ID = rand() % 30;
			price = rand() % 100 + 10000;
			stat = rand() % 20 + 10;
			feature = "무기입니다.";
			break;
		case ARMOR:
			type = "Armor";
			ID = rand() % 30 + 30;
			price = rand() % 100 + 5000;
			stat = rand() % 30 + 20;
			feature = "방어구입니다.";

			break;
		case ACCESSORY:
			type = "Accesory";
			ID = rand() % 30 + 60;
			price = rand() % 100 + 3000;
			stat = rand() % 10 + 10;
			feature = "악세입니다.";

			break;
		default:
			break;
		}

		Item item;
		item.SetInfo(type, ID, price, stat, feature);
		list.push_back(item);
	}
	cout << "무작위 아이템 "<<input<<"개를 생성했습니다." << endl;
}

Item Inventory::AT(UINT index)
{
    return list[index];
}

void Inventory::ChangeItem(Item item, UINT index)
{

	list[index].Type    = item.Type;
	list[index].ID      = item.ID;
	list[index].price   = item.price  ;
	list[index].stat    = item.stat   ;
	list[index].feature = item.feature;
}

UINT Inventory::Size()
{
    return list.size();
}

void Inventory::Print()
{
	for (UINT i = 0; i < list.size(); i++)
	{
		cout << i << "번째 물건" << endl;
		list[i].ShowInfo();
	}
}

void Inventory::Clear()
{
	list.clear();
}
