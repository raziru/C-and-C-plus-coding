#include <iostream>
#include <string>


using namespace std;

/*
class: struct의 C++ 버전

C vs c++

C++은 기본적으로 C에 비해서 모든 것들이 전체적으로 접근하기 힘들다. 보안이 강해졌다!

접근 지정자(Access Modifier):

public   : 클래스 외부에서도 접근이 가능//밖에서 침투를 방지

private  : 클래스 내부에서만 접근이 가능

protected: 상속된 자식에서도 접근이 가능

기본 접근 지정자 :

struct = public
class  = private

this : 나 자신을 가리키는 포인터 변수

*this

클래스 내부의 변수 : 맴버 변수
클래스 내부의 함수 : 맴버 함수(메소드, Method)

객체(object) : 클래스로 만들어진 변수

생성자(constructor) : 객체가 생성될 때 실행되는 함수 -- 전투의 함성
소멸자( destructor) : 객체가 소멸될 때 실행되는 함수 -- 죽음의 메아리 
--나중에 생성된게 먼저 소멸하고 먼저 소멸한게 나중에 소멸한다.

생성자 오버로딩

initializer (이니셜라이저) : 초기화 해주는 애, 생성자에서 변수의 초기값을 정해주는 역할

함수의 매구변수에 기본값을 설정할 수 있다.


*/

typedef unsigned int UINT;

class Character
{
public:
    Character()
    {
        cout << name << "캐릭터 생성!" << endl;

        cout << "생성자 호출!" << endl;
    }

    Character(string name)
        :name(name)
    {
        cout << (*this).name << "캐릭터 생성!" << endl;
        cout << "생성자 오버로딩 1 호출!" << endl;

    }

    Character(string name, UINT level, float hp=0.0f, bool isDead=false) // 매개변수 기본값은 제일 뒤의 매개변수부터 넣는다.
        :name(name), level(level),hp(hp),isDead(isDead)//초기화도 함수의 일부 ,로 구별 
    {
        cout << (*this).name << "캐릭터 생성!" << endl;
        cout << (*this).level << "캐릭터 레벨!" << endl;

        cout << "생성자 오버로딩 2 호출!" << endl;


    }

    ~Character()
    {
        cout << name << "캐릭터 소멸!" << endl;

    }
    void ShowInfo()
    {
        cout << "-------Charater Info-------"   << endl;
        cout << "name   : " << name   << endl;
        cout << "level  : " << level  << endl;
        cout << "hp     : " << hp     << endl;
        cout << "isDead : " <<(isDead ? "Dead":"Alive") << endl;

    }
    void SetInfo(string name, UINT level, float hp, bool isDead)
    {
        /*
        (*this).name   = name;
        (*this).level  = level;
        (*this).hp     = hp;
        (*this).isDead = isDead;
        */

        this->name   = name;
        this->level  = level;
        this->hp     = hp;
        this->isDead = isDead;
    }

private:
    string name;
    UINT   level;
    float  hp;
    bool   isDead;

};



int main()
{
    Character player;

    player.SetInfo("chao", 10, 100.0f, false);

    player.ShowInfo();

    Character enemy;//앞에서부터 채워넣어야한다.

    enemy.SetInfo("Park", 5, 10.0f, true);

    enemy.ShowInfo();

}
