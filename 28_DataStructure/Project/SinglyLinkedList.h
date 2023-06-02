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

	void PushBack(Node* newNode); //�ڿ� �о�ִ� ����带

	//����
	void PopBack();// ������ ��带 �����ϴ� �Լ�

	void Insert(Node* newNode, UINT index);// Ư���ε����� ��带 �����ϴ� �Լ�

	void Remove(UINT index);// Ư���ε����� ��带 �����ϴ� �Լ�

	void ClearList();
	// �� �� �Լ��� �����ؿ���
	void PrintList();

	Node* Find(UINT index);

private:
	Node*head = nullptr;

	UINT listSize = 0;
	

};

