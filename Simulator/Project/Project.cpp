#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


using namespace std;

class Character
{
public:
	Character(string name)
		:name(name)
	{
		cout << name << "가 태어났습니다!" << endl;
	}
	~Character()
	{
		cout << this->name << "와 이별했습니다." << endl;
	}
	void ShowInfo()
	{
		cout << "이름     : " << this->name   << endl;
		cout << "레벨     : " << this->level  << endl;
		cout << "경험치   : " << this->exp    << endl;
		cout << "경험치통 : " << this->expMax << endl;
		cout << "행복도   : " << this->happy*100.0f  << "%" << endl;
		cout << "포만도   : " << this->full   << "%" << endl;
		cout << "전투력   : " << this->combat << endl;
		cout << endl;
	}
	void SetLevel(int level)
	{
		this->level = level;
	}
	void SetHP(float hp)
	{
		if (hp<=0.0f)
		{
			this->hp = 0.0f;
		}
		else
		{

			this->hp = hp;
		}
	}
	void SetExp(int exp)
	{
		if (exp >= this->expMax)
		{
			this->exp = 0;
			this->expMax += 20;
			SetLevel(GetLevel() + 1);
			cout << "레벨업!" << endl;
		}
		else
		{
			this->exp = exp;
		}
	}
	void SetHappy(int happy)
	{
		if (happy<=0)
		{
			this->happy = 0;
			cout << "불행해요!" << endl;

		}
		else if (happy >= 100)
		{
			this->happy = 100;
			cout << "행복도가 가득찼습니다!" << endl;
		}
		else
		{
			this->happy = happy;
		}
	}
	void SetFull(float full)
	{
		if (full <= 0)
		{
			this->full = 0;
			cout << "배고파요!" << endl;

		}
		else if (full >= 100)
		{
			this->full = 100;
			cout << "배가 가득찼습니다!" << endl;
		}
		else
		{
			this->full = full;
		}
	}
	void SetCombat()
	{
		this->combat = this->level*10;
	}
	void SetClean(int clean)
	{
		this->clean = clean;
	}
	string GetName()
	{
		return this->name;
	}
	int GetLevel()
	{
		return this->level;
	}
	float GetHp()
	{
		return this->hp;
	}
	int GetExp()
	{
		return this->exp;
	}
	int GetHappy()
	{
		return this->happy;
	}
	float GetFull()
	{
		return this->full;
	}
	float GetCombat()
	{
		return this->combat;
	}
	int GetClean()
	{
		return this->clean;
	}

	
	void Play()
	{
		SetHappy(GetHappy() + 40);
		cout << "놀아주기 완료! " << endl;
		cout << "현재 행복도: " << GetHappy() << "%" << endl;
	}
	void Eat()
	{
		SetFull(GetFull() + 40);
		cout << "식사 완료!" << endl;
		cout << "현재 포만도: " << GetFull() << "%" << endl;
	}
	void Train()
	{
		if (GetFull() <= 0 || GetHappy() <= 0)
		{
			cout << "훈련을 거부합니다." << endl;
		}
		else
		{
			SetExp(GetExp() + 100);
			cout << "훈련완료!" << endl;
			SetCombat();
			SetHP(GetLevel() * 100.0f);
			SetFull(GetFull() - 20);
			SetHappy(GetHappy() - 20);

			ShowInfo();
		}
		SetFull(GetFull());
		SetHappy(GetHappy());
		
		

	}
	void Dirty()
	{
		SetClean(GetClean() + rand() % 10);
		cout << "현재 청결도: " << GetClean() << endl;
		if (GetClean() >= 100)
		{
			cout << "방이 너무 더럽습니다!" << endl;
			SetHappy(GetHappy() - 30);
		}
		cout << endl;

	}
	void Clean()
	{
		cout << "청소하였습니다." << endl;
		SetFull(GetFull() - 10);
		SetHappy(GetHappy() - 10);
		clean = 0;

	}

private:
	string name;
	int level = 1;
	float hp = 100.0f;
	float full = 50.0f;
	int happy = 20;
	int exp = 0;
	int expMax = 100;
	int combat = level*10 ;
	int clean = 0;
};

