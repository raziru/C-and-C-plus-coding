#include<stdio.h>

/*
Condition = ����

���ǹ� (Conditional Statement):

���ǽ��� true�� �� ��ɹ��� �����ϰ� ���ִ� ����

if (���ǽ�)
{
	��ɹ�;
}
else if (���ǽ�)
{
	��ɹ�;
}
else
{
	��ɹ�;
}



*/
int main()
{
	int n;
	
	printf("n�� ���� �Է��ϼ���\n");
	
	scanf_s(" %d", &n);
	
	if (n > 5) 
	{
		printf("n�� 5���� ũ��!\n");
	}
	else if (n == 10)
	{
		printf("n�� 10�� ����!\n");
	}
	else
	{
		printf("n�� 10���� �۴�!\n");
	}



	return 0;
}