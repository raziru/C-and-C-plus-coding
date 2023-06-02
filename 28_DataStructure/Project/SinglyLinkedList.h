#pragma once

struct Node
{
	Node(int data)
		: data(data)
	{

	}


	int   data = 0;
	Node* next = nullptr;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void PushBack(Node* newNode); //뒤에 밀어넣다 새노드를

	//숙제
	void PopBack();// 마지막 노드를 제거하는 함수

	void Insert(Node* newNode, UINT index);// 특정인덱스에 노드를 삽입하는 함수

	void Remove(UINT index);// 특정인덱스에 노드를 제거하는 함수

	void ClearList();
	// 이 세 함수를 구현해오기
	void PrintList();

	Node* Find(UINT index);

private:
	Node*head = nullptr;

	UINT listSize = 0;
	

};

