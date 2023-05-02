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

2. ������ ���� �̸� �տ� ���� * : '������ ����'�� '����Ű�� ����'�� '��'�� ��ȯ -- ���� ������ ����

*������(Deference) ������*, �������� ������->�����Ϳ��� ������ ������ ã�� ���� ����Ѵ�.


& : �ּ� ������

1.    ������ �ڿ� ���� & : ������ ������ ����ϰ� ���ִ� ������

2. ���� �̸� �տ� ���� & : ������ �ּҰ��� ��ȯ�ϴ� ������ -- �ּ� ������ ����


*/

//�Լ� ȣ�� ��� (Call-By-Value, Call-By-Address)

//Call-By-Value (���� ���� ȣ��) : ���� �Ű������� ���� ����
//void Swap(int a, int b)//�Ű�����(parameter)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//}


//Call-By-Address (�ּҿ� ���� ȣ��) : ������ ������ ����
void Swap(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

//Call-By-Reference(������ ���� ȣ��) : �Ű������� ������ ����
void Swap(int& a, int& b)//�Ű�����(parameter)
{
	int temp = a;
	a = b;
	b = temp;

}

void SetValue(float& variable, float value)
{
	variable = value;

	value = 0.5f;
}

int main() 
{
	int a = 10;
	int b = 20;

	int* pA = &a; //Pointer ����, a�� �ּ� ����
	int* pB = &b;

	int arr[4]; //��� �������� sizeof�� ����.



	printf("    Value of a  = %d\n", a);
	printf("     Size of a  = %lld\n", sizeof(a));
	printf("  Address of a  = %p\n", &a);
	printf("    Value of pA = %p\n", pA);
	printf("     Size of pA = %lld\n", sizeof(pA));
	printf("  Address of pA = %p\n", &pA);
	printf("Deference of pA = %d\n", *pA);


	float p = 1.5f;
	float* q = &p;
	//printf("%d\n", sizeof(q));

	//Swap(pA, pB);

	Swap(a, b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	float f = 0.0f;

	printf("f = %f\n", f);

	float value = 12.5f;

	SetValue(f, value);

	
	printf("f = %f\n", f);
	printf("value = %f\n", value);

	char c = 'A';

	char* pC = &c;


	printf("    Value of c  = %d\n", c);			//65
	printf("     Size of c  = %lld\n", sizeof(c));  //1
	printf("  Address of c  = %p\n", &c);			//&c
	printf("    Value of pC = %p\n", pC);			//pC
	printf("     Size of pC = %lld\n", sizeof(pC)); //8
	printf("  Address of pC = %p\n", &pC);			//ó������ ��
	printf("Deference of pC = %d\n", *pC);			//65

	// c == *pC, address of c == value of pC, size of pC != size of c. Address of pC != Address of c
	return 0;
}

