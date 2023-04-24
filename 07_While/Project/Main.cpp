#include<stdio.h>

/*
반복문 : while, do ~ while, for

while : 조건식이 true인 동안에 계속 반복한다.

while 문의 형식

while (조건식)
{
	명령어;
}

*/
// 프로그램이 처음시작하는 지점
// main은 '진입점'(Entry Point)이다.

int main()
{
	int n = 0;

	while (true)
	{
		n++;
		
		if (n % 2 == 0)
			continue;
		
		printf("n = %d\n", n);
		
		if (n >= 10)
			break;
	}

	return 0;
}