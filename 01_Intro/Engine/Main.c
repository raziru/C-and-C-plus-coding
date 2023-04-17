#include<stdio.h>//주석
#include<math.h>
/*
* 이거는 긴주석
* 입니다
* 정말로
* [] 대괄호
* {} 중괄호
* () 소괄호
*/
/*
아니
진짜네
*/
int main() {
	int a, b, c;
	a = 10;
	b = 10;
	c = 0;
	for (int i = 0; i < b; i++) {
		c += a* b;
	}
	char* p = "야이 이게 뭐냐\n";
	printf(p);
	printf("hello world\n");
	printf("%d", c);

	return 0;
}