#include<stdio.h>

/*
   Mouse Pointer: ���콺�� ��ġ�� ����Ű�� ��

C++������ Pointer: ������ ��ġ�� ����Ű�� ��

Pointer ����: '������ ��ġ'�� ����� ����

�ּҰ� : 16���� ������(ex. 0xFFFF)

Pointer ������ ���� ���:

(����Ű���� �ϴ� ������ ����)* (������ �����̸�) = &(����Ű���� �ϴ� ���� �̸�);



* : ���� ������

1.    ������ �ڿ� ���� * : '���� ����' �� �� '������ ����'��� ���� �˷��ִ� ����

2. ������ ���� �̸� �տ� ���� * : '������ ����'�� ����Ű�� ������ ���� ��ȯ

������(Deference) ������, �������� ������->�����Ϳ��� ������ ������ ã�� ���� ã�Ƴ���.


& : �ּ� ������

1.    ������ �ڿ� ���� & :

2. ���� �̸� �տ� ���� & : ������ �ּҰ��� ��ȯ�ϴ� ������


*/

//�Լ� ȣ�� ��� (Call-By-Value, Call-By-Address)

//Call-By-Value (���� ���� ȣ��)
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

}
//Call-By-Address (�ּҿ� ���� ȣ��)
void Swap(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

int main() 
{
	int a = 10;
	int b = 20;

	int* pA = &a; //Pointer ����, a�� �ּ� ����
	int* pB = &b;



	printf("    Value of a  = %d\n", a);
	printf("    Value of pA = %p\n", pA);
	printf("  Address of a  = %p\n", &a);
	printf("Deference of pA = %d\n", *pA);

	Swap(&a, &b);


	printf("a = %d\n", a);
	printf("b = %d\n", b);





	return 0;
}

