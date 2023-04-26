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

void Print()
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
	return a + b;
}

int Random(int start, int end)
{
	//start ~ end ������ ���� ���� ������ �Լ� �����
	srand(time(NULL));
	return	rand() % (end - start + 1) + start;
}

int main()
{
	Print();

	Print("HelloWorld!");//�Լ� ȣ��, call

	Print(100);

	Print(1.5f);//float���� �޴� �Ÿ� float�� �������ִ°� �����ϴ�.

	int sum = Add(10,20);

	Print(sum);

	int result = Random(10, 20);

	Print(result);

	Print(Random(1002, 1500));
	

	return 0;
}