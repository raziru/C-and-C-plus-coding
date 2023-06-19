#pragma once

enum ItemType
{
	WEAPON,
	ARMOR,
	HELMET,
	NONE
};

struct Item
{
	Item()
	{

	}
	Item(string name, UINT price, ItemType type)
		:name(name), price(price), type(type)
	{
	}

	void ShowInfo()
	{
		cout << "------Item Info-------" << endl;

		cout << "Name  : " << name  << endl;
		cout << "Price : " << price << endl;

		string str;

		switch (type)
		{
		case WEAPON:
			str = "Weapon";
			break;
		case ARMOR:
			str = "Armor";
			break;
		case HELMET:
			str = "Helmet";
			break;
		case NONE:
			str = "None";
			break;
		default:
			break;
		}

		cout << "Type  : " << str << endl;
		cout << "--------------------------------" << endl;
	}

	string   name  = "";
	UINT     price = 0;
	ItemType type  = NONE;
};

class Player
{
public:
	Player();
	~Player();

	void AddItem(string name, UINT price, ItemType type);

	

	void ShowInventory();
	void ShowEquipList();

	void EquipItem(string name);
	void UnEquipItem(ItemType type);



private:
	vector<Item> inventory;
	map<ItemType, Item> equipList;
	UINT money = 1000;
};