#include<stdio.h>//�ּ�
#include<math.h>
/*
* �̰Ŵ� ���ּ�
* �Դϴ�
* ������
* [] ���ȣ
* {} �߰�ȣ
* () �Ұ�ȣ
*/
/*
�ƴ�
��¥��
*/
int main() {
	int a, b, c;
	a = 10;
	b = 10;
	c = 0;
	for (int i = 0; i < b; i++) {
		c += a* b;
	}
	char* p = "���� �̰� ����\n";
	printf(p);
	printf("hello world\n");
	printf("%d", c);

	return 0;
}