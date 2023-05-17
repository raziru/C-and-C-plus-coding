#include<iostream> 

using namespace std;
//최초 설정할때 쓰는 스크립트이다.
//std라는 namespace를 사용중이다. 라이브러리를 끌어다둔것 절대 std라는 namespace를 쓰면안된다.


/*
C vs C++

namespace


*/

/*
구글에 검색해서
C와 C++의 차이점
복붙하지말고 paraphrasing, 자신의 단어로 바꿔서 적기
*/

namespace A
{
	int a;
	int b;
	int c;

}
namespace B
{
	int b;
}

namespace C
{	
	int c;
}//c++은 헤더들이 namespace에 보관되어있다.

struct D
{
	static int d;
};
int main()
{
	D d; // struct는 반드시 객체를 만들어야 쓸 수 있다.
	d.d;

	A::a;
	B::b;
	C::c;

	D::d;

	cout << "Hello world!" << endl;//standard라는 namespace에 있는 cout을 호출한다.
	cout << "Hello world!" << endl;//standard라는 namespace에 있는 cout을 호출한다.

	cout << 456 << "helloworld" << endl;

	int a;

	char b;

	cin >> a;

	cin >> b;

	cout << a << "10은" << b << "야" << endl;

	string str;

	cin >> str;
	cout << str << endl;

	cout << a << "\t" << str << endl;

	cout << "arr[" << a << "]=" << a << endl;

	string str2 = "Hello";//std에 내장된 string
	if (str == str2)
		cout << "Same" << endl;
	cout << str + str2 << endl;
	return 0;
}