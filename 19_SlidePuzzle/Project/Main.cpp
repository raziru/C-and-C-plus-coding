#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define SIZE 4

int board[SIZE][SIZE] = {};

struct Point
{
	int row = SIZE - 1;
	int col = SIZE - 1;
};

Point point;

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

void Initialize()
{
	int count = 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = count++;
		}
	}
	board[SIZE - 1][SIZE - 1] = 0;
}
void PrintBoard()
{

	system("cls");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Move(Direction dir)
{
	switch (dir)
	{
		case LEFT:
			if (point.col <= 0)//증감연산자가 안전함을 만든다!
			{
				break;
			}
			Swap(board[point.row][point.col], board[point.row][point.col - 1]);
			point.col--;
			break;
		case RIGHT:
			if (point.col >= SIZE-1)//증감연산자가 안전함을 만든다!
			{
				break;
			}
			Swap(board[point.row][point.col], board[point.row][point.col + 1]);
			point.col++;
			break;
		case UP:
			if (point.row <= 0)//증감연산자가 안전함을 만든다!
			{
				break;
			}
			Swap(board[point.row][point.col], board[point.row - 1][point.col]);

			point.row--;
			break;
		case DOWN:
			if (point.row >= SIZE - 1)//증감연산자가 안전함을 만든다!
			{
				break;
			}
			Swap(board[point.row][point.col], board[point.row + 1][point.col]);
			point.row++;
			break;
		default:
			break;
	}
}

void Shuffle(int count)
{
	for (int i = 0; i < count; i++)
	{
		Direction dir = (Direction)(rand() % 4);//형변환!

		Move(dir);
	}
}

void InputDirection()
{
	char dir = 0;

	Direction direction;

	//scanf_s(" %c", &dir, 1);

	while (true)
	{
		if (_kbhit())
		{
			dir = _getch();

			if (dir == 'A' || 
				dir == 'a' || 
				dir == 'S' || 
				dir == 's' || 
				dir == 'W' || 
				dir == 'w' || 
				dir == 'D' || 
				dir == 'd')
				break;
		
		}
	}

	switch (dir)
	{
		case 'A':
		case 'a':
			direction = LEFT;
			break;
		case 'S':
		case 's':

			direction = DOWN;
			break;

		case 'D':
		case 'd':
			direction = RIGHT;
			break;

		case 'W':
		case 'w':
			direction = UP;
			break;

		default:

			break;
	}

	Move(direction);
}

bool CheckWin()
{
	int count = 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j] != count++)
				return false;

			//count++

			if (count == SIZE * SIZE)
			{
				printf("정답입니다!\n");
				return true;
			}
			
		}
	}
}

int main()
{

	srand(time(NULL));

	Initialize();
	
	//Shuffle(5);

	while (true)
	{
		Shuffle(10);

		if (CheckWin() == false)
		{
			break;
		}

	}

	PrintBoard();

	while (true)
	{
		InputDirection();

		PrintBoard();

		if (CheckWin()==true)
		{
			break;
		}
	}



	return 0;

}