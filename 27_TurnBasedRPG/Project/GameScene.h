#pragma once

enum Job
{
	GAREN,
	TEEMO,
	NEEKO
};
class GameScene
{
public:
	GameScene();
	~GameScene();

	void ChooseCharacter();
	void StartBattle();

	void AutoBattle(Character* player1, Character* player2, bool& isDead);

private:
	Character* player = nullptr;
	Character*  enemy = nullptr;

};



