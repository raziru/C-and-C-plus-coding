#include<stdio.h>
#include<stdlib.h> //library
#include<time.h>

int main()
{
	srand(time(NULL));

	//1. True or False (50% Ȯ��)

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 2;

		if (random)
			printf("����! %d\n", random);
		else
			printf("����! %d\n", random);
		
	}

	//2. Ư�� Ȯ�� n%

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100; // 0~99 100���� ����� ��
		int percent = 10;
		if (random < percent)
		{
			printf("%d%%�� Ȯ���� ����!\n", percent);
		}
		else
		{
			printf("%d%%�� Ȯ���� ����!\n", 100 - percent);
		}

	}

	//3. Ư�� ������ �� ����, n���� �� ����

	int n = 3;
	for (int i = 0; i < 10; i++)
	{
		int random = rand() % n;
		switch (random)
		{
		case 0:
			printf("0�� ĳ���� ����!\n");
			break;
		case 1:
			printf("1�� ĳ���� ����!\n");
			break;
		case 2:
			printf("2�� ĳ���� ����!\n");
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

	printf("Start���� End������ ���� ���!\n");

	scanf_s("%d %d", &start, &end);

	int random = rand() % (end - start + 1) + start; // 50 ~ 100

	printf("%d\n", random);

	return 0;
}