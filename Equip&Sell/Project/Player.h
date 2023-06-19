#pragma once

enum Type
{
	WEAPON,
	ARMOR,
	HELMET,
	BROOCH,
	NONE
};

struct Item
{

	void SetInfo(Type type, string name, int stat, int price)
	{
		this->type = type;
		this->name = name;
		this->stat = stat;
		this->price = price;
	}


	void ShowInfo()
	{
		switch (type)
		{
		case WEAPON:
			cout << "����: ����" << endl;

			break;
		case ARMOR:
			cout << "����: ��" << endl;

			break;
		case HELMET:
			cout << "����: ����" << endl;

			break;
		case BROOCH:
			cout << "����: ���ġ" << endl;

			break;
		case NONE:
			break;
		default:
			break;
		}


		cout << "�̸�: " << name << endl;
		cout << "����: " << stat << endl;
		cout << "����: " << price << endl;

	}




	Type type = NONE;
	string name = "";
	int stat = 0;
	int price = 0;
};

class Shop;


class Player
{
public:
	Player();
	Player(string name)
		:name(name)
	{
		curHP = maxHP;
	};
	~Player();

	void GetItem(Item item);
	void Remove(UINT index);

	void Print();
	void Clear();

	void SellItem(UINT index, Shop* other);
	void BuyShop(UINT index, Shop* other);


	void GivePlayer(UINT index, Player* other);

	void Find(Type type);
	void Peek();

	void RandomItem(int times);
	void Equiping(UINT index);
	void Unequiping(Type type);

	void ShowEquip();

	bool Money(int money);

	string GetName() { return name; };

	int ShowMoney() { return money; };

	void ShowInfo();


private:
	string name = "";
	int maxHP = 100; //���
	int curHP = 100;
	int attack = 10;//����
	int defense = 10;//��
	int speed = 10;//��ű�

	int money = 1000;
	vector<Item> inventory;
	map<Type, Item> equip;

};



