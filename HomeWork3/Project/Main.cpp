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
		printf("������?\n");
		scanf_s("%d",&answer);
		arr[i] = answer;
		len = i;
		if (random==answer)
		{
			printf("�����Դϴ�! ������ %d\n\n",answer);
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
		printf("%d�� �Է��߽��ϴ�. �ٽ� �غ�����\n",len);
	}

	printf("�Էµ� ���� %d��\n",len);
	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr[j]);
	}

	printf("\n");

	return 0;
}
