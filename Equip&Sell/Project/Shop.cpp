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
	cout << name << "�� �κ�" << endl;

	int i = 0;
	for (Item item : inventory)
	{
		cout << i << "��°" << endl;
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
		cout << "�� �ε����� �ʰ��߽��ϴ�." << endl;
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
		cout << other->GetName() << "��(��) ���̾����ϴ�." << endl;
	}
}

void Shop::BreakItem(UINT index)
{
	if (index > inventory.size() - 1)
	{
		cout << "�� �ε����� �ʰ��߽��ϴ�." << endl;
		return;
	}

	Item item = inventory.at(index);
	cout << this->name<<"��(��) "<< item.price << "��ŭ ȯ���߽��ϴ�." << endl;
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
	cout << name << "�� ���� ��: " << money<<endl;

	for (Item item : inventory)
	{
		switch (item.type)
		{
		case WEAPON:
			cout << i << ". " << item.name << " " << "����" << "����: " << item.price << endl;

			break;
		case ARMOR:
			cout << i << ". " << item.name << " " << "��" << "����: " << item.price << endl;

			break;
		case HELMET:
			cout << i << ". " << item.name << " " << "���" << "����: " << item.price << endl;

			break;
		case BROOCH:
			cout << i << ". " << item.name << " " << "���ġ" << "����: " << item.price << endl;

			break;
		default:
			break;

		}
		i++;

	}
	while (true)
	{
		
		char input2;
		cout << "�ε����� �˻��ϰڽ��ϱ�? Y/N" << endl;
		cin >> input2;
		if (input2 == 'N' || input2 == 'n')
		{
			break;
		}

		int input;
		cout << "������ Ȯ���ϰ� ������ �ε����� �Է��ϼ���." << endl;
		cin >> input;
		
		if (input > inventory.size() - 1 || inventory.size() == 0)
		{
			cout << "�ִ� �ε����� �ʰ��߽��ϴ�." << endl;
		}
		else
		{
			inventory.at(input).ShowInfo();
		
		}
		
		
	}

}

void Shop::Find(Type type)
{
	cout << name << "�� �κ��丮 �˻� ����Դϴ�." << endl;
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
		cout << "���� �����մϴ�." << endl;
		return false;
	}
	else
	{
		this->money -= money;
		return true;
	}
}
