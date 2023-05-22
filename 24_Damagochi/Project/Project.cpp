#include <iostream>
#include <string>

using namespace std;

#define MIN_STAT   0
#define MAX_STAT 100

//struct State
//{
//	string name;
//	int cutStat;
//	int minStat;
//	int maxStat;
//};


enum Menu
{
	PLAY = 1,
	FEED,
	SLEEP,
	CLEAN,
	END,
	ERROR
};

class Character
{
public:
	Character()
	{

	}
	Character(string name)
		:name(name)
	{

	}
	~Character()
	{

	}
	void ShowInfo()
	{
		cout << "-----Character Info-----" << endl;
		cout << "Name   : " << name   << endl;
		cout << "Level  : " << level  << endl;
		cout << "HP     : " << hp     << endl;
		cout << "Hunger : " << hunger << endl;
		cout << "Dirty  : " << dirty  << endl;
		cout << "Exp    : " << exp    << endl;
	}
	void SetStat(int& stat, int value)
	{
		stat += value;
		if (stat > MAX_STAT)
		{
			stat = MAX_STAT;
		}
		else if(stat < MIN_STAT)
		{
			stat = MIN_STAT;
		}
	}
	void Play()
	{
		cout << this->name << "와(과) 놀아줬습니다!" << endl;
		SetStat(hunger, +40);
		SetStat(dirty , +20);
		SetStat(hp    , -20);
	}
	void Feed()
	{
		cout << this->name << "은(는) 밥을 먹었습니다!" << endl;
		SetStat(hunger, -50);
		SetStat(dirty , +20);
		SetStat(hp    , +10);
	}
	void Sleep()
	{
		cout << this->name << "이(가) 잠이 들었습니다!" << endl;
		SetStat(hunger, +20);
		SetStat(dirty , +20);
		SetStat(hp    , +50);
	}
	void Clean()
	{
		cout << this->name << "을(를) 씻겨줬습니다!" << endl;
		SetStat(hunger, +20);
		SetStat(dirty , -50);
		SetStat(hp    , +20);
	}
private:
	string name = "";
	int level   = 1;
	int hp      = 100;
	int hunger  = 0;
	int dirty   = 0;
	int exp     = 0; 

};


int main()
{
	string name;
	cout << "캐릭터의 이름을 입력해주세요!" << endl;
	cin >> name;

	Character* player = nullptr;
	player = new Character(name);

	while (true)
	{
		Menu menu;
		cout << "메뉴를 선택하세요! 1. PLAY, 2. FEED, 3. SLEEP, 4. CLEAN, 5. END_GAME" << endl;
		/*int input;
		cin >> input;
		menu = (Menu)input;*/


		getchar();
		scanf_s(" %d", &menu);

		switch (menu)
		{
			case PLAY:
				player->Play();
				break;
			case FEED:
				player->Feed();
				break;
			case SLEEP:
				player->Sleep();
				break;
			case CLEAN:
				player->Clean();
				break;
			case END:
				cout << "게임을 종료했습니다!" << endl;
				delete(player);
				return 0;
				break;
			default:
				menu = ERROR;
				break;
		}
		player->ShowInfo();
	}

	





	delete(player);
    return 0;
}