bool Battle(Character* player) 
{
	Character* enemy;

	enemy = new Character("enemy");
	enemy->SetLevel(rand() % 10 + 1);
	enemy->SetHP(enemy->GetLevel() * 100.0f);
	enemy->SetCombat();
	enemy->ShowInfo();

	int playerAttack;
	int enemyAttack;
	int temp;
	char answer;
	while (true)
	{
		cout << "공격하시겠습니까? (Y/N): ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			playerAttack = rand() % 100 + player->GetCombat();
			enemyAttack = rand() % 100 + enemy->GetCombat();

			if (playerAttack > enemyAttack)
			{
				cout << player->GetName() << "의 공격!" << endl;
				temp = rand() % 100 + 1;
				cout << temp << "의 데미지" << endl;

				enemy->SetHP(enemy->GetHp() - temp);
			}
			else if (playerAttack < enemyAttack)
			{
				cout << enemy->GetName() << "의 공격!" << endl;
				temp = rand() % 100 + 1;
				cout << temp << "의 데미지" << endl;
				player->SetHP(player->GetHp() - temp);
			}

			cout << player->GetName()<< "의 남은체력: " << player->GetHp() << endl;
			cout << enemy->GetName() << "의 남은체력: " << enemy->GetHp() << endl;
		}
		else
		{
			cout << "도망쳤습니다..." << endl;
			return false;
		}

		if (player->GetHp() <= 0)
		{
			cout << enemy->GetName()  << "승리!" << endl;
			delete(enemy);
			return false;
		}
		else if(enemy->GetHp() <= 0)
		{
			cout << player->GetName() << "승리!" << endl;
			delete(enemy);
			return true;
		}
		
	}

}


int main()
{
	srand(time(NULL));
	string name;
	cout << "이름을 정해주세요:";
	cin >> name;
	Character* player;
	player = new Character(name);
	int input;
	bool gameover = false;
	char answer;
	player->ShowInfo();
	while (true)
	{
		player->Dirty();
		cout << "정보보기: 0/밥먹이기: 1/놀아주기: 2/훈련하기: 3" << endl;
		cout << "청소하기: 4/전투하기: 5/이별하기: 6" << endl<<endl;
		cout << "행동을 입력해주세요: ";
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 0:
			cout << "현재 상태" << endl;

			player->ShowInfo();
			break;
		case 1:
			player->Eat();
			break;
		case 2:
			player->Play();
			break;
		case 3:
			player->Train();
			break;
		case 4:
			player->Clean();
			break;
		case 5:
			if (Battle(player))
			{
				player->SetExp(player->GetExp()+10000.0f);
			}
			else
			{
				cout << "이별하시나요?(Y/N): ";
				cin >> answer;
				if (answer == 'Y' || answer == 'y')
					gameover = true;
				else
				{
					gameover = false;
					cout << "행복도, 포만도 감소..." << endl;
					player->SetHP(player->GetLevel() * 100.0f);
					player->SetFull(player->GetFull() - 30);
					player->SetHappy(player->GetHappy() - 30);
					cout << "현재 행복도: " << player->GetHappy() << "%" << endl;
					cout << "현재 포만도: " << player->GetFull() << "%" << endl;

				}
			}
			break;
		case 6:
			cout << "이별하시나요?(Y/N): ";
			cin >> answer;
			if(answer=='Y' || answer == 'y')
				gameover = true;
			else
			{
				gameover = false;
			}
			break;
		default:
			break;
		}
		
		if (gameover)
		{
			break;
		}
		
		cout << endl;
	}
	delete player;

	cout << "게임을 종료합니다." << endl;

    return 0;
}

