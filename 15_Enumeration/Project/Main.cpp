#include<stdio.h>

/*
������ (Enumeration, enum) : ����� �����ϴ� ���, ����� �̸��� �ٿ��ش�

���ο� �������� ����� ��



��ũ�� (Macro) : ��ó���⿡�� ó�� -- �ؽ�Ʈ ��ü, ġȯ





*/

/*
Player / Computer

N X N ¥�� ����ĭ���� ������ ���� �ϼ��ϴ� ����� �¸�

N�� define���� ����ũ�� ����

Player�� ��ġ�� �Է��� �޾Ƽ� ĭä���, 

Computer�� �������� ĭä��� (�̹� ä���� ĭ�� �Ǻ�)

���� �� ���� �����ư��鼭 ����

2���� �迭(arr[N][N])�� �����, 0�� ��ĭ, 1�� Player, 2�� Computer

Ȥ�� char�� O X

�¸� ����: �����ٷ� �ϼ�, �����ٷ� �ϼ�, �밢�� 2����

*�¸� ���θ� �Ǵ��ϴ� ���� ����*


*/

#define MAX_SIZE 150 //global variable����

enum State
{
	IDLE,//���а�, ��ü��, ���ڰ� ������ �����ϰ� ������ִ� ��ġ
	WALK,
	JUMP

};//switch���� ���� ����.

enum Menu //!!�ð��� �����ϰ� �ڵ��� �������� ����Ų��!!
{
	GAME_START = 1,
	GAME_END

};


int main()
{
	const int SIZE = 10;

	MAX_SIZE;

	State state;

	state = IDLE;

	switch (state)
	{
	case IDLE:
		//IDLE ���� ����
		break;
	case WALK:
		//WALK ���� ����
		break;
	case JUMP:
		//JUMP ���� ����
		break;
	default:
		break;
	}

	printf("�޴��� �Է��ϼ���!\n 1. ���� ����, 2.���� ����\n");

	//int menu = 0;

	Menu menu;

	scanf_s(" %d", &menu);

	switch (menu)
	{
	case GAME_START:
		printf("���ӽ���!");
		break;
	case GAME_END:
		printf("��������!");
		break;
	default:
		break;
	}

	return 0;
}