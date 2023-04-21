#include<stdio.h>
/*
조건문 (Conditional Statment):

switch

조건변수에 특정 값이 들어오면, 그 값에 해당되는 동작을 실행한다.

선언 방법:

switch (조건변수이름)
{
	case 조건값1:
		명령문;
		break;

	case 조건값2:
		명령문;
		break;

	case 조건값3:
		명령문;
		break;

	default:
		명령문;
		break;		
}


*/


int main() 
{
	int n;

	printf("n의 값을 입력하세요!\n");
	scanf_s(" %d", &n);

	/*switch (n)
	{
	case 1:
		printf("1번 명령문 실행");
		break;

	case 2:
		printf("2번 명령문 실행");
		break;

	case 3:
		printf("3번 명령문 실행");
		break;

	default:
		printf("해당입력값이 없습니다.");
		break;
	}*/

	if (n == 1)
	{
		printf("1번 명령문 실행");
	}
	else if (n == 2)
	{
		printf("2번 명령문 실행");
	}
	else if (n == 3)
	{
		printf("3번 명령문 실행");
	}
	else
	{
		printf("해당입력값이 없습니다.");
	}

	return 0;
}

//계산기 만들기 이항계산기 만들기 A+B=을 수행하는 거면 된다.