#include<stdio.h>
#include<stdlib.h>

/*
다차원 배열(2차원 배열)

배열의 요소로 배열을 가지는 변수형



*/

int main()
{
	int arr1[2] = { 1, 2 };

	int arr2[2][3] = 
	{ 
		1, 2, 3,
		4, 5, 6 
	};

	int arr3[3][2] = 
	{ 
		1, 2,
		3, 4,
		5, 6
	};

	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("arr[%d][%d] = %d\n", i, j, arr3[i][j]);
		}
	}*/


	/*
	1. (2중 for문을 사용해서)
	
	3행 2열 크기의 2차원 배열을 선언하고, 앞에서 부터 1로 시작해서 1씩 증가하는 수를 채워보세요

	{
		1, 2,
		3, 4,
		5, 6
	}

	2. 4행 4열 크기의 2차원 배열을 선언하고, 다음과 같이 채워지는 배열을 완성하시오

	{
		0, 1, 2, 3
		10, 11, 12, 13 
		20, 21, 22, 23
		30,31 32,33
	}
	
	3. 3행 2열 크기의 2차원배열을 선언하고, 다음과 같이 채워지는 배열을 완성하시오

	{
		A, B
		C, D
		E, F
	}

	*/

	int arr4[3][2] = {};
	int count = 0;
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			//arr_1[i][j] = (2*i+1)+j;
			arr4[i][j] = ++count;
			printf("arr4[%d][%d] = %d\t", i, j, arr4[i][j]);

		}
		printf("\n");

	}
	printf("\n\n");



	int arr5[4][4] = {};
	int answer2;
	for (int i = 0; i < 4; i++)
	{
		//answer2 = i*10;
		for (int j = 0; j < 4; j++)
		{
			arr5[i][j] = i * 10 + j;
			//arr5[i][j] = answer2++;
			printf("arr5[%d][%d] = %02d\t", i, j, arr5[i][j]);

		}
		printf("\n");

	}
	printf("\n\n");

	printf("%.2f\n", 1.5f);



	char arr6[3][2] = {};
	char A = 65;
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			arr6[i][j] = A++;
			printf("arr6[%d][%d] = %c\t", i, j, arr6[i][j]);

		}
		printf("\n");

	}








	/*int** p;
	int height;
	int width;

	scanf_s(" %d", &height);
	scanf_s(" %d", &width);


	p = (int**)malloc(sizeof(int*) * height);

	for (int i = 0; i < width; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * width);
	
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			p[i][j] = height * i + j;
			printf("p[%d][%d] = %d\t", i, j, p[i][j]);

		}
		printf("\n");
	}*/




	return 0;
}