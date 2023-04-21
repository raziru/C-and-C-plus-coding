#include<stdio.h>

int main()
{
	/*scanf_s(" %d", &n);

	printf("n = %d", n);
	*/
	int n = 0;

	int m;

	printf("n과 m의 값을 입력하세요!\n");

	scanf_s(" %d %d", &n, &m);

	printf("n = %d, m = %d\n", n, m);

	float f;

	printf("f의 값을 입력하세요!\n");

	scanf_s(" %f", &f);

	printf("f = %f", f);

	return 0;
}