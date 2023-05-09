#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define SIZE 3

int board[SIZE][SIZE] = {};

enum ID
{
	PLAYER   = 1,
	COMPUTER = 2
};

void ShowBoard()
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

}

void PlayerInput()
{
	int row ;
	int col ;

	while (true)
	{
		printf("�÷��̾� ��ġ�� �Է��ϼ���! \n");

		scanf_s("%d %d", &row, &col);

		if (row<1 || row>SIZE || col<1 || col>SIZE)
		{
			printf("������ ��� �����Դϴ�!\n");
			continue;
		}

		if (board[row - 1][col - 1] == 0)
		{
			board[row - 1][col - 1] = PLAYER;

			ShowBoard();

			break;
		}
		else
		{
			printf("�̹� ���õ� ��ġ�Դϴ�!\n");
		}

	}

}

void ComputerInput()
{
	int row;
	int col;

	while (true)
	{
		
		row = rand() % SIZE + 1;
		col = rand() % SIZE + 1;
		
		if (row<1 || row>SIZE || col<1 || col>SIZE)
		{
			continue;
		}

		if (board[row - 1][col - 1] == 0)
		{
			for (int i = 4 - 1; i >= 0; i--)
			{
				printf("��ǻ�Ͱ� �Է����Դϴ�!...%d\n", i);
				Sleep(1000);
			}

			board[row - 1][col - 1] = COMPUTER;

			ShowBoard();

			break;
		}

	}

}

bool CheckWin(ID id)
{
	int count = 0 ;
	//����
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j] == id)
			{
				count++;
			}

			if (count == SIZE)
			{
				return true;
			}
		}
		count = 0;
	}
	//����
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[j][i] == id)
			{
				count++;
			}

			if (count == SIZE)
			{
				return true;
			}
		}
		count = 0;
	}

	// �밢��
	for (int i = 0; i < SIZE; i++)
	{
		if (board[i][i] == id)
		{
			count++;
		}

		if (count == SIZE)
		{
			return true;
		}
		
	}
	count = 0;

	//���밢��
	for (int i = 0; i < SIZE; i++)
	{
		if (board[i][SIZE-i-1] == id)
		{
			count++;
		}

		if (count == SIZE)
		{
			return true;
		}
		
	}
	count = 0;

	return false;
}
bool CheckDraw()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j]==0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand(time(NULL));
	ShowBoard();
	
	while (true)
	{
		PlayerInput();
		if (CheckWin(PLAYER))
		{
			printf("�÷��̾� �¸�!\n");
			break;
		}

		if (CheckDraw())
		{
			printf("���º��Դϴ�!\n");
			break;

		}

		ComputerInput();

		if (CheckWin(COMPUTER))
		{
			printf("��ǻ�� �¸�!\n");
			break;

		}
		if (CheckDraw())
		{
			printf("���º��Դϴ�!\n");
			break;

		}
	}

	return 0;
}