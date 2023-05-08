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

	bool winX; //���˻�
	bool winY; //��˻�
	bool winD; //�밢�� �˻�
	bool winDR;//���밢�� �˻�

	bool replay = false;

	bool playerTurn;

	srand(time(NULL));

	int first = rand() % 2;

	printf("�÷��̾�� 1, ��ǻ�ʹ� 2�Դϴ�.\n\n");

	if (first==0)
	{
		playerTurn = true;

		printf("�÷��̾��� ���Դϴ�. \n\n");
	}
	else
	{
		playerTurn = false;

		printf("��ǻ���� ���Դϴ�. \n\n");

	}
	
	int turn = 0;

	printf("���ӽ���!\n\n");

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
				printf("�÷��̾� ��! %d��\n\n", turn + 1);
			}

			scanf_s(" %d", &X);
			scanf_s(" %d", &Y);

			if (X >= N || Y >= N || X < 0 || Y < 0)
			{
				printf("\n������ ������ �����ּ���.\n\n");
				replay = true;
				continue;
			}
		}
		else
		{
			if (!replay)
			{
				printf("��ǻ���� ��! %d��\n\n", turn + 1);
			}

			X = rand() % N;
			Y = rand() % N;
		}

		if (map[X][Y] != 0)
		{
			if (playerTurn)
			{
				printf("\n�̹� ���õ� ���Դϴ�.\n\n");
			}
			replay = true;
			continue;
		}
		else
		{
			if (playerTurn)
			{
				map[X][Y] = 1; //player�� 1
				playerTurn = false;
			}
			else
			{
				map[X][Y] = 2; //cpu�� 2
				playerTurn = true;

			}
			replay = false;
		}
		
		printf("\n");
	
		for (int i = 0; i < N; i++)
		{
			int checkX = map[i][0]; //��Ȯ��
			int checkY = map[0][i]; //��Ȯ��
			int checkD = map[0][0]; //�밢�� Ȯ��
			int checkDR = map[N-1][0]; //���밢�� Ȯ��

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
		printf("�÷��̾� �¸�!");

	}
	else if (cpuWin)
	{
		printf("��ǻ�� �¸�!");
	}
	else
	{
		printf("���º�!");
	}

	return 0;
}