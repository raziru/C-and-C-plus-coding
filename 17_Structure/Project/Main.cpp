#include<stdio.h>

/*
����ü(Structure, struct) : '�پ��� ������'�� ������ ���ÿ� ������ �����ϴ� ���

typedef (type define): ������ �����ϴ� �������� ���ο� �̸��� ���� �� ���



*/



typedef unsigned int UINT; //����� ���� ������ typedef, enum, struct, class, class�� struct�� Ȯ���Ų ����

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
	(*character).isDead = isDead; //*�� ������ ã�°�
	  character->isDead = isDead; // ->�� (*����)�� �����ڷ� �ٲ㳽��


}


struct World //����ü�� ����ü�� �����ϴ�
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