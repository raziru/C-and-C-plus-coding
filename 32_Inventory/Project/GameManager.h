#pragma once




class GameManager
{
public:
	GameManager();
	~GameManager();

	void ManagePlayer();
	void ManageStore();



private:
	Player* player =nullptr;
					
	Store* store =  nullptr;
};


