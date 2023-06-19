#include "Framework.h"
#include "Player.h"



Player::Player()
{
}



Player::~Player()
{
}

void Player::GetItem(Item item)
{
	this->inventory.push_back(item);
}

void Player::Remove(UINT index)
{
	this->inventory.erase(inventory.begin() + index);
}

void Player::Print()
{
	cout << name << "�� �κ�" << endl;
	int i = 0;
	for (Item item : this->inventory)
	{
		cout << i << "��°" << endl;
		item.ShowInfo();
		i++;
	}
}

void Player::Clear()
{
	inventory.clear();
}

void Player::SellItem(UINT index, Shop* other)
{

	if (index > inventory.size() - 1)
	{
		cout << "�ִ� �ε����� �ʰ��߽��ϴ�." << endl;
		return;
	}
	float mag = 0.7f;

	Item item = inventory.at(index);
	
	if (other->Money(item.price * mag))
	{
		this->Money((-1) * item.price * mag);
		other->GetItem(item);
		Remove(index);
	}
	else
	{
		cout << other->GetName()<<"��(��) ���̾����ϴ�." << endl;
	}
	
}

void Player::BuyShop(UINT index, Shop* other)
{
	other->SellItem(index,this);
}

void Player::GivePlayer(UINT index, Player* other)
{
	if (index > inventory.size()-1)
	{
		cout << "�ִ� �ε����� �ʰ��߽��ϴ�." << endl;
		return;
	}
	Item item = inventory.at(index);
	Remove(index);
	other->GetItem(item);
}

void Player::Find(Type type)
{
	cout << name << "�� �κ��丮 �˻� ����Դϴ�." << endl;
	for (Item item : inventory)
	{
		if (item.type == type)
		{
			item.ShowInfo();
		}
	}

	cout << name << "�� ���â �˻� ����Դϴ�." << endl;

	for (pair<Type, Item>pair : equip)
	{
		if (pair.first == type)
		{
			pair.second.ShowInfo();
		}
	}


}

