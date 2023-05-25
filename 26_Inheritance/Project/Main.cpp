#include "Framework.h"

/*




상속(Inheritance):

코드를 재사용하는 방법 중 하나 / 클래스끼리 부모자식관계를 설정

재정의 / 부모가 변수 함수를 작성하고 자식이 그 내용을 자신의 기능에 맞춰서 재정의한다. 재사용+재정의

Overriding(오버라이딩): 

부모에 있는 함수를 자식 단계에서 '재정의'하는 기능

형변환(Casting): 변수형을 바꾸는 것

int n = (int) 1.5f;
명시적 형변환: 변환 할 변수형을 직접 적어주는것 -- cin으로 받은 정보를 enum에 입력할 때
int n = 1.5f;
암묵적 형변환: 변환 할 변수형을 직접 적어주지 않더라도 시스템이 알아서 처리

업 캐스팅(Up - Casting)

자식 클래스를 부모 클래스로 형변환 하는 것

다운 캐스팅(Down - Casting)

부모 클래스를 자식 클래스로 형변환 하는 것

가상함수(Virtual Function): 

업캐스팅이 이루어진 상황에서 부모 단계의 함수가 아니라
오버라이딩된 자식 단계의 함수를 호출하게 해주는 기능

가상함수는 = "이 함수 자식 단계에서 재정의 됐을 수도 있으니까, 가서 확인해봐라"

자식들이 가질거 같은 함수를 가상으로 만들어놓는 것

순수 가상함수 (Pure - Virtual Function):

자식 단계에서 '반드시' 재정의 해야하는 함수 -- 부모 클래스가 아닌 자식 클래스에서만 사용할 것같은 함수

virtual 함수 = 0; //선언하고 정의가 없게 설정했다. 추상적으로(실존 하지 않는) 함수가 선언된것 -- 그 어떤 클래스도 순수 가상함수를 가진 경우 선언될 수 없다. 



추상 클래스(Abstract Class):

순수 가상 함수를 한 개 이상 가진 클래스 

순수 가상 함수는 정의되지 않은 함수이기 때문에

추상클래스를 변수로 선언할 수 없다(메모리 할당 불가능)//정적 할당도 동적할당도 변수 선언도 성립되지 않는다. -- 컴퓨터는 빈칸인것에 의문을 가지고 자식의 함수를 찾게 된다.

인터페이스(Interface):

오직 순수 가상함수만 가지고 있는 클래스 // 변수 X, 순수 가상 함수만 -- 형식만 있는 클래스

*/



int main()
{
    /*Pikachu* pikachu = new Pikachu();
        Mew* mew     = new Mew();*/

    Character* player1 = nullptr;
    Character* player2 = nullptr;

    cout << "캐릭터를 선택하세요! 1. 피카츄 2. 뮤" << endl;

    int input;
    cin >> input;

    switch (input)
    {
        case 1:
            player1 = new Pikachu();
            player2 = new Mew();
            break;
        case 2:
            player1 = new Mew();
            player2 = new Pikachu();
            break;
        case 3:
            player1 = new Mage();
            player2 = new Pikachu();
            player1->SetCombat();
        default:
            break;
    }


    player1->ShowInfo();
    player2->ShowInfo();

    player1->Attack(player2);
    player2->Attack(player1);


    delete(player1);
    delete(player2);
    return 0;
}
