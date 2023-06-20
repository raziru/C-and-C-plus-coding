#include"Framework.h"


/*
Operator Overloading (연산자 오버로딩):

기존에 존재하는 연산자에 새로운 기능을 부여하는 기법

함수

반환형 함수이름(매개 변수)
{
    명령문;
}

반환형 : 연산의 결과값의 형식

함수이름은 : 내가 오버로딩한 연산

매개변수 : 두 번째 피연산자의 변수형

*/



int main()
{
    Point p1(10, 20);
    Point p2(30, 40);
    Point p3;

    /*p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;*/

    p3 = p1 + p2;

    cout << "p3 = " << p3.x << " , " << p3.y << endl;

    p3 += p1;

    cout << "p3 = " << p3.x << " , " << p3.y << endl;

    //p3 = p1 * 0.5f;

    p3 << 2;


    cout << "p3 = " << p3.x << " , " << p3.y << endl;

    return 0;
}

