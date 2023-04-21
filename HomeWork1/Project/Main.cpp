#include<stdio.h>

int main()
{
	int A, B;
	char p;
	printf("수식을 입력하세요\n");
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
			printf("0으로 나눌 수 없습니다.");
		}
		else
		{
			printf("%d / %d = %d", A, B, A / B);
		}
		break;
	case '%':
		if (B == 0)
		{
			printf("0으로 나눌 수 없습니다.");
		}
		else
		{
			printf("%d %% %d = %d", A, B, A % B);
		}
		break;
	default:
		printf("잘못된 수식입니다.");
		break;
	}
	return 0;

}