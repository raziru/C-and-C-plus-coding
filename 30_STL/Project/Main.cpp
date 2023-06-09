#include "Framework.h"

/*
STL (Standard Template Library)

Container(자료구조):
vector, list, stack, heap, map .. 등등

1. 순차 컨테이너 (Sequence): 선형자료구조 - vector, deque, list, forward_list

'vector' : 동적인 배열

2. 연관 컨테이너 (Associative) : 'key' , 'value' - pair / 키 값 쌍

키와 값이 쌍으로 이루어져 있는 구조

map, multi_map, unordered_map, set, multi_set, unordered_set
multi_map은 key중복을 허가한 맵
map : key와 value의 쌍

key : ID 

3. 컨테이너 어댑터 (Container Adapter)


Iterator(반복자): 컨테이너로 부터 값을 읽는데 사용하는 포인터 변수


Algorithm(알고리즘):

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