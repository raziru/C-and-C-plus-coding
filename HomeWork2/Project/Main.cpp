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
	printf("������ ũ�⸦ �����ּ���: ");
	scanf_s("%d", &n);

	printf("\n\n");

	Shape shape;

	printf("�ﰢ��:1, �簢��:2, ���̾Ƹ��:3\n");

	scanf_s(" %d", &shape);
	printf("\n\n");


	switch (shape)
	{
	case TRIANGLE:
		//�ﰢ��
		printf("�ﰢ��\n\n");

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
		//�簢��
		printf("�簢��\n\n");

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
				printf("*");
			printf("\n");
		}
		break;
	case DIAMOND:
		//���̾Ƹ��
		printf("���̾Ƹ��\n\n");

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
