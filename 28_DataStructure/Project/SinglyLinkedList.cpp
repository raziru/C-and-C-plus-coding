#include "Framework.h"
#include "SinglyLinkedList.h"


SinglyLinkedList::SinglyLinkedList()
{
}

SinglyLinkedList::~SinglyLinkedList()
{
}

void SinglyLinkedList::PushBack(Node* newNode)
{
	if (head == nullptr)
	{
		head = newNode;

		listSize++;

		return;
	}

	Node* lastNode = Find(listSize - 1);

	lastNode->next = newNode;

	listSize++;
}

void SinglyLinkedList::PopBack()
{
}

void SinglyLinkedList::Insert(Node* newNode, UINT index)
{
}

void SinglyLinkedList::Remove(UINT index)
{
}

void SinglyLinkedList::ClearList()
{
}

void SinglyLinkedList::PrintList()
{
	Node* node = head;
	UINT count = 0;
	while (true)
	{
		cout << count++ << "번 쨰 노드 데이터" << node->data << endl;
		node = node->next;

		if (node ==nullptr )
		{
			break;
		}
	}
}

Node* SinglyLinkedList::Find(UINT index)
{
	Node* node = this->head;

	/*Node* node1 = head;

	Node* node2 = node1->next;

	Node* node3 = node2->next;

	node3 == node1->next->next;*/

	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}

	return node;
}

