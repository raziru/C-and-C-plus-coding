#include<stdio.h>
#include<stdlib.h> //library
#include<time.h>

int main()
{
	srand(time(NULL));

	//1. True or False (50% 확률)

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 2;

		if (random)
			printf("성공! %d\n", random);
		else
			printf("실패! %d\n", random);
		
	}

	//2. 특정 확률 n%

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100; // 0~99 100가지 경우의 수
		int percent = 10;
		if (random < percent)
		{
			printf("%d%%의 확률로 성공!\n", percent);
		}
		else
		{
			printf("%d%%의 확률로 실패!\n", 100 - percent);
		}

	}

	//3. 특정 선택지 중 랜덤, n가지 중 선택

	int n = 3;
	for (int i = 0; i < 10; i++)
	{
		int random = rand() % n;
		switch (random)
		{
		case 0:
			printf("0번 캐릭터 선택!\n");
			break;
		case 1:
			printf("1번 캐릭터 선택!\n");
			break;
		case 2:
			printf("2번 캐릭터 선택!\n");
			break;
		default:
			break;
		}
	}



	return 0;
}

int main1()
{
	srand(time(NULL));

	/*int n = rand() % 51 + 50;
	printf("n = %d", n);*/

	int start, end;

	printf("Start부터 End까지의 랜덤 출력!\n");

	scanf_s("%d %d", &start, &end);

	int random = rand() % (end - start + 1) + start; // 50 ~ 100

	printf("%d\n", random);

	return 0;
}