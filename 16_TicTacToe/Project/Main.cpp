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
		printf("플레이어 위치를 입력하세요! \n");

		scanf_s("%d %d", &row, &col);

		if (row<1 || row>SIZE || col<1 || col>SIZE)
		{
			printf("범위를 벗어난 숫자입니다!\n");
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
			printf("이미 선택된 위치입니다!\n");
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
				printf("컴퓨터가 입력중입니다!...%d\n", i);
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
	//가로
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
	//세로
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

	// 대각선
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

	//역대각선
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
			printf("플레이어 승리!\n");
			break;
		}

		if (CheckDraw())
		{
			printf("무승부입니다!\n");
			break;

		}

		ComputerInput();

		if (CheckWin(COMPUTER))
		{
			printf("컴퓨터 승리!\n");
			break;

		}
		if (CheckDraw())
		{
			printf("무승부입니다!\n");
			break;

		}
	}

	return 0;
}