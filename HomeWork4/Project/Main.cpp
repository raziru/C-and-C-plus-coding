#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5

int main()
{
	
	int map[N][N] = {};

	int X, Y;

	bool playerWin = false;
	bool cpuWin = false;

	bool winX; //열검사
	bool winY; //행검사
	bool winD; //대각선 검사
	bool winDR;//역대각선 검사

	bool replay = false;

	bool playerTurn;

	srand(time(NULL));

	int first = rand() % 2;

	printf("플레이어는 1, 컴퓨터는 2입니다.\n\n");

	if (first==0)
	{
		playerTurn = true;

		printf("플레이어의 선입니다. \n\n");
	}
	else
	{
		playerTurn = false;

		printf("컴퓨터의 선입니다. \n\n");

	}
	
	int turn = 0;

	printf("게임시작!\n\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d", map[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

	while (turn < N * N)
	{

		if (playerTurn)
		{
			if (!replay)
			{
				printf("플레이어 턴! %d턴\n\n", turn + 1);
			}

			scanf_s(" %d", &X);
			scanf_s(" %d", &Y);

			if (X >= N || Y >= N || X < 0 || Y < 0)
			{
				printf("\n게임판 영역을 지켜주세요.\n\n");
				replay = true;
				continue;
			}
		}
		else
		{
			if (!replay)
			{
				printf("컴퓨터의 턴! %d턴\n\n", turn + 1);
			}

			X = rand() % N;
			Y = rand() % N;
		}

		if (map[X][Y] != 0)
		{
			if (playerTurn)
			{
				printf("\n이미 선택된 곳입니다.\n\n");
			}
			replay = true;
			continue;
		}
		else
		{
			if (playerTurn)
			{
				map[X][Y] = 1; //player는 1
				playerTurn = false;
			}
			else
			{
				map[X][Y] = 2; //cpu는 2
				playerTurn = true;

			}
			replay = false;
		}
		
		printf("\n");
	
		for (int i = 0; i < N; i++)
		{
			int checkX = map[i][0]; //열확인
			int checkY = map[0][i]; //행확인
			int checkD = map[0][0]; //대각선 확인
			int checkDR = map[N-1][0]; //역대각선 확인

			winX = true;
			winY = true;
			winD = true;
			winDR =true;

			for (int j = 0; j < N; j++)
			{
				printf("%d ", map[i][j]);

				if (!(checkX == map[i][j] && checkX != 0 && winX))
				{
					winX = false;
				}

				if (!(checkY == map[j][i] && checkY != 0 && winY))
				{
					winY = false;
				}

				if (!(checkD == map[j][j] && checkD != 0 && winD))
				{
					winD = false;
				}
				
				if (!(checkDR == map[j][N - j - 1] && checkDR != 0 && winDR))
				{
					winDR = false;
				}

			}
			if (winX || winY || winD || winDR)
			{
				if (playerTurn)
				{
					cpuWin = true;
				}
				else
				{
					playerWin = true;
				}
			}
			printf("\n");
		}
		printf("\n");
		
		if (playerWin || cpuWin)
		{
			break;
		}
		
		turn++;

	}
	if (playerWin)
	{
		printf("플레이어 승리!");

	}
	else if (cpuWin)
	{
		printf("컴퓨터 승리!");
	}
	else
	{
		printf("무승부!");
	}

	return 0;
}