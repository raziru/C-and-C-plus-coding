#include<stdio.h>
//#include<stdlib.h>

/*
�迭(Array):

'���� ������'�� ������ ���ÿ� '������' �����ϴ� ���

�迭�� ���� ���:

������ �迭���̸�[�迭�Ǳ���];

�迭�� ���� = ������ ����

�迭�� ���̿��� ������ �� �� ����.

���(constant, const): ������ �ʴ� ��

*/


int main()
{
	

	const int size = 5;//����� ������ �����ϸ� �����Ҷ� �����ϰ� ���������.

	//size = 9;

	int arr[size] = {  };


	//arr = (int*)malloc(sizeof(int) * size);

	/*printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2])*/;
	for (int i = 0; i < size; i++)
	{
		arr[i] = 5 * i;

		printf("           arr[%d] = %d\n", i, arr[i]);

		printf("Address of arr[%d] = %p\n", i, &arr[i]);
	}

	printf("Size of arr = %lld\n", (sizeof(arr)));
	//free(arr);

	return 0;
}