#include "Framework.h"
#include "Store.h"


Store::Store()
{
	items.emplace("Ãµ°©¿Ê", Item("Ãµ°©¿Ê", 300, ARMOR));
	items.emplace("·Õ¼Òµå", Item("·Õ¼Òµå", 350, WEAPON));
	items.emplace("¶ó¹Ùµ·", Item("¶ó¹Ùµ·", 360, HELMET));
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
