#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
�Լ�(Function):

Ư�� �Է��� �޾Ƽ� ���α׷��Ӱ� ���ϴ� ������ �����ϰų�, ��� ���� ��ȯ�ϴ� ���

�Լ��� ���� ���: 

��ȯ�� �Լ��̸�(�Ű�����)
{
	��ɹ�;
}

��ȯ�� = �Լ��� ������� ����, ������

��ȯ���� ���� �Լ��� ��ɹ��� �������ִ� �Լ���.

��ȯ���� ���� ��� void�� �ۼ�

�Լ� �����ε�(Function Overloading) : C++���

'���� �̸�'�� �Լ��� '�Ű������� �ٸ���' �����ϴ� C++�� ���



*/

void Attack()
{
	printf("Attack!\n");
}

void Print(const char* string)
{
	printf(string);
	printf("\n");
}

void Print(int i)
{
	printf("PrintInt : %d\n", i);
}

void Print(float f)
{
	printf("PrintFloat : %f\n", f);
}

int Add(int a, int b)
{
	int result = a + b;

	return result;
}

int Random(int start, int end)
{

	int random = rand() % (end - start + 1) + start;

	return random;
}

int main()
{
	
	Attack();


	Print("HelloWorld!");//�Լ� ȣ��, call

	Print(100);

	Print(1.5f);//float���� �޴� �Ÿ� float�� �������ִ°� �����ϴ�.

	
	int random = Add(10, 20);
	
	printf("Result = %d\n", random);
		 
	Random(50, 100);
	for (int i = 0; i < 10; i++)
	{
		printf("Random = %d\n", Random(50, 100));
	}

	for (int i = 0; i < 12; i++)
	{
		printf("Random = %d\n", Random(50, 100));

	}


	return 0;
}