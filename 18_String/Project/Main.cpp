#include<stdio.h>
#include<string>//string.h�� c���� ���� ������� string�� ������ �� �������ִ�.
#include<ctime>

/*
���ڿ�(string) : ������ �迭, char�� �迭

NULL ����('\0') : ���ڿ��� ���� �˸��� ����

���ڿ��� ���� ���������� NULL ���ڰ� �ڵ����� �����.

�迭�� �Լ��� �Ű������� ����� ����, Call-By-Value�� ������� ���Ѵ�.

�ڵ����� Call-By-Address�� �޾ƿ��� �ȴ�.



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
	str1�� str2�� ���̸� ��

	���࿡ �� ���ڿ��� ��ġ�ϸ� 1�� ��ȯ

	�ٸ���,

	str1�� ���̰� �� ũ�� 2�� ��ȯ,
	str2�� ���̰� �� ũ�� 3�� ��ȯ,

	�� ���ڿ��� ���̸� ���� ��ġ���� ������ 0�� ��ȯ

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
	char str1[] = "HelloWorld!";//12���� ��ü

	const char* str2 = "ByeBye\n";//12���� ��ü

	//PrintString(str);

	printf("%d\n", StringLength(str1));//�迭�� ũ�⸦ �޴´�.

	//PrintString(str2);

	printf("strcmp: %d\n",strcmp(str1, str2));
	printf("strcmp: %d\n", strcmp(str2, str1));//���ĺ� ������
	printf("strcmp: %d\n", strcmp(str1, str1));

	char str3[] = "HelloWorld!";

	//printf(str3);

	printf("%d \n", StringCompare("hello", "hello"));
	printf("%d \n", StringCompare("heklo", "hello"));
	printf("%d \n", StringCompare("hekl", "hello"));
	printf("%d \n", StringCompare("heklo", "hell"));



	return 0;
}