#include<stdio.h>

/*
   Mouse Pointer: 마우스의 위치를 가리키는 것

C++에서의 Pointer: 변수의 위치를 가리키는 것

Pointer 변수: '변수의 위치'를 기록한 변수

주소값 : 16진수 정수형(ex. 0xFFFF)

Pointer 변수의 선언 방법:

(가리키고자 하는 변수의 형식)* (포인터 변수이름) = &(가리키고자 하는 변수 이름);



* : 참조 연산자

1.    변수형 뒤에 붙은 * : '변수 선언' 할 때 '포인터 변수'라는 것을 알려주는 역할

2. 포인터 변수 이름 앞에 붙은 * : '포인터 변수'가 가리키는 변수의 값을 반환

역참조(Deference) 연산자, 간접참조 연산자->포인터에서 역으로 변수를 찾고 값을 찾아낸다.


& : 주소 연산자

1.    변수형 뒤에 붙은 & :

2. 변수 이름 앞에 붙은 & : 변수의 주소값을 반환하는 연산자


*/

//함수 호출 방식 (Call-By-Value, Call-By-Address)

//Call-By-Value (값에 의한 호출)
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

}
//Call-By-Address (주소에 의한 호출)
void Swap(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

int main() 
{
	int a = 10;
	int b = 20;

	int* pA = &a; //Pointer 선언, a의 주소 대입
	int* pB = &b;



	printf("    Value of a  = %d\n", a);
	printf("    Value of pA = %p\n", pA);
	printf("  Address of a  = %p\n", &a);
	printf("Deference of pA = %d\n", *pA);

	Swap(&a, &b);


	printf("a = %d\n", a);
	printf("b = %d\n", b);





	return 0;
}

