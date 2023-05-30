#include "Framework.h"

/*
턴제 RPG

부모캐릭터 클래스 만들기

1. 캐릭터 클래스는 상속받아서 여러개의 자식캐릭터 클래스만들기

최소 3개 이상, 각캐릭터는 자신만의 고유한 변수 1개이상

전사: 방어도 마법사: 마나 뱀파이어: 피의 구슬 파이터: 콤보

2. 전투구현

최소 기본공격 1개, 스킬 1개 이상 만들기

변수의 영향을 받아서 공격력 방어력

3. 자동 전투 (확률에 따라서 혹은 조건에 따라서)

플레이어는 직접 조종해도 상관없음

+@ 전투가 끝나면 통계가 나오게

4. 메뉴 구현: 캐릭터 생성, 전투, 정보 출력, 등등

5. 순수 가상 함수, 가상함수 반드시 1개 이상 사용

*/

enum Job
{
    WARRIOR = 1,
    MAGE = 2,
    FIGHTER = 3,
    VAMPIRE = 4
};

enum Button
{
    SHOWINFO = 0,
    ATTACK,
    SKILL1,
    SKILL2,
    SKILL3,
    SKILL4,
    SHOWTRAIT =8
    
};
enum Menu
{
    BATTLE = 1,
    CHANGE,
    SHOW,
    CLOSE
};

void Battle(Character*player) 
{
    Character* enemy = nullptr;
    Job input = (Job)(rand() % 4 + 1);
    switch (input)
    {
    case WARRIOR:
        enemy = new Warrior("적");
        break;
    case MAGE:
        enemy = new Mage("적");
        break;
    case FIGHTER:
        enemy = new Fighter("적");
        break;
    case VAMPIRE:
        enemy = new Vampire("적");
        break;
    default:
        break;
    }
    Button button;
    bool playerTurn = true;
    player->Reset();
    int random = rand() % 2;
    if (random == 0)
    {
        playerTurn = true;
        cout << "플레이어 선공!" << endl;
    }
    else
    {
        playerTurn = false;
        cout << "적의 선공!" << endl;
    }
    int turn = 0;

    while (true)
    {
        
        cout << "---------------------------" << endl;
        if (playerTurn)
        {
            player->ShowInfo();
            enemy->ShowInfo();
            cout << "---------- 제" << ++turn << "턴 ----------" << endl;
            cout << "당신의 턴입니다." << endl;
            cout << "1. 기본공격 2. 기본 스킬 3. 필살기 4. 자원 생성 5. 스탯강화 0. 상태 표시 8. 조언표시" << endl;
            scanf_s(" %d", &button);
            system("cls");

            switch (button)
            {
            case ATTACK:
                player->Attack(enemy);
                playerTurn = false;
                player->Passive();
                break;
            case SKILL1:
                player->Skill_1(enemy);
                playerTurn = false;
                player->Passive();
                break;
            case SKILL2:
                player->Skill_2(enemy);
                playerTurn = false;
                player->Passive();
                break;
            case SKILL3:
                player->Skill_3(enemy);
                playerTurn = false;
                player->Passive();
                break;
            case SKILL4:
                player->Skill_4(enemy);
                playerTurn = false;
                player->Passive();
                break;
            case SHOWINFO:
                turn--;
                break;
            case SHOWTRAIT:
                player->ShowTrait();
                turn--;
                break;

            default:
                
                break;
            }
        }
        else
        {

            random = rand() % 10;
            if (random >= 2) //공격기술이 70퍼확률로 더많이 사용
            {
                button = (Button)(rand() % 3 + 1);
            }
            else
            {
                button = (Button)(rand() % 2 + 4);

            }
            switch (button)
            {
            case ATTACK:
                enemy->Attack(player);
                break;
            case SKILL1:
                enemy->Skill_1(player);
                break;
            case SKILL2:
                enemy->Skill_2(player);
                break;
            case SKILL3:
                enemy->Skill_3(player);
                break;
            case SKILL4:
                enemy->Skill_4(player);
                break;
            default:
                break;
            }

            enemy->Passive();
            playerTurn = true;

        }
        if ((player->GetHP() <= 0) || (enemy->GetHP() <= 0))
        {
            if (enemy->GetHP() <= 0)
            {
                cout << "적의 HP가 0이 됐다!" << endl;

                cout << "플레이어의 승리!" << endl;
                player->SetWin();
                enemy->SetLose();

            }
            else if (player->GetHP() <= 0)
            {
                cout << "플레이어의 HP가 0이 됐다!" << endl;

                cout << "적의 승리!" << endl;
                player->SetLose();
                enemy->SetWin();
            }
            else
            {
                cout << "무승부!" << endl;
            }
            
            break;
        }

    }

    delete(enemy);
}


int main()
{
    srand(time(NULL));

    string name = "";
    cout << "이름을 입력해주세요! :";
    cin >> name;
    cout << "직업을 선택하세요" << endl << "1. 전사 2. 마법사 3. 격투가 4. 뱀파이어" << endl;
    Character* player = nullptr;
    Job input;
    scanf_s(" %d", &input);
    system("cls");

    switch (input)
    {
    case WARRIOR:
        player = new Warrior(name);
        break;
    case MAGE:
        player = new Mage(name);
        break;
    case FIGHTER:
        player = new Fighter(name);
        break;
    case VAMPIRE:
        player = new Vampire(name);
        break;
    default:
        break;
    }
    
    Menu menu;
    while (true)
    {
        cout << "1. 전투 2. 직업변경 3. 전적확인 4. 종료" << endl;
        scanf_s(" %d", &menu);
        system("cls");
        switch (menu)
        {
        case BATTLE:
            Battle(player);
            break;
        case CHANGE:
            
            cout << "직업을 선택하세요" << endl << "1. 전사 2. 마법사 3. 격투가 4. 뱀파이어" << endl;
            
            scanf_s(" %d", &input);
            system("cls");

            switch (input)
            {
            case WARRIOR:
                player = new Warrior(name);
                break;
            case MAGE:
                player = new Mage(name);
                break;
            case FIGHTER:
                player = new Fighter(name);
                break;
            case VAMPIRE:
                player = new Vampire(name);
                break;
            default:
                break;
            }
            break;
        case SHOW:
            player->ShowRecord();
            break;
        case CLOSE:
            break;
        default:
            break;
        }
        
        if (menu == CLOSE)
        {
            break;
        }

    }

    delete(player);
    cout << "게임을 종료합니다!" << endl;
    return 0;
}

