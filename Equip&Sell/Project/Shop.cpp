#include "Framework.h"
#include "Shop.h"


Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::GetItem(Item item)
{
	inventory.push_back(item);
}

void Shop::Remove(UINT index)
{
	inventory.erase(inventory.begin() + index);
}

void Shop::Print()
{
	cout << name << "의 인벤" << endl;

	int i = 0;
	for (Item item : inventory)
	{
		cout << i << "번째" << endl;
		item.ShowInfo();
		i++;
	}
}

void Shop::Clear()
{
	inventory.clear();
}

void Shop::SellItem(UINT index, Player* other)
{
	if (index > inventory.size()-1)
	{
		cout << "그 인덱스를 초과했습니다." << endl;
		return;
	}
	float mag = 1.0;
	Item item = inventory.at(index);
	if (other->Money(item.price*mag))
	{
		this->Money((-1) * item.price * mag);
		other->GetItem(item);
		Remove(index);
	}
	else
	{
		cout << other->GetName() << "이(가) 돈이없습니다." << endl;
	}
}

void Shop::BreakItem(UINT index)
{
	if (index > inventory.size() - 1)
	{
		cout << "그 인덱스를 초과했습니다." << endl;
		return;
	}

	Item item = inventory.at(index);
	cout << this->name<<"이(가) "<< item.price << "만큼 환전했습니다." << endl;
	Money( (- 1)* item.price);
	Remove(index);
}

void Shop::Equiping(UINT index)
{
}

void Shop::Unequiping(Type type)
{
}

void Shop::Peek()
{
	int i = 0;
	i = 0;
	cout << name << "의 현재 돈: " << money<<endl;

	for (Item item : inventory)
	{
		switch (item.type)
		{
		case WEAPON:
			cout << i << ". " << item.name << " " << "무기" << "가격: " << item.price << endl;

			break;
		case ARMOR:
			cout << i << ". " << item.name << " " << "방어구" << "가격: " << item.price << endl;

			break;
		case HELMET:
			cout << i << ". " << item.name << " " << "헬멧" << "가격: " << item.price << endl;

			break;
		case BROOCH:
			cout << i << ". " << item.name << " " << "브로치" << "가격: " << item.price << endl;

			break;
		default:
			break;

		}
		i++;

	}
	while (true)
	{
		
		char input2;
		cout << "인덱스로 검색하겠습니까? Y/N" << endl;
		cin >> input2;
		if (input2 == 'N' || input2 == 'n')
		{
			break;
		}

		int input;
		cout << "정보를 확인하고 싶으면 인덱스를 입력하세요." << endl;
		cin >> input;
		
		if (input > inventory.size() - 1 || inventory.size() == 0)
		{
			cout << "최대 인덱스를 초과했습니다." << endl;
		}
		else
		{
			inventory.at(input).ShowInfo();
		
		}
		
		
	}

}

void Shop::Find(Type type)
{
	cout << name << "의 인벤토리 검색 결과입니다." << endl;
	for (Item item : inventory)
	{
		if (item.type == type)
		{
			item.ShowInfo();
		}
	}
}

void Shop::RandomItem(int times)
{
	for (int i = 0; i < times; i++)
	{
		Item item;
		Type type = (Type)(rand() % 4);
		switch (type)
		{
		case WEAPON:
			item.SetInfo(type, to_string((rand() % 1000)), rand() % 30 - 5, rand() % 500 + 500);
			break;
		case ARMOR:
			item.SetInfo(type, to_string((rand() % 1000)), rand() % 30 - 5, rand() % 500 + 300);
			break;
		case HELMET:
			item.SetInfo(type, to_string((rand() % 1000)), rand() % 20 - 5, rand() % 500 + 200);
			break;
		case BROOCH:
			item.SetInfo(type, to_string((rand() % 1000)), rand() % 10 - 5, rand() % 300 + 100);
			break;
		case NONE:
			break;
		default:
			break;
		}
		GetItem(item);
	}
}

bool Shop::Money(int money)
{
	if (this->money<money&&money>0)
	{
		cout << "돈이 부족합니다." << endl;
		return false;
	}
	else
	{
		this->money -= money;
		return true;
	}
}
