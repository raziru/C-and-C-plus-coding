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
			//cout << item.name << "�� �����߽��ϴ�." << endl;
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
		cout << "�ش� ������ ��� �������� �ʾҽ��ϴ�." << endl;
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
		cout << "������ �ش� �������� �������� �ʽ��ϴ�." << endl;
		return;
	}

	Item item = items[name];

	if (this->money<item.price)
	{
		cout << "�ܾ��� �����մϴ�!" << endl;
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
		if (inventory.at(i).name == name)//at�� ����ó���� �Ǿ��ִ�.
		{
			this->money += inventory[i].price * 0.7f;

			store->GetItems().emplace(name, inventory[i]);

			inventory.erase(inventory.begin() + i);
			
			return;//vector�� �ߺ��� �㰡�ϱ� ������ �ϳ��� �����ؾ��ϴ� ��� ���߿� ���� ���� �ʿ��ϴ�.
		}
	}

	cout << "�ش� �������� �κ��丮�� �������� �ʽ��ϴ�." << endl;

}
