#include<stdio.h>

int main()
{
	int A, B;
	char p;
	printf("������ �Է��ϼ���\n");
	scanf_s(" %d", &A);
	scanf_s(" %c", &p, 1);
	scanf_s(" %d", &B);
	switch (p)
	{
	case '+':
		printf("%d + %d = %d", A, B, A + B);
		break;
	case '-':
		printf("%d - %d = %d", A, B, A - B);
		break;
	case '*':
		printf("%d * %d = %d", A, B, A * B);
		break;
	case '/':
		if (B == 0)
		{
			printf("0���� ���� �� �����ϴ�.");
		}
		else
		{
			printf("%d / %d = %d", A, B, A / B);
		}
		break;
	case '%':
		if (B == 0)
		{
			printf("0���� ���� �� �����ϴ�.");
		}
		else
		{
			printf("%d %% %d = %d", A, B, A % B);
		}
		break;
	default:
		printf("�߸��� �����Դϴ�.");
		break;
	}
	return 0;

}