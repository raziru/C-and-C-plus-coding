#include<stdio.h>
/*
�ݺ��� : for

for (�ʱ��; ���ǽ�; ������)
{
	��ɹ�;
}

�ʱ�� -> ���ǽ� -> ��ɹ� (-> ���ǽ� -> ������ -> ��ɹ�) (-> ���ǽ� -> ������ -> ��ɹ�) (-> ���ǽ� -> ������ -> ��ɹ�)
*/
int main()
{
	//index 
	/*for (int i = 1; i < 10; i++)
	{
		printf("3 * %d = %d\n", i, 3 * i);
		
	}*/

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++) 
		{

			printf("%d * %d = %3d\n", i, j, i * j);

		}
		printf("\n");
	}
	return 0;
}