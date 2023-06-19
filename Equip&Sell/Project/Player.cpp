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
	cout << name << "의 인벤" << endl;
	int i = 0;
	for (Item item : this->inventory)
	{
		cout << i << "번째" << endl;
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
		cout << "최대 인덱스를 초과했습니다." << endl;
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
		cout << other->GetName()<<"이(가) 돈이없습니다." << endl;
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
		cout << "최대 인덱스를 초과했습니다." << endl;
		return;
	}
	Item item = inventory.at(index);
	Remove(index);
	other->GetItem(item);
}

void Player::Find(Type type)
{
	cout << name << "의 인벤토리 검색 결과입니다." << endl;
	for (Item item : inventory)
	{
		if (item.type == type)
		{
			item.ShowInfo();
		}
	}

	cout << name << "의 장비창 검색 결과입니다." << endl;

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
	cout << name << "의 현재 돈: " << money<<endl;
	for (Item item : inventory)
	{
		switch (item.type)
		{
		case WEAPON:
			cout << i << ". " << item.name << "  " << "무기" << endl;

			break;
		case ARMOR:
			cout << i << ". " << item.name << "  " << "방어구" << endl;

			break;
		case HELMET:
			cout << i << ". " << item.name << "  " << "헬멧" << endl;

			break;
		case BROOCH:
			cout << i << ". " << item.name << "  " << "브로치" << endl;

			break;
		default:
			break;

		}
		i++;

	}
	while (true)
	{
		
		char input2;
		cout << "인덱스로 검색하겠습니까? Y/N" << endl;
		cin >> input2;
		if (input2 == 'N' || input2 == 'n')
		{
			break;
		}
		int input;
		cout << "정보를 확인하고 싶으면 인덱스를 입력하세요." << endl;
		cin >> input;

		if (input > inventory.size() - 1||inventory.size() == 0)
		{
			cout << "최대 인덱스를 초과했습니다." << endl;
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
		cout << "최대 인덱스를 초과했습니다." << endl;
		return;
	}
	Item item = inventory.at(index);
	Type type = item.type;
	switch (type)
	{
	case WEAPON:
		if(equip.count(WEAPON)>0)
		{
			cout << "무기를 교체합니다." << endl;
			GetItem(equip[WEAPON]);

			this->attack -= equip[WEAPON].stat;

			equip.erase(WEAPON);
			equip.emplace(type, item);

			this->attack += item.stat;

		}
		else
		{
			cout << "무기 장착!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->attack += item.stat;

		}
		break;
	case ARMOR:
		if (equip.count(ARMOR) > 0)
		{
			cout << "방어구를 교체합니다." << endl;
			GetItem(equip[ARMOR]);

			this->defense -= equip[ARMOR].stat;

			equip.erase(ARMOR);
			equip.emplace(type, item);

			this->defense += item.stat;

		}
		else
		{
			cout << "방어구 장착!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->defense += item.stat;

		}
		break;
	case HELMET:
		if (equip.count(HELMET) > 0)
		{
			cout << "헬멧을 교체합니다." << endl;
			GetItem(equip[HELMET]);

			this->maxHP -= equip[HELMET].stat;

			equip.erase(HELMET);
			equip.emplace(type, item);

			this->maxHP += item.stat;

		}
		else
		{
			cout << "헬멧 장착!" << endl;
			Remove(index);
			equip.emplace(type, item);
			this->maxHP += item.stat;

		}
		break;
	case BROOCH:
		if (equip.count(BROOCH) > 0)
		{
			cout << "브로치를 교체합니다." << endl;
			GetItem(equip[BROOCH]);

			this->speed -= equip[BROOCH].stat;

			equip.erase(BROOCH);
			equip.emplace(type, item);

			this->speed += item.stat;

		}
		else
		{
			cout << "브로치 장착!" << endl;
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
			cout << "무기를 해제합니다." << endl;
			GetItem(equip[WEAPON]);

			this->attack -= equip[WEAPON].stat;

			equip.erase(WEAPON);

		}
		else
		{
			cout << "무기를 착용안했습니다." << endl;

		}
		break;
	case ARMOR:
		if (equip.count(ARMOR) > 0)
		{
			cout << "방어구를 해제합니다." << endl;

			GetItem(equip[ARMOR]);

			this->defense -= equip[ARMOR].stat;

			equip.erase(ARMOR);

		}
		else
		{
			cout << "방어구를 착용안했습니다." << endl;

		}
		break;
	case HELMET:
		if (equip.count(HELMET) > 0)
		{
			cout << "헬멧를 해제합니다." << endl;

			GetItem(equip[HELMET]);

			this->maxHP -= equip[HELMET].stat;

			equip.erase(HELMET);

		}
		else
		{
			cout << "헬멧을 착용안했습니다." << endl;

		}
		break;
	case BROOCH:
		if (equip.count(BROOCH) > 0)
		{
			cout << "브로치를 해제합니다." << endl;

			GetItem(equip[BROOCH]);

			this->speed -= equip[BROOCH].stat;

			equip.erase(BROOCH);

		}
		else
		{
			cout << "브로치를 착용안했습니다." << endl;

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
		cout << "부위: 무기,  이름: "<<equip[WEAPON].name << endl;
	}
	else
	{
		cout << "부위: 무기,   비었음" << endl;

	}
	if (equip.count(ARMOR) > 0)
	{
		cout << "부위: 방어구, 이름: " << equip[ARMOR].name << endl;
	}
	else
	{
		cout << "부위: 방어구, 비었음" << endl;

	}
	if (equip.count(HELMET) > 0)
	{
		cout << "부위: 헬멧,   이름: " << equip[HELMET].name << endl;
	}
	else
	{
		cout << "부위: 헬멧,   비었음" << endl;

	}
	if (equip.count(BROOCH) > 0)
	{
		cout << "부위: 브로치, 이름: " << equip[BROOCH].name << endl;
	}
	else
	{

		cout << "부위: 브로치, 비었음" << endl;
	}
}

bool Player::Money(int money)
{
	if (this->money < money && money > 0)
	{
		cout << "돈이 부족합니다." << endl;
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
	cout << "이름:     " << name << endl;
	cout << "최대체력: " << maxHP << endl;
	cout << "현재체력: " << curHP << endl;
	cout << "공격력:   " << attack << endl;
	cout << "방어력:   " << defense << endl;
	cout << "속도:     " << speed << endl;


	cout << "돈:       " << money << endl;
}
