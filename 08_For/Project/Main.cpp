#include<stdio.h>
/*
반복문 : for

for (초기식; 조건식; 증감식)
{
	명령문;
}

초기식 -> 조건식 -> 명령문 (-> 조건식 -> 증감식 -> 명령문) (-> 조건식 -> 증감식 -> 명령문) (-> 조건식 -> 증감식 -> 명령문)
*/
int main()
{
	//index 
	/*for (int i = 1; i < 10; i++)
	{
		printf("3 * %d = %d\n", i, 3 * i);
		
	}*/

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++) 
		{

			printf("%d * %d = %3d\n", i, j, i * j);

		}
		printf("\n");
	}
	return 0;
}