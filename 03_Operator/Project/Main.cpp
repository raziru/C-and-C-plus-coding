#include<stdio.h>
/*
������(Operator): ���� ����������� ��ȣ�� ġ�� ������ ����.

���� ������: n++, n--, ++n, --n

n++

n= n_1;

n--

n=n-1

++n�� n++�� ��������

n�̶�� ������ ����ϱ����� ���ϴ���, ����� ���� ���ϴ����� ���̴�.

��� ������:	*, /, %(modulus, mod, ������ ������), +, -, <<, >>

�� ������: >, <, <=, >=, ==, != 0,1 return

��Ʈ ������: ~ > & > ^ > |

�� ������: &&(and) > ||(or), !(not, ���������ڿ� �켱������ ����)

���� ������: ���ǽ� ? true�� �� ����� : false�� �� �����;

���� ������: =, +=, -=, *=, /=, %=
*/


int main()
{
	printf("7 %% 3 = %d\n", 7 % 3);

	int a = 0;
	printf("a = %d\n", a);

	//a = a + 10;
	a += 10;

	printf("a = %d\n", a);

	a += 10;

	printf("a = %d\n", a);

	a /= 3;

	printf("a = %d\n", a);

	a %= 5;

	printf("a = %d\n", a); // a == 1

	//++a;
	

	printf("a = %d\n", ++a);

	printf("a = %d\n", a); //2

	int b = 20;

	printf("a > b = %d\n", a > b); //0
	printf("a < b = %d\n", a < b); //1
	
	printf("a == b = %d\n", a == b); //0
	printf("a != b = %d\n", a != b); //1
	
	
	printf("!(a > b) = %d\n", !(a > b)); //1
	printf("!(a < b) = %d\n", !(a < b)); //0

	bool i = true;
	bool j = true;
	bool k = false;
	bool l = false;

	printf("i && j = %s\n", i && j ? "true" : "false");
	printf("i && k = %s\n", i && k ? "true" : "false");
	printf("k && l = %s\n", k && l ? "true" : "false");
	printf("i || j = %s\n", i || j ? "true" : "false");
	printf("i || k = %s\n", i || k ? "true" : "false");
	printf("k || l = %s\n", k || l ? "true" : "false");

	printf("~a=%d\n", ~a);



	return 0;
}