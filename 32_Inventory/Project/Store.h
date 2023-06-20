#pragma once
class Store
{
public:
	Store();
	~Store();

	void ShowItems();

	void RemoveItem(string name);

	map<string, Item>& GetItems() { return items; }//call by reference�� ������ ����, &�� ���̸� �����ڰ� ���޵ȴ�.
	                                               //������ ��ü�� ������ ���̱� ������ reference�� �����ϴ°� ����.
	                                               //�ǵ������� ������ ������ ���̱� ������ ��ü���⿡ ������ �ʿ�� ����.
	                                               //���Ǽ��� ���� ���������̱⶧���� ��������.
private:
	map<string, Item> items;
};

