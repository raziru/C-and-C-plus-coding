#include<stdio.h>

int main()
{
	/*scanf_s(" %d", &n);

	printf("n = %d", n);
	*/
	int n = 0;

	int m;

	printf("n�� m�� ���� �Է��ϼ���!\n");

	scanf_s(" %d %d", &n, &m);

	printf("n = %d, m = %d\n", n, m);

	float f;

	printf("f�� ���� �Է��ϼ���!\n");

	scanf_s(" %f", &f);

	printf("f = %f", f);

	return 0;
}