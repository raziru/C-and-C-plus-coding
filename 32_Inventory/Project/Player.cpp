#include "Framework.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::AddItem(string name, UINT price, ItemType type)
{
	Item item(name, price, type);

	inventory.push_back(item);
}

void Player::ShowInventory()
{
	cout << "-------- Inventory -------" << endl;

	for (Item item : inventory)
		item.ShowInfo();
	cout << "Money : " << money << endl;
}

void Player::ShowEquipList()
{
	cout << "--------Equip List--------" << endl;
	for (pair<ItemType,Item> pair : equipList)
		pair.second.ShowInfo();

}

void Player::EquipItem(string name)
{
	for (UINT i = 0; i < inventory.size(); i++)
	{
		Item item = inventory[i];
		if (item.name==name)
		{
			//cout << item.name << "을 착용했습니다." << endl;
			equipList.emplace(item.type, item);
			
			inventory.erase(inventory.begin() + i);


			return;
		}
	}
}

void Player::UnEquipItem(ItemType type)
{
	if (equipList.count(type) ==0)
	{
		cout << "해당 부위에 장비를 착용하지 않았습니다." << endl;
		return;
	}
	Item unequipItem = equipList[type];
	inventory.push_back(unequipItem);
	equipList.erase(type);

}

void Player::BuyItem(Store* store, string name)
{
	map<string, Item> items = store->GetItems();


	if (items.count(name)==0)
	{
		cout << "상점에 해당 아이템이 존재하지 않습니다." << endl;
		return;
	}

	Item item = items[name];

	if (this->money<item.price)
	{
		cout << "잔액이 부족합니다!" << endl;
		return;
	}

	inventory.push_back(item);

	store->GetItems().erase(name);
	//store->RemoveItem(name);

	this->money -= item.price;

	

}

void Player::SellItem(Store* store, string name)
{

	for (UINT i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i).name == name)//at은 예외처리가 되어있다.
		{
			this->money += inventory[i].price * 0.7f;

			store->GetItems().emplace(name, inventory[i]);

			inventory.erase(inventory.begin() + i);
			
			return;//vector는 중복을 허가하기 때문에 하나만 삭제해야하는 경우 도중에 끊는 것이 필요하다.
		}
	}

	cout << "해당 아이템이 인벤토리에 존재하지 않습니다." << endl;

}
