#include "Framework.h"

/*
상속(Inheritance):

코드를 재사용하는 방법 중 하나 / 클래스끼리 부모자식관계를 설정

재정의 / 부모가 변수 함수를 작성하고 자식이 그 내용을 자신의 기능에 맞춰서 재정의한다. 재사용+재정의

Overriding(오버라이딩): 

부모에 있는 함수를 자식 단계에서 '재정의'하는 기능



*/



int main()
{
    Pikachu* pikachu = new Pikachu();
        Mew* mew     = new Mew();


    pikachu->ShowInfo();
        mew->ShowInfo();

    pikachu->Attack(mew);
        mew->Attack(pikachu);


    delete(mew);
    delete(pikachu);
    return 0;
}
