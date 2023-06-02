#include "Framework.h"

/*
자료 구조(Data Structure): --면접볼때 활용하는 정보

컴퓨터에서 자료를 처리할 때 효율적으로 관리하고 구조화시키기 위한 학문

변수를 구조화하고 정리하는 방법

변수를 모아놓는 여러가지 방법 ex) 배열, 구조체, 클래스, 포인터

1. 미리 정의 된 자료구조

1-1) 기본 자료구조 : 정수형, 실수형, 논리형, 문자형

1-2) 파생된 자료구조 : 배열, 구조체, 클래스, 포인터

2. 사용자 정의 자료구조 :

2-1) 선형(Linear) 자료구조 : 배열, 리스트, 스택(stack), 큐(Queue), 데크/디큐(Deque)

2-2) 비선형 자료구조 : 트리(tree), 그래프(Graph) -- 알고리즘과 연관되는 자료구조

연결 리스트(Linked List) : 노드끼리 '논리적인 순서'로 이어져있는 자료구조

단순 연결 리스트 (Singly Linked List, SLL)
이중 연결 리스트 (Doubly Linked List, DLL)
원형 연결 리스트 (Circular Linked List CLL)

Node(노드) : 데이터 값을 가지고 있는 공간

Edge(엣지) : 노드와 노드를 연결하는 선




Standard Template Library(STL) : vector(선형, 배열과 유사하고 완전히 대체하는 자료구조), map -- 조사해오기 

*/


int main() //namespace로 선언은 못한다.
{
	SinglyLinkedList list;

	for (UINT i = 0; i < 10; i++)
	{
		Node* node = new Node(i * 10);

		list.PushBack(node);
	}

	list.PrintList();
	return 0;
}

