#include<stdio.h>
/*
���ǹ� (Conditional Statment):

switch

���Ǻ����� Ư�� ���� ������, �� ���� �ش�Ǵ� ������ �����Ѵ�.

���� ���:

switch (���Ǻ����̸�)
{
	case ���ǰ�1:
		��ɹ�;
		break;

	case ���ǰ�2:
		��ɹ�;
		break;

	case ���ǰ�3:
		��ɹ�;
		break;

	default:
		��ɹ�;
		break;		
}


*/


int main() 
{
	int n;

	printf("n�� ���� �Է��ϼ���!\n");
	scanf_s(" %d", &n);

	/*switch (n)
	{
	case 1:
		printf("1�� ��ɹ� ����");
		break;

	case 2:
		printf("2�� ��ɹ� ����");
		break;

	case 3:
		printf("3�� ��ɹ� ����");
		break;

	default:
		printf("�ش��Է°��� �����ϴ�.");
		break;
	}*/

	if (n == 1)
	{
		printf("1�� ��ɹ� ����");
	}
	else if (n == 2)
	{
		printf("2�� ��ɹ� ����");
	}
	else if (n == 3)
	{
		printf("3�� ��ɹ� ����");
	}
	else
	{
		printf("�ش��Է°��� �����ϴ�.");
	}

	return 0;
}

//���� ����� ���װ��� ����� A+B=�� �����ϴ� �Ÿ� �ȴ�.