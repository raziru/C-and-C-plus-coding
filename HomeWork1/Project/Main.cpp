#include<stdio.h>

int main() 
{
	int A, B;
	char p;
	printf("수식을 입력하세요\n");
	//scanf_s(" %d %c %d", &A, &p, &B);
	scanf_s(" %d", &A);
	scanf_s(" %c", &p);
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
		printf("%d / %d = %d", A, B, A / B);
		break;
	case '%':
		printf("%d %% %d = %d", A, B, A % B);
		break;
	default:
		printf("잘못된 수식입니다.");
		break;
	}
	return 0;

}