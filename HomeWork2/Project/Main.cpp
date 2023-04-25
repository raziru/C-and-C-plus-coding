#include<stdio.h>

int main()
{
	int n;
	printf("도형의 크기를 정해주세요: ");
	scanf_s("%d", &n);

	printf("\n\n");

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

	printf("\n\n");

	//사각형
	printf("사각형\n\n");

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}

	printf("\n\n");

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

	return 0;
}
