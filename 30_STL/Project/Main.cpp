#include "Framework.h"

/*
STL (Standard Template Library) : 자료구조, 알고리즘을 템플릿으로 정리한 라이브러리

1. Container(자료구조):
vector, list, stack, heap, map .. 등등

1-1) Sequence Container(순차 컨테이너) : 선형자료구조 - vector, deque, list(doublelinkedlist), forward_list

'vector' : 동적인 배열

1-2) Associative Container(연관 컨테이너) : pair('key' , 'value') : ('키' , '값') 쌍

키와 값이 쌍으로 이루어져 있는 구조

key : ID (identifier)

set, map

map : key와 value의 쌍
map, multi_map, unordered_map, set, multi_set, unordered_set // map은 입력이 들어오면 항상 정렬해준다. unordered_map은 입력된 순서를 보존해준다.
multi_map은 key중복을 허가한 맵

'map'


stl은 map과 vector를 가장 많이 쓴다.

1-3) Container Adapter (컨테이너 어댑터): 컨테이너를 변형한 자료구조
- stack, queue, priority queue


2. Iterator(반복자): 컨테이너로 부터 값을 읽는데 사용하는 '포인터 변수' // find함수에 선언되는 포인터 변수처럼 컨테이너를 순회할때 사용되는 포인터 변수들


3. Algorithm(알고리즘): 문제 해결을 위한 논리의 흐름을 정리해둔 것

- Swap, Find, Sort //자료구조 알고리즘 공부는 암기이며 함수로 떼우는 게 맞지 개념에 직찹하지말자.

*/
enum Type
{
	WEAPON,
	ARMOR,
	HELMET
};

struct Item
{
	void ShowInfo()
	{
		cout << name << endl;
		cout << price << endl;
		cout << damage << endl;
	}
	string name;
	UINT   price;
	float  damage;
};

int main()
{
	//<key, value>  key는 중복 불가 value는 중복 가능
	map<string, int> intMap;

	intMap.insert(pair<string, int>("Armor", 1));
	intMap.insert({ "Helmet", 1 });

	intMap.emplace( "Weapon", 1 ); //가장 빠르고 안정적인 삽입 방법이다.

	for (pair<string,int> pair : intMap)
	{
		cout << "Key   : " << pair.first << endl;
		cout << "Value : " << pair.second << endl;

	}
	cout << intMap["Weapon"] << endl;

	if (intMap.count("Weapon") > 0)
	{
		cout << "Weapon이 존재합니다." << endl;
	}
	else if (intMap.count("Weapon")==0)
	{
		cout << "Weapon이 존재하지 않습니다." << endl;
	}

	map<Type, Item> inventory;

	Type type;

	type = ARMOR;
	Item item;

	item.name = "천갑옷";
	item.price = 300;
	item.damage = 100;
	inventory.emplace(type, item);

	type = WEAPON;

	item.name = "도란검";
	item.price = 450;
	item.damage = 200;

	inventory.emplace(type, item);

	for (pair<Type,Item> pair:inventory)
	{
		switch (pair.first)
		{
		case WEAPON:
			cout << "무기 : " << endl;
			break;
		case ARMOR:
			cout << "방어구 : " << endl;
			break;
		case HELMET:
			cout << "헬멧 : " << endl;
			break;
		default:
			break;
		}
		pair.second.ShowInfo();

	}
	return 0;
}
int main1()
{
    vector<int> intVector;

	for (UINT i = 0; i < 10; i++)
	{
		intVector.push_back(i + 1);
	}
	vector<int>::iterator iter;

	iter = intVector.begin();//head를 반환하는 함수
	while (true)
	{
		cout << *iter++ << endl;//++로 이동한다. Array와 기능을 유사하게 만들어줌

		if (iter == intVector.end())
			break;
		
	}

	int index = 3;

	intVector.emplace_back();


	intVector.erase(intVector.begin() + index);


	//iter = intVector.begin();//head를 반환하는 함수
	//while (true)
	//{
	//	cout << *iter++ << endl;//++로 이동한다. Array와 기능을 유사하게 만들어줌

	//	if (iter == intVector.end())
	//		break;

	//}

	for (int i : intVector)//범위 기반 for문
	{
		cout << i<< endl;//++로 이동한다. Array와 기능을 유사하게 만들어줌

	}

	for (UINT i = 0; i < intVector.size(); i++)
	{
		cout << intVector[i] << endl;
	}

    return 0;
}