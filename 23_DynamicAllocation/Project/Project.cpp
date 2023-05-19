#include <iostream>

using namespace std;

/*
동적 할당(Dynamic Allocation): 게임 플레이 중 실시간으로 메모리를 할당/해제 하는 것
변수할당과 메모리할당의 시점이 달라질 수 있다. -> 용량을 자유롭게 통제할 수 있다.


선언 방법:

1. 객체를 선언하는 대신, 객체를 가리킬 포인터 변수를 선언한다.

Character* player;

2. 포인터 변수 이름 = new 변수형();

new : 할당된 메모리의 첫번째 주소값을 반환하는 연산자

클래스(class): 설계도

객체(object): 설계도로 구현된 대상

인스턴스(instance): 동적할당된 존재의 실체

*클래스 인스턴스는 서로 연관되어있어 구분하지 않아도 된다.

*/

class Character
{
public:
	Character()
	{
		cout << name << "생성자 호출!" << endl;
	}
	Character(string name)
		: name(name)
	{
		cout << name << "생성자 오버로딩호출!" << endl;
	}
	~Character()
	{
		cout << name << "소멸자 호출!" << endl;

	}

//private:
	string name;
	int level;
	float hp;
	bool isDead;
};

	//(*player).hp;==player->hp;
void Add(int value)
{
	static int sum = 0;
	sum += value;
	cout << "sum    = " << sum << endl;
}



int main()
{
	
	int size = 0;

	cout << "배열의 크기를 입력하세요! :";
	cin >> size;

	int* arr = nullptr;

	arr = new int[size];//size로 접근이 불가능

	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
		Add(arr[i]);
		cout << endl;
	}

	delete[] arr;//배열은 []를 붙인다. -- new와 동시에 delete를 같이 만들어놓는게 좋다.

	arr = nullptr;


    return 0;
}

int main2() 
{
	//Character player;

	Character* player = nullptr;//빈공간으로 지정

	/*

	Character p;
	player = &p;


	player->hp; */ //new 명령어 하나로 압축된다.

	player = new Character("Chao");
	//new == &, new 하는 대상의 주소값을 반환한다. 변수생성으로 시간을 소비할 필요를 없앤다.
	// 선언할때만 사용할 수 있다.

	(*player).hp;

	delete player;
	return 0;
}
