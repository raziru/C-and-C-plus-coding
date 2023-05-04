#include<stdio.h>

/*
열거형 (Enumeration, enum) : 상수를 선언하는 방법, 상수에 이름을 붙여준다

새로운 변수형을 만드는 것



매크로 (Macro) : 전처리기에서 처리 -- 텍스트 대체, 치환





*/

/*
Player / Computer

N X N 짜리 빙고칸에서 한줄을 먼저 완성하는 사람이 승리

N은 define으로 적정크기 배정

Player는 위치를 입력을 받아서 칸채우기, 

Computer는 랜덤으로 칸채우기 (이미 채워진 칸을 판별)

서로 한 번씩 번갈아가면서 진행

2차원 배열(arr[N][N])을 만들고, 0은 빈칸, 1은 Player, 2는 Computer

혹은 char로 O X

승리 조건: 가로줄로 완성, 세로줄로 완성, 대각선 2가지

*승리 여부를 판단하는 것이 중점*


*/

#define MAX_SIZE 150 //global variable느낌

enum State
{
	IDLE,//구분값, 대체값, 숫자가 얼마인지 기억안하게 만들어주는 장치
	WALK,
	JUMP

};//switch문과 같이 쓴다.

enum Menu //!!시간을 절약하고 코드의 가독성을 향상시킨다!!
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
		//IDLE 동작 실행
		break;
	case WALK:
		//WALK 동작 실행
		break;
	case JUMP:
		//JUMP 동작 실행
		break;
	default:
		break;
	}

	printf("메뉴를 입력하세요!\n 1. 게임 시작, 2.게임 종료\n");

	//int menu = 0;

	Menu menu;

	scanf_s(" %d", &menu);

	switch (menu)
	{
	case GAME_START:
		printf("게임시작!");
		break;
	case GAME_END:
		printf("게임종료!");
		break;
	default:
		break;
	}

	return 0;
}