void Player::Peek()
{
	int i = 0;
	i = 0;
	cout << name << "�� ���� ��: " << money<<endl;
	for (Item item : inventory)
	{
		switch (item.type)
		{
		case WEAPON:
			cout << i << ". " << item.name << "  " << "����" << endl;

			break;
		case ARMOR:
			cout << i << ". " << item.name << "  " << "��" << endl;

			break;
		case HELMET:
			cout << i << ". " << item.name << "  " << "���" << endl;

			break;
		case BROOCH:
			cout << i << ". " << item.name << "  " << "���ġ" << endl;

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

		if (input > inventory.size() - 1||inventory.size() == 0)
		{
			cout << "�ִ� �ε����� �ʰ��߽��ϴ�." << endl;
		}
		else
		{
			inventory.at(input).ShowInfo();

		}
		


	}



}


void Player::RandomItem(int times)
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

void Player::Equiping(UINT index)
{
	if (index > inventory.size() - 1||inventory.empty())
	{
		cout << "�ִ� �ε����� �ʰ��߽��ϴ�." << endl;
		return;
	}
	Item item = inventory.at(index);
	Type type = item.type;
	switch (type)
	{
	case WEAPON:
		if(equip.count(WEAPON)>0)
		{
			cout << "���⸦ ��ü�մϴ�." << endl;
			GetItem(equip[WEAPON]);

			this->attack -= equip[WEAPON].stat;

			equip.erase(WEAPON);
			equip.emplace(type, item);

			this->attack += item.stat;

		}
		else
		{
			cout << "���� ����!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->attack += item.stat;

		}
		break;
	case ARMOR:
		if (equip.count(ARMOR) > 0)
		{
			cout << "���� ��ü�մϴ�." << endl;
			GetItem(equip[ARMOR]);

			this->defense -= equip[ARMOR].stat;

			equip.erase(ARMOR);
			equip.emplace(type, item);

			this->defense += item.stat;

		}
		else
		{
			cout << "�� ����!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->defense += item.stat;

		}
		break;
	case HELMET:
		if (equip.count(HELMET) > 0)
		{
			cout << "����� ��ü�մϴ�." << endl;
			GetItem(equip[HELMET]);

			this->maxHP -= equip[HELMET].stat;

			equip.erase(HELMET);
			equip.emplace(type, item);

			this->maxHP += item.stat;

		}
		else
		{
			cout << "��� ����!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->maxHP += item.stat;

		}
		break;
	case BROOCH:
		if (equip.count(BROOCH) > 0)
		{
			cout << "���ġ�� ��ü�մϴ�." << endl;
			GetItem(equip[BROOCH]);

			this->speed -= equip[BROOCH].stat;

			equip.erase(BROOCH);
			equip.emplace(type, item);

			this->speed += item.stat;

		}
		else
		{
			cout << "���ġ ����!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->speed += item.stat;

		}
		break;
	case NONE:
		break;
	default:
		break;
	}
}

void Player::Unequiping(Type type)
{
	switch (type)
	{
	case WEAPON:
		if (equip.count(WEAPON) > 0)
		{
			cout << "���⸦ �����մϴ�." << endl;
			GetItem(equip[WEAPON]);

			this->attack -= equip[WEAPON].stat;

			equip.erase(WEAPON);

		}
		else
		{
			cout << "���⸦ ������߽��ϴ�." << endl;

		}
		break;
	case ARMOR:
		if (equip.count(ARMOR) > 0)
		{
			cout << "���� �����մϴ�." << endl;

			GetItem(equip[ARMOR]);

			this->defense -= equip[ARMOR].stat;

			equip.erase(ARMOR);

		}
		else
		{
			cout << "���� ������߽��ϴ�." << endl;

		}
		break;
	case HELMET:
		if (equip.count(HELMET) > 0)
		{
			cout << "��並 �����մϴ�." << endl;

			GetItem(equip[HELMET]);

			this->maxHP -= equip[HELMET].stat;

			equip.erase(HELMET);

		}
		else
		{
			cout << "����� ������߽��ϴ�." << endl;

		}
		break;
	case BROOCH:
		if (equip.count(BROOCH) > 0)
		{
			cout << "���ġ�� �����մϴ�." << endl;

			GetItem(equip[BROOCH]);

			this->speed -= equip[BROOCH].stat;

			equip.erase(BROOCH);

		}
		else
		{
			cout << "���ġ�� ������߽��ϴ�." << endl;

		}
		break;
	case NONE:
		break;
	default:
		break;
	}

}

void Player::ShowEquip()
{
	if (equip.count(WEAPON)>0)
	{
		cout << "����: ����,  �̸�: "<<equip[WEAPON].name << endl;
	}
	else
	{
		cout << "����: ����,   �����" << endl;

	}
	if (equip.count(ARMOR) > 0)
	{
		cout << "����: ��, �̸�: " << equip[ARMOR].name << endl;
	}
	else
	{
		cout << "����: ��, �����" << endl;

	}
	if (equip.count(HELMET) > 0)
	{
		cout << "����: ���,   �̸�: " << equip[HELMET].name << endl;
	}
	else
	{
		cout << "����: ���,   �����" << endl;

	}
	if (equip.count(BROOCH) > 0)
	{
		cout << "����: ���ġ, �̸�: " << equip[BROOCH].name << endl;
	}
	else
	{

		cout << "����: ���ġ, �����" << endl;
	}
}

bool Player::Money(int money)
{
	if (this->money < money && money > 0)
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

void Player::ShowInfo()
{
	cout << "�̸�:     " << name << endl;
	cout << "�ִ�ü��: " << maxHP << endl;
	cout << "����ü��: " << curHP << endl;
	cout << "���ݷ�:   " << attack << endl;
	cout << "����:   " << defense << endl;
	cout << "�ӵ�:     " << speed << endl;


	cout << "��:       " << money << endl;
}
