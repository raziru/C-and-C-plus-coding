#include <iostream>
#include<string>
using namespace std;

/*
범위 기반 For 문(Range Based For)

범위 내의 변수들에게 모두 같은 동작을 시키고 싶을 때 사용한다.

범위? 배열, 자료구조 

형식:

for (개별변수형 임시변수이름 : 범위(배열의 이름))
{

    명령문;
}

int i in range arr

*/

struct Player
{
    string name;
    int   level;
    float hp;

};

int main()
{
    int arr[] = { 1,2,3,4,5 };

    for (int i : arr) //인덱스로 접근할 필요가 없음!, 순서를 무시하고 같은 동작을 진행할때 사용한다.
    {
        cout << i << endl;
    }

    string str = "Hello World!";

    for (char c : str)
    {
        cout << c << endl;
    }

    Player players[10];

    for (int i = 0; i < 10; i++)
    {
        players[i].name  = "Player" +  to_string(i);
        players[i].level =          i;
        players[i].hp    = 100.0f * i;
    }

    /*for (int i = 0; i < 10; i++)
    {
        cout << players[i].name  << endl;
        cout << players[i].level << endl;
        cout << players[i].hp    << endl;

    }*/

    for (Player p : players)
    {
        cout << p.name << endl;
        cout << p.level << endl;
        cout << p.hp << endl;

       
    }

    for (Player p : players)
    {
        for (char c : p.name)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    

    return 0;
}

