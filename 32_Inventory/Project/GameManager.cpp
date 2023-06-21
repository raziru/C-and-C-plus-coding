#include "Framework.h"
#include "GameManager.h"
GameManager::GameManager()
{
	player = new Player;
	store = new Store;
}

GameManager::~GameManager()
{
	delete player;

	delete store;
}

void GameManager::ManagePlayer()
{
	while (true)
	{
		int input;
		cout << "�޴��� �����ϼ���! 1. �κ��丮 ���, 2. ���������� ���, 3. ������ ����, 4. ������ ���� 5. ������" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			player->ShowInventory();
			break;
		case 2:
			player->ShowEquipList();

			break;
		case 3:
		{//switch���ȿ��� ������ �����ϰ� �ɰ�� ���������̱� ������ ������ �����ϱ����� �߰�ȣ�� ����Ѵ�.
			string name;
			cout << "������ �������� �̸��� �Է��ϼ���!" << endl;
			player->ShowInventory();
			cin >> name;

			player->EquipItem(name);
			player->ShowEquipList();
		}

			break;//break��ġ�� �������.
		case 4:
		{
			int type;
			cout << "������ �������� ������ �Է��ϼ���! 1. WEAPON 2. ARMOR 3. HELMET" << endl;

			player->ShowEquipList();
			cin >> type;
			player->UnEquipItem((ItemType)type);
		}
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
	}
}

void GameManager::ManageStore()
{
	while (true)
	{
		int input;
		cout << "�޴��� �����ϼ���! 1. ��������Ʈ ���, 2. ������ ����, 3. ������ �Ǹ� 4. ������" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			store->ShowItems();
			break;
		
		case 2:
		{//switch���ȿ��� ������ �����ϰ� �ɰ�� ���������̱� ������ ������ �����ϱ����� �߰�ȣ�� ����Ѵ�.
			string name;
			cout << "������ �������� �̸��� �Է��ϼ���!" << endl;
			store->ShowItems();

			cin >> name;

			player->BuyItem(store,name);
			player->ShowInventory();
		}

		break;//break��ġ�� �������.
		case 3:
		{
			string name;
			cout << "�Ǹ� �������� �̸��� �Է��ϼ���!" << endl;
			player->ShowInventory();

			cin >> name;

			player->SellItem(store, name);
			store->ShowItems();
		}
		break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
