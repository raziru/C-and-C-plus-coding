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

/*
class inventory 만들기

소지품(아이템) 보관하는 인벤토리

struct item
{
}
아이템을 저장하는 vectro를 만들기

아이템 추가 삭제 조회등등 기능만들기

struct안에 아이템의 기능을 넣는다.

*/
enum State
{
	IDLE,
	WALK,
	JUMP
};

enum Type
{
	WEAPON,
	ARMOR,
	HELMET
};

class Animation
{
public:
	
	Animation();
	~Animation();//맴버 함수: 메소드
	int ID;//맴버 변수
private:
	
};

Animation::Animation()
{
}

Animation::~Animation()
{
}

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
//vector-- 성능좋은 배열이 필요할 때 map-- 중복을 거부할 필요가 있을때 사용
int main()
{
	//<key, value>  key는 중복 불가 value는 중복 가능//키 값 쌍
	map<string, int> intMap;//보통 키는 스트링을 할당한다.


	intMap.insert(pair<string, int>("Armor", 1));//pushback이 없다.
	intMap.insert({ "Helmet", 1 });

	intMap.emplace( "Weapon", 1 ); //가장 빠르고 안정적인 삽입 방법이다.
	intMap.emplace("Weapon", 123); //key 중복은 거부한다.


	for (pair<string,int> pair : intMap)
	{
		cout << "Key   : " << pair.first << endl;
		cout << "Value : " << pair.second << endl;

	}
	cout << intMap["Weapon"] << endl;

	if (intMap.count("Weapon") > 0)//multi_map은 실제 개수, 나머지는 0개 or 1개만 출력된다. 중복이 없기때문
	{
		cout << "Weapon이 존재합니다." << endl;
	}
	else if (intMap.count("Weapon")==0)
	{
		cout << "Weapon이 존재하지 않습니다." << endl;
	}

	map<State, Animation*> animMap;

		State state;

	animMap.emplace(IDLE, new Animation());
	animMap.emplace(WALK, new Animation());
	animMap.emplace(JUMP, new Animation());

	animMap[IDLE]->ID= 10;
	animMap[WALK]->ID = 20;
	animMap[JUMP]->ID = 30;



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
    vector<int> intVector;//size를 지정할 필요가 없다. -- 여유있게 메모리를 할당해두고 만약 다음에 들어갈 공간에 다른 개체가있으면 아예 벡터의 모든 것을 다른 위치로 이동시킨다. 

	
	for (UINT i = 0; i < 10; i++)
	{
		intVector.push_back(i + 1);
	}
	vector<int>::iterator iter;//class에 들어있는 변수형

	iter = intVector.begin();//head를 반환하는 함수

	/*cout << *iter << endl;

	iter++;

	cout << *iter << endl;*/

	/*for (vector<int>::iterator iter = intVector.begin(); iter !=intVector.end(); iter++)
	{
		cout << *iter << endl;
	}*/

	/*while (true)
	{
		cout << *iter << endl;
		iter++;
		if (iter==intVector.end())
		{
			break;
		}
	}*/

	for (UINT i = 0; i < intVector.size(); i++)//일부만 사용할때
	{
		cout << &intVector[i] << endl;
	}
	int index = 5;

	intVector.erase(intVector.begin() + index);//iterator를 요구한다. 하지만 선언할필요가 없다.

	cout << "---------------------" << endl;

	intVector.insert(intVector.begin() + index, 100);

	intVector.emplace_back();

	for (int i : intVector)//범위 기반 for문 -- 자료구조를 위한 기술이기때문에 많이쓰인다. 전체를 건들때
	{
		cout << i << endl;//++로 이동한다. Array와 기능을 유사하게 만들어줌

	}




	


    return 0;
}