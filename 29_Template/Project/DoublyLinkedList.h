#pragma once
#pragma once

template<typename T>
struct Node
{
	Node(T data)
		: data(data)
	{
	}
	T data;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
};


template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	Node<T>* Find(UINT index);
	T AT(UINT index);

	void PushBack(Node<T>* newNode);
	void PopBack();

	void Insert(Node<T>* newNode, UINT index);
	void Remove(UINT index);

	void Print();
	void Clear();

	UINT Size() { return listSize; };

private:
	Node<T>* head = nullptr;

	Node<T>* tail = nullptr;

	UINT listSize = 0;
};



template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template<typename T>
inline Node<T>* DoublyLinkedList<T>::Find(UINT index)
{

	Node<T>* node = nullptr;

	if (index <= listSize / 2)
	{
		node = head;
		for (UINT i = 0; i < index; i++)
		{
			node = node->next;
		}
	}
	else
	{
		node = tail;
		for (int i = listSize - 1; i >= index; i--)
		{
			node = node->prev;
		}
	}
	return node;
}

template<typename T>
inline T DoublyLinkedList<T>::AT(UINT index)
{
	return Find(index)->data;
}

template<typename T>
inline void DoublyLinkedList<T>::PushBack(Node<T>* newNode)
{
	if (head == nullptr)
	{
		head = newNode;

	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;

	}
	tail = newNode;
	listSize++;

}

template<typename T>
inline void DoublyLinkedList<T>::PopBack()
{
	if (listSize <= 0)

	{
		cout << "리스트가 비어있어서 삭제할 수 없습니다!" << endl;
		return;
	}

	if (listSize == 1)
	{
		delete head;
		//delete tail; //헤드와 테일이 같은곳을 가르키기 때문에 하나만 삭제하는게 맞다.

		head = nullptr;
		tail = nullptr;
		listSize--;
		return;
	}

	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
	listSize--;
}

template<typename T>
inline void DoublyLinkedList<T>::Insert(Node<T>* newNode, UINT index)
{
	if (index < 0 || index>listSize)
	{
		cout << "인덱스가 범위를 벗어납니다!" << endl;
		return;
	}

	if (index=listSize)
	{
		PushBack(newNode);
	}



	Node<T>* node = Find(index-1);
	node->next->prev = newNode;
	node->next = newNode;

	listSize++;
}

template<typename T>
inline void DoublyLinkedList<T>::Remove(UINT index)
{
	if (index<0 || index>listSize)
	{
		cout << "인덱스가 범위를 벗어납니다!" << endl;
		return;
	}


	Node<T>* node = Find(index);
	node->next->prev = node->prev;
	node->prev->next = node->next;

	delete node;
	listSize--;

}

template<typename T>
inline void DoublyLinkedList<T>::Print()
{
}

template<typename T>
inline void DoublyLinkedList<T>::Clear()
{
}


