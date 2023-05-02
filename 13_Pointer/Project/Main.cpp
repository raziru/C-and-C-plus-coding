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

2. 포인터 변수 이름 앞에 붙은 * : '포인터 변수'가 '가리키는 변수'의 '값'을 반환 -- 참조 연산자 역할

*역참조(Deference) 연산자*, 간접참조 연산자->포인터에서 역으로 변수를 찾고 값을 출력한다.


& : 주소 연산자

1.    변수형 뒤에 붙은 & : 변수의 원본을 사용하게 해주는 연산자

2. 변수 이름 앞에 붙은 & : 변수의 주소값을 반환하는 연산자 -- 주소 연산자 역할


*/

//함수 호출 방식 (Call-By-Value, Call-By-Address)

//Call-By-Value (값에 의한 호출) : 받은 매개변수의 값만 참조
//void Swap(int a, int b)//매개변수(parameter)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//}


//Call-By-Address (주소에 의한 호출) : 포인터 변수로 참조
void Swap(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

//Call-By-Reference(참조에 의한 호출) : 매개변수의 원본을 참조
void Swap(int& a, int& b)//매개변수(parameter)
{
	int temp = a;
	a = b;
	b = temp;

}

void SetValue(float& variable, float value)
{
	variable = value;

	value = 0.5f;
}

int main() 
{
	int a = 10;
	int b = 20;

	int* pA = &a; //Pointer 선언, a의 주소 대입
	int* pB = &b;

	int arr[4]; //모든 포인터의 sizeof는 같다.



	printf("    Value of a  = %d\n", a);
	printf("     Size of a  = %lld\n", sizeof(a));
	printf("  Address of a  = %p\n", &a);
	printf("    Value of pA = %p\n", pA);
	printf("     Size of pA = %lld\n", sizeof(pA));
	printf("  Address of pA = %p\n", &pA);
	printf("Deference of pA = %d\n", *pA);


	float p = 1.5f;
	float* q = &p;
	//printf("%d\n", sizeof(q));

	//Swap(pA, pB);

	Swap(a, b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	float f = 0.0f;

	printf("f = %f\n", f);

	float value = 12.5f;

	SetValue(f, value);

	
	printf("f = %f\n", f);
	printf("value = %f\n", value);

	char c = 'A';

	char* pC = &c;


	printf("    Value of c  = %d\n", c);			//65
	printf("     Size of c  = %lld\n", sizeof(c));  //1
	printf("  Address of c  = %p\n", &c);			//&c
	printf("    Value of pC = %p\n", pC);			//pC
	printf("     Size of pC = %lld\n", sizeof(pC)); //8
	printf("  Address of pC = %p\n", &pC);			//처음보는 값
	printf("Deference of pC = %d\n", *pC);			//65

	// c == *pC, address of c == value of pC, size of pC != size of c. Address of pC != Address of c
	return 0;
}

