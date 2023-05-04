#include<stdio.h>


enum Shape
{
	TRIANGLE = 1,
	RECTANGLE, 
	DIAMOND
};

int main()
{
	int n;
	printf("도형의 크기를 정해주세요: ");
	scanf_s("%d", &n);

	printf("\n\n");

	Shape shape;

	printf("삼각형:1, 사각형:2, 다이아몬드:3\n");

	scanf_s(" %d", &shape);
	printf("\n\n");


	switch (shape)
	{
	case TRIANGLE:
		//삼각형
		printf("삼각형\n\n");

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n - i - 1; j++)
				printf(" ");

			for (int k = 0; k < 2 * i + 1; k++)
				printf("*");

			printf("\n");
		}

		break;
	case RECTANGLE:
		//사각형
		printf("사각형\n\n");

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
				printf("*");
			printf("\n");
		}
		break;
	case DIAMOND:
		//다이아몬드
		printf("다이아몬드\n\n");

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n - i - 1; j++)
				printf(" ");

			for (int k = 0; k < 2 * i + 1; k++)
				printf("*");

			printf("\n");
		}

		for (int i = n - 1; i > 0; i--)
		{

			for (int j = n - i; j > 0; j--)
				printf(" ");

			for (int k = 2 * i - 1; k > 0; k--)
				printf("*");

			printf("\n");
		}
		break;
	default:
		break;
	}
	

	return 0;
}
