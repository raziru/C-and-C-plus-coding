#pragma once

enum Type
{
	WEAPON = 1,
	ARMOR,
	ACCESSORY
};
struct Item
{
	
	

	string Type    = "";
	UINT   ID      = 0;
	UINT   price   = 0;
	int    stat    = 0;
	string feature = "";
	void ShowInfo()
	{
		cout << "Á¾·ù: " << Type << endl;
		cout << "ID  : "  <<  ID << endl;

		cout << "°¡°Ý: " << price << endl;
		cout << "½ºÅÈ: " << stat << endl;
		cout << "Æ¯Â¡: " << feature << endl;
	}
	void SetInfo(string type, UINT ID, UINT price, int stat, string feature)
	{
		this->Type = type;
		this->ID = ID;
		this->price = price;
		this->stat = stat;
		this->feature = feature;
	}
};

class Inventory
{
public:
	Inventory();
	~Inventory();
	void PushBack(Item item);
	void PopBack();
	void Insert(Item item, UINT index);
	void Remove(UINT index);

	void RandomInput(UINT input);
	Item AT(UINT index);

	void ChangeItem(Item item, UINT index);

	UINT Size();
	void Print();
	void Clear();
	
private:
	vector<Item> list;
	
};

