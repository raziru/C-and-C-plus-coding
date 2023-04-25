#include<stdio.h>
#include<stdlib.h> //library
#include<time.h>

int main()
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