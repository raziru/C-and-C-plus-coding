#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
함수(Function):

특정 입력을 받아서 프로그래머가 원하는 동작을 실행하거나, 결과 값을 반환하는 기능

함수의 선언 방법: 

반환형 함수이름(매개변수)
{
	명령문;
}

반환형 = 함수의 결과값의 형식, 변수형

반환형이 없는 함수는 명령문만 실행해주는 함수다.

반환형이 없는 경우 void로 작성

함수 오버로딩(Function Overloading) : C++기능

'같은 이름'의 함수를 '매개변수만 다르게' 정의하는 C++의 기능



*/

void Print()
{
	printf("Attack!\n");
}

void Print(const char* string)
{
	printf(string);
	printf("\n");
}

void Print(int i)
{
	printf("PrintInt : %d\n", i);
}

void Print(float f)
{
	printf("PrintFloat : %f\n", f);
}

int Add(int a, int b)
{
	return a + b;
}

int Random(int start, int end)
{
	//start ~ end 사이의 랜덤 값이 나오는 함수 만들기
	srand(time(NULL));
	return	rand() % (end - start + 1) + start;
}

int main()
{
	Print();

	Print("HelloWorld!");//함수 호출, call

	Print(100);

	Print(1.5f);//float형을 받는 거면 float라 지정해주는게 안전하다.

	int sum = Add(10,20);

	Print(sum);

	int result = Random(10, 20);

	Print(result);

	Print(Random(1002, 1500));
	

	return 0;
}