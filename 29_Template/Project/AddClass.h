#pragma once

template<typename T>// class T로도 작성하는데 기능은 같다 typename으로 통일하자
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
