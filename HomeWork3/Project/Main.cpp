#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));

	const int size = 100;

	int arr[size] = {};

	int random = rand() % size + 1;

	int answer;

	int len = 0;

	for (int i = 0; i < size; i++)
	{
		printf("정답은?\n");
		scanf_s("%d",&answer);
		arr[i] = answer;
		len = i;
		if (random==answer)
		{
			printf("정답입니다! 정답은 %d\n\n",answer);
			break;
		}
		else if(random<answer)
		{
			printf("DOWN!\n\n");
		}
		else
		{
			printf("UP!\n\n");
		}
	}

	len++;

	if (len==size)
	{
		printf("%d번 입력했습니다. 다시 해보세요\n",len);
	}

	printf("입력된 숫자 %d개\n",len);
	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr[j]);
	}

	printf("\n");

	return 0;
}
