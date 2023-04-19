#include<stdio.h>
/*
빌드 : 프로그램을 실행하기 위한 준비 과정

빌드 과정 :

1. 전처리기 - 주석 제거

2. 컴파일러 - 코드 해석 -> 어셈블리어

3. 어셈블러 - 이진수(binary)로 번역

4. 링커 - 앞의 모든 내용을 결함 

Variable : 변수 - 변할 수 있는 수
Constant : 상수 - 변하지 않는 수

프로그래밍에서의 변수 - 데티어를 담는 공간

변수의 유형(변수형, 자료형): 어떤 변수를 담을지 알려주는 것

정수형 - short(2byte), int(integer, 4byte), long(4byte), long long(8byte)

실수형 - float(4byte), double(8byte), long double(8byte 이상)

논리형 - bool(boolean, 1byte)

문자형 - char(character, 1byte) : 글자 1개를 담는다.





메모리의 최소단위 : bit(0 or 1) byte
메모리의 기본단위 : byte(8bit, 256가지)

변수 선언 시 유의사항:

1. 같은 이름의 변수를 중복해서 선언할 수 없다.(대소문자)

2. 기본적인 변수 선언 방식 : 변수형 변수이름; 변수형 변수이름 = 초기값;

3. 변수 이름 제일 앞에는 숫자가 올 수 없다.

4. 특수문자는 사용이 불가능 (단, _는 사용가능)


변수 네이밍 규칙: 

1. Camel(카멜) 표기법 : 소문자로 시작해서, 띄어쓰기를 대문자로 표시(bloodType)

- 변수에 주로 사용

2. Pascal(파스칼) 표기법 : 대문자로 시작해서, 띄어쓰기를 대문자로 표시(BloodType)

- 함수에 주로 사용

3. Hungarian(헝가리안) 표기법 : 소문자로 시작해서, 띄어쓰기를 언더바(_)로 표시 (blood_type)

- 상수에 주로 사용 (BLOOD_TYPE)


서식 지정사(format specifier)( %d, %f, %c ...)

Escape Sequence(\n, \t, \\, \" ...)

*/

int main() 
{
	int a = 10;//assign
	int A_ = 30;
	printf("a = %d \" \\ \" \n", a);

	a = 20;

	printf("A = %d\n", A_);

	int b = 20;

	printf("a + b = %d\n", a + b);

	float f = 20.0;

	printf("f = %0.1f\n", f);

	bool isFalling = true;

	bool bErase = false;

	bool canFly = 3;//0이 아니면 true

	char c = '[';


	signed int p = 0b11111111;


	printf("c = %c\n", c);

	printf("Hello World!\n");

	printf("%d", p);

	return 0;
}