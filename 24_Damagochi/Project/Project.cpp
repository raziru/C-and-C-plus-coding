#include <iostream>
#include <string>
#include <conio.h>

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
	PLAY = 49,
	FEED,
	SLEEP,
	CLEAN,
	FIGHT,
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

		SetExp(+100);
	}
	void Feed()
	{
		cout << this->name << "은(는) 밥을 먹었습니다!" << endl;
		SetStat(hunger, -50);
		SetStat(dirty , +20);
		SetStat(hp    , +10);
		
		SetExp(+50);

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
		
		SetExp(+30);

	}
	void SetExp(int value)
	{
		
		exp += value;

		if (exp>=level*MAX_STAT)
		{
			exp -= level * MAX_STAT;
			level++;

			cout << name << "이 레벨업 했습니다!" << endl;
		}
	}

	bool Battle(Character* enemy)
	{
		if (this->level >= enemy->level)//객체가 달라도 클래스 이름이 같으면 private에 접근할 수 있다.
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int GetLevel() { return level; }

private:
	string name = "";
	int level   = 1;
	int hp      = 100;
	int hunger  = 0;
	int dirty   = 0;
	int exp     = 0; 

};

bool Battle(Character* player1, Character* player2)
{
	if (player1->GetLevel() >= player2->GetLevel())
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	string name;
	cout << "캐릭터의 이름을 입력해주세요!" << endl;
	cin >> name;

	Character* player = nullptr;
	Character* enemy = nullptr;

	player = new Character(name);
	enemy = new Character("적");


	while (true)
	{
		Menu menu;

		cout << "메뉴를 선택하세요! 1. PLAY, 2. FEED, 3. SLEEP, 4. CLEAN, 5. FIGHT 6.END_GAME" << endl;
		/*int input;
		cin >> input;
		menu = (Menu)input;*/

		/*getchar();
		scanf_s(" %d", &menu);*/

		char input;
		while (true)
		{
			if (_kbhit())
			{
				input = _getch();
				break;
			}
		}

		menu = (Menu)input;
		system("cls");

		

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
				delete(enemy);
				return 0;
				break;
			case FIGHT:
				
				if (player->Battle(enemy))
					cout << "Player 승리!" << endl;
				else
					cout << "Enemy 승리!" << endl;
				
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

