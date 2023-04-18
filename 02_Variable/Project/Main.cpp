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


메모리의 최소단위 : bit(0 or 1) byte
메모리의 기본단위 : byte(8bit, 256가지)



*/
int main() 
{
	printf("10 + 20 = %d", 10 + 20);

	return 0;
}