#include<stdio.h>
/*
연산자(Operator): 연산 순서상관없이 괄호를 치는 습관이 좋다.

증감 연산자: n++, n--, ++n, --n

n++

n= n_1;

n--

n=n-1

++n과 n++의 차이점은

n이라는 변수를 사용하기전에 더하느냐, 사용한 수에 더하느냐의 차이다.

산술 연산자:	*, /, %(modulus, mod, 나머지 연산자), +, -, <<, >>

비교 연산자: >, <, <=, >=, ==, != 0,1 return

비트 연산자: ~ > & > ^ > |

논리 연산자: &&(and) > ||(or), !(not, 증감연산자와 우선순위가 같음)

삼항 연산자: 조건식 ? true일 때 결과값 : false일 때 결과값;

대입 연산자: =, +=, -=, *=, /=, %=
*/


int main()
{
	printf("7 %% 3 = %d\n", 7 % 3);

	int a = 0;
	printf("a = %d\n", a);

	//a = a + 10;
	a += 10;

	printf("a = %d\n", a);

	a += 10;

	printf("a = %d\n", a);

	a /= 3;

	printf("a = %d\n", a);

	a %= 5;

	printf("a = %d\n", a); // a == 1

	//++a;
	

	printf("a = %d\n", ++a);

	printf("a = %d\n", a); //2

	int b = 20;

	printf("a > b = %d\n", a > b); //0
	printf("a < b = %d\n", a < b); //1
	
	printf("a == b = %d\n", a == b); //0
	printf("a != b = %d\n", a != b); //1
	
	
	printf("!(a > b) = %d\n", !(a > b)); //1
	printf("!(a < b) = %d\n", !(a < b)); //0

	bool i = true;
	bool j = true;
	bool k = false;
	bool l = false;

	printf("i && j = %s\n", i && j ? "true" : "false");
	printf("i && k = %s\n", i && k ? "true" : "false");
	printf("k && l = %s\n", k && l ? "true" : "false");
	printf("i || j = %s\n", i || j ? "true" : "false");
	printf("i || k = %s\n", i || k ? "true" : "false");
	printf("k || l = %s\n", k || l ? "true" : "false");

	printf("~a=%d\n", ~a);



	return 0;
}