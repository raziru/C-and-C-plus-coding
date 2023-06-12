#include"Framework.h"

template <typename T>
void Swap(T& a, T& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
    DoublyLinkedList<int>* list;
	list = new DoublyLinkedList<int>;
	for (int i = 0; i < 10; i++)
	{
		Node<int>* newNode = new Node<int>(i * 10);
		newNode->next = nullptr;
		newNode->prev = nullptr;

		list->PushBack(newNode);
	}
	Node<int>* newNode = new Node<int>(999);
	newNode->next = nullptr;
	newNode->prev = nullptr;
	Node<int>* newNode2 = new Node<int>(9999);
	newNode2->next = nullptr;
	newNode2->prev = nullptr;

	cout << "헤드에 입력" << endl;
	list->Insert(newNode, 0);
	list->Print();
	cout << "리스트 길이: " << list->Size() << endl;

	cout << "테일에 입력" << endl;
	list->Insert(newNode2, 11);
	list->Print();
	cout << "리스트 길이: " << list->Size() << endl;

	cout << "헤드를 삭제" << endl;

	list->Remove(0);
	list->Print();
	cout << "리스트 길이: " << list->Size() << endl;

	cout << "index 7을 삭제" << endl;

	list->Remove(7);
	list->Print();
	cout << "리스트 길이: " << list->Size() << endl;

	cout << "클리어" << endl;

	list->Clear();
	list->Print();
	cout<<"리스트 길이: "<< list->Size() << endl;

	
	return 0;
}

int main1()
{
	return 0;
}

