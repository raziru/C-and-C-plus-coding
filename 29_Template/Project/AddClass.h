#pragma once

template<typename T>// class T�ε� �ۼ��ϴµ� ����� ���� typename���� ��������
class AddClass
{
public:
    AddClass();

    AddClass(int a, int b)
        :a(a), b(b)
    {

    }
    ~AddClass();

    void Print();


private:
    T a;
    T b;
};

template<typename T>
inline AddClass<T>::AddClass()
{
}

template<typename T>
inline AddClass<T>::~AddClass()
{
}

template<typename T>
inline void AddClass<T>::Print()
{

    cout << a << " + " << b << " = " << a + b << endl;

}
