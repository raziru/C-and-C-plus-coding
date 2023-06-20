#pragma once
class Store
{
public:
	Store();
	~Store();

	void ShowItems();

	void RemoveItem(string name);

	map<string, Item>& GetItems() { return items; }//call by reference로 원본을 전달, &를 붙이면 참조자가 전달된다.
	                                               //정적인 객체를 보내는 것이기 때문에 reference로 전달하는게 좋다.
	                                               //의도적으로 수정을 지시할 것이기 때문에 객체지향에 집착할 필요는 없다.
	                                               //편의성을 위한 원본참조이기때문에 문제없다.
private:
	map<string, Item> items;
};

