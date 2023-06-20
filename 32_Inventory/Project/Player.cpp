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

	Item item = items[name];

	inventory.push_back(item);

	store->GetItems().erase(name);
	//store->RemoveItem(name);
}

void Player::SellItem(Store* store, string name)
{
}
