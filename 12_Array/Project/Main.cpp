#include<stdio.h>
//#include<stdlib.h>

/*
배열(Array):

'같은 변수형'의 변수를 동시에 '여러개' 선언하는 방법

배열의 선언 방법:

변수형 배열의이름[배열의길이];

배열의 길이 = 변수의 개수

배열의 길이에는 변수가 들어갈 수 없다.

상수(constant, const): 변하지 않는 수

*/


int main()
{
	

	const int size = 5;//상수인 변수를 생성하면 수정할때 유리하게 만들어진다.

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