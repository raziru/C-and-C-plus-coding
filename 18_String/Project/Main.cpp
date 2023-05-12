#include<stdio.h>
#include<string>//string.h는 c에서 쓰는 헤더파일 string이 내용을 다 가지고있다.
#include<ctime>

/*
문자열(string) : 문자의 배열, char의 배열

NULL 문자('\0') : 문자열의 끝을 알리는 문자

문자열의 제일 마지막에는 NULL 문자가 자동으로 생긴다.

배열을 함수의 매개변수로 사용할 때는, Call-By-Value는 사용하지 못한다.

자동으로 Call-By-Address로 받아오게 된다.



*/

void PrintString(char str[])
{
	printf(str);
}

void PrintString(const char* str)
{
	printf(str);
}

int StringLength(char* str, int size)
{
	
	for (int i = 0; i<size; i++)
	{
		if (str[i]=='\0')
		{
			return i;
		}
	}

	return 0;
}

int StringLength(char* str )
{

	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
		{
			return i;
		}
	}

	return 0;
}
int StringCompare(const char* str1, const char* str2)
{
	if (strlen(str1) > strlen(str2))
		return 2;
	else if (strlen(str1) < strlen(str2))
		return 3;
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i]!=str2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	

	

	/*
	str1과 str2의 길이를 비교

	만약에 두 문자열이 일치하면 1을 반환

	다르면,

	str1의 길이가 더 크면 2를 반환,
	str2의 길이가 더 크면 3을 반환,

	두 문자열의 길이만 같고 일치하지 않으면 0을 반환

	*/
	/*int i = 0;
	int j = 0;
	bool same = true;
	while (true)
	{
		if (str1[i] != str2[i])
		{
			same = false;
		}


		if (str1[i] == '\0' && str2[i] == '\0')
		{
			if (same)
			{
				return 1;
			}
			else
				return 0;
		}
		else if (str1[i] == '\0')
		{
			return 3;
		}
		else if (str2[i] == '\0')
		{
			return 2;
		}

		i++;

	}*/


	return 0;
}


int main()
{
	char str1[] = "HelloWorld!";//12개의 객체

	const char* str2 = "ByeBye\n";//12개의 객체

	//PrintString(str);

	printf("%d\n", StringLength(str1));//배열의 크기를 받는다.

	//PrintString(str2);

	printf("strcmp: %d\n",strcmp(str1, str2));
	printf("strcmp: %d\n", strcmp(str2, str1));//알파벳 순서비교
	printf("strcmp: %d\n", strcmp(str1, str1));

	char str3[] = "HelloWorld!";

	//printf(str3);

	printf("%d \n", StringCompare("hello", "hello"));
	printf("%d \n", StringCompare("heklo", "hello"));
	printf("%d \n", StringCompare("hekl", "hello"));
	printf("%d \n", StringCompare("heklo", "hell"));



	return 0;
}