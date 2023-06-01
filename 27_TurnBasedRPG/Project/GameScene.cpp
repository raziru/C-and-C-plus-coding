#include "Framework.h"
#include "GameScene.h"


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete player;
	delete enemy;
}

void GameScene::ChooseCharacter()
{
	cout << "캐릭터를 선택하세요!" << endl;

	int input;

	cin >> input;

	switch (input)
	{
		case 1:
			player = new Garen();
			break;

		case 2:
			player = new Teemo();

			break;
		case 3:
			player = new Neeko();

			break;
		default:
			break;
	}

	Job job;

	while (true)
	{
		job = (Job)(rand() % 3);

		if (job != (input - 1))
			break;
	}

	switch (job)
	{
		case GAREN:
			enemy = new Garen();
			break;
		case TEEMO:
			enemy = new Teemo();

			break;
		case NEEKO:
			enemy = new Neeko();

			break;
		default:
			break;

	}
}

void GameScene::StartBattle()
{
	player->Initialize();
	enemy->Initialize();
	while (true)
	{
		bool playerAttack = rand() % 2;
		bool isDead = 0;
		if (playerAttack)
		{

			AutoBattle(player, enemy, isDead);

			if (isDead)
			{
				break;

			}
			AutoBattle(enemy, player, isDead);

			if (isDead)
			{
				break;

			}
		}
		else
		{
			AutoBattle(enemy, player, isDead);

			if (isDead)
			{
				break;

			}
			AutoBattle(player, enemy, isDead);

			if (isDead)
			{
				break;

			}
		}






	}

}

void GameScene::AutoBattle(Character* player1, Character* player2, bool& isDead)
{
	player1->AutoBattle(player2);
	player2->ShowInfo();


	if (player2->GetHP() <= 0)
	{
		cout << player1->GetName() << ")의 승리!" << endl;
		cout << player2->GetName() << ")의 패배!" << endl;
		isDead = true;

	}
}

