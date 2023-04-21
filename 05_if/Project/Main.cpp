#include<stdio.h>

/*
Condition = 조건

조건문 (Conditional Statement):

조건식이 true일 때 명령문을 실행하게 해주는 문구

if (조건식)
{
	명령문;
}
else if (조건식)
{
	명령문;
}
else
{
	명령문;
}



*/
int main()
{
	int n;
	
	printf("n의 값을 입력하세요\n");
	
	scanf_s(" %d", &n);
	
	if (n > 5) 
	{
		printf("n은 5보다 크다!\n");
	}
	else if (n == 10)
	{
		printf("n은 10과 같다!\n");
	}
	else
	{
		printf("n은 10보다 작다!\n");
	}



	return 0;
}