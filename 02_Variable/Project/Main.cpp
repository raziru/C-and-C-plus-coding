#include<stdio.h>
/*
���� : ���α׷��� �����ϱ� ���� �غ� ����

���� ���� :

1. ��ó���� - �ּ� ����

2. �����Ϸ� - �ڵ� �ؼ� -> �������

3. ����� - ������(binary)�� ����

4. ��Ŀ - ���� ��� ������ ���� 

Variable : ���� - ���� �� �ִ� ��
Constant : ��� - ������ �ʴ� ��

���α׷��ֿ����� ���� - ��Ƽ� ��� ����

������ ����(������, �ڷ���): � ������ ������ �˷��ִ� ��

������ - short(2byte), int(integer, 4byte), long(4byte), long long(8byte)

�Ǽ��� - float(4byte), double(8byte), long double(8byte �̻�)

���� - bool(boolean, 1byte)

������ - char(character, 1byte) : ���� 1���� ��´�.





�޸��� �ּҴ��� : bit(0 or 1) byte
�޸��� �⺻���� : byte(8bit, 256����)

���� ���� �� ���ǻ���:

1. ���� �̸��� ������ �ߺ��ؼ� ������ �� ����.(��ҹ���)

2. �⺻���� ���� ���� ��� : ������ �����̸�; ������ �����̸� = �ʱⰪ;

3. ���� �̸� ���� �տ��� ���ڰ� �� �� ����.

4. Ư�����ڴ� ����� �Ұ��� (��, _�� ��밡��)


���� ���̹� ��Ģ: 

1. Camel(ī��) ǥ��� : �ҹ��ڷ� �����ؼ�, ���⸦ �빮�ڷ� ǥ��(bloodType)

- ������ �ַ� ���

2. Pascal(�Ľ�Į) ǥ��� : �빮�ڷ� �����ؼ�, ���⸦ �빮�ڷ� ǥ��(BloodType)

- �Լ��� �ַ� ���

3. Hungarian(�밡����) ǥ��� : �ҹ��ڷ� �����ؼ�, ���⸦ �����(_)�� ǥ�� (blood_type)

- ����� �ַ� ��� (BLOOD_TYPE)


���� ������(format specifier)( %d, %f, %c ...)

Escape Sequence(\n, \t, \\, \" ...)

*/

int main() 
{
	int a = 10;//assign
	int A_ = 30;
	printf("a = %d \" \\ \" \n", a);

	a = 20;

	printf("A = %d\n", A_);

	int b = 20;

	printf("a + b = %d\n", a + b);

	float f = 20.0;

	printf("f = %0.1f\n", f);

	bool isFalling = true;

	bool bErase = false;

	bool canFly = 3;//0�� �ƴϸ� true

	char c = '[';


	signed int p = 0b11111111;


	printf("c = %c\n", c);

	printf("Hello World!\n");

	printf("%d", p);

	return 0;
}