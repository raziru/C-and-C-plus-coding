#include<stdio.h>

int main() 
{
	int A, B;
	char p;
	printf("������ �Է��ϼ���\n");
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
		printf("�߸��� �����Դϴ�.");
		break;
	}
	return 0;

}