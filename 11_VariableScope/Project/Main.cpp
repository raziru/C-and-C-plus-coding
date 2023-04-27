#include<stdio.h>

/*
변수의 유효 범위(Variable Scope)

기본적으로 변수는 지역(중괄호) 내부에서 작동한다.

Local(지역 변수), Global(전역 변수), Static(정적 변수)

지역 변수: 지역 내부에서 생성되고, 지역을 나가면 소멸하는 변수

전역 변수: 지역 외부에서 생성되고, 프로그램이 종료될 때 소멸하는 변수

정적 변수: 지역 내부에서 생성되고, 프로그램이 종료될 때 소멸하는 변수

형식은 지역변수, 성질은 전역변수


유의사항: 

1. 기본적으로 전역 변수와 지역변수의 이름을 같게 설정할 수 있다.

그러나 절대적으로 피해야하는 방식이다. 지역변수가 전역변수를 재치고 호출되어버린다.

2. 만약에 지역변수와 전역변수가 충돌하면, 지역변수를 우선으로 사용한다.

3. 서로 다른 지역의 지역변수끼리는 이름이 같아도 상관없다.

4. 
*/

int global = 0;

void PrintLocal()
{
	int local = 0;

	printf("Local  = %d\n", local++);
}

void PrintGlobal()
{
	//int global = 10;
	printf("Global = %d\n", global++);
}

void PrintStatic()
{
	static int s = 0;//메모리에 상주!

	printf("Static = %d\n", s++);
}

int main()
{
	/*{
		 int a = 10;
		printf("a = %d\n", a);
	}*/

	for (int i = 0; i < 10; i++)
	{
		PrintLocal();
		PrintGlobal();
		PrintStatic();
		printf("\n");
	}

	return 0;
}