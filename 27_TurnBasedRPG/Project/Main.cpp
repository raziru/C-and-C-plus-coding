#include "Framework.h"

int main()
{
	Character* player = new Teemo();
	Character* enemy = new Teemo();
	player->Initialize();
	 enemy->Initialize();

	player->ShowInfo();
	 enemy->ShowInfo();

	player->BaseAttack(enemy);
	enemy->Skill(player);
	enemy->Skill(player);

	enemy->Skill(player);

	enemy->Skill(player);



	player->ShowInfo();
	 enemy->ShowInfo();


	
	delete player;
	delete enemy;
	return 0;
}


