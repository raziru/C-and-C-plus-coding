#include "Framework.h"
#include "Store.h"


Store::Store()
{
	items.emplace("õ����", Item("õ����", 300, ARMOR));
	items.emplace("�ռҵ�", Item("�ռҵ�", 350, WEAPON));
	items.emplace("��ٵ�", Item("��ٵ�", 360, HELMET));
}

Store::~Store()
{
}

void Store::ShowItems()
{
	cout << "-----Store Item List ------" << endl;
	for (pair<string, Item> pair : items)
	{
		pair.second.ShowInfo();
	}
}

void Store::RemoveItem(string name)
{
	items.erase(name);
}
