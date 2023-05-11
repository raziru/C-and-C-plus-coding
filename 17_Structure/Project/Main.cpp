#include<stdio.h>

/*
구조체(Structure, struct) : '다양한 변수형'의 변수를 동시에 여러개 선언하는 방법

typedef (type define): 기존에 존재하는 변수형에 새로운 이름을 붙일 때 사용



*/



typedef unsigned int UINT; //사용자 정의 변수형 typedef, enum, struct, class, class는 struct를 확장시킨 개념

//typedef struct
//{
//	int	level;
//	float hp;
//	bool isDead;
//	
//} Character;

enum State
{
	IDLE,
	WALK
};

struct Character
{
	void Print()
	{
		printf("Hello World!");
	}

	int	  level;
	float hp;
	bool  isDead;
	State state;

};

void ShowInfo(Character character)
{
	printf("LEVEL  : %d\n", character.level );
	printf("HP     : %f\n", character.hp    );
	printf("ISDEAD : %d\n", character.isDead);

}

void SetInfo(Character* character, int level, float hp, bool isDead)
{
	(*character).level  = level;
	(*character).hp     = hp;
	(*character).isDead = isDead; //*는 원본을 찾는것
	  character->isDead = isDead; // ->는 (*변수)를 연산자로 바꿔낸것


}


struct World //구조체안 구조체가 가능하다
{
	Character player;
	Character enemy;

	UINT num;

	int arr[10];

	Character* pPlayer;

};

int main()
{

	UINT n = 0;
	
	Character player;
	player.hp     = 100.0f;
	player.level  = 10;
	player.isDead = false;

	//player.Print();

	Character enemy;
	enemy.hp     = 50.0f;
	enemy.level  = 5;
	enemy.isDead = true;

	World world;

	world.player.hp;
	world.enemy.hp;

	ShowInfo(player);
	SetInfo(&player, 20, 200.0f, true);
	printf("\n");
	ShowInfo(player);

//	ShowInfo(enemy);

	return 0;
}