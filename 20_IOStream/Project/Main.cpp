#include<iostream> 

using namespace std;
//���� �����Ҷ� ���� ��ũ��Ʈ�̴�.
//std��� namespace�� ������̴�. ���̺귯���� ����ٵа� ���� std��� namespace�� ����ȵȴ�.


/*
C vs C++

namespace


*/

/*
���ۿ� �˻��ؼ�
C�� C++�� ������
������������ paraphrasing, �ڽ��� �ܾ�� �ٲ㼭 ����
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
}//c++�� ������� namespace�� �����Ǿ��ִ�.

struct D
{
	static int d;
};
int main()
{
	D d; // struct�� �ݵ�� ��ü�� ������ �� �� �ִ�.
	d.d;

	A::a;
	B::b;
	C::c;

	D::d;

	cout << "Hello world!" << endl;//standard��� namespace�� �ִ� cout�� ȣ���Ѵ�.
	cout << "Hello world!" << endl;//standard��� namespace�� �ִ� cout�� ȣ���Ѵ�.

	cout << 456 << "helloworld" << endl;

	int a;

	char b;

	cin >> a;

	cin >> b;

	cout << a << "10��" << b << "��" << endl;

	string str;

	cin >> str;
	cout << str << endl;

	cout << a << "\t" << str << endl;

	cout << "arr[" << a << "]=" << a << endl;

	string str2 = "Hello";//std�� ����� string
	if (str == str2)
		cout << "Same" << endl;
	cout << str + str2 << endl;
	return 0;
}