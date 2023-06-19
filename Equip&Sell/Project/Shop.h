#pragma once


class Shop
{
public:
	Shop();
	Shop(string name)
		:name(name)
	{

	}
	~Shop();
	void GetItem(Item item);
	void Remove(UINT index);

	void Print();
	void Clear();

	void SellItem(UINT index, Player* other);

	void BreakItem(UINT index);


	void Equiping(UINT index);
	void Unequiping(Type type);

	void Peek();
	void Find(Type type);
	void RandomItem(int times);

	bool Money(int money);

	string GetName() { return name; };

	int ShowMoney() { return money; };

private:
	vector<Item> inventory;
	string name = "";
	UINT money = 1000000;
};

