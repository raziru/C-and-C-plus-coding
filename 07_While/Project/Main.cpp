#include<stdio.h>

/*
�ݺ��� : while, do ~ while, for

while : ���ǽ��� true�� ���ȿ� ��� �ݺ��Ѵ�.

while ���� ����

while (���ǽ�)
{
	��ɾ�;
}

*/
// ���α׷��� ó�������ϴ� ����
// main�� '������'(Entry Point)�̴�.

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