#include "Framework.h"



int main()
{
	srand(time(NULL));
	
	GameScene* scene = new GameScene;

	scene->ChooseCharacter();

	


	while (true)
	{
		cout << "메뉴를 입력하세요" << endl;

		int input;

		cin >> input;
		switch (input)
		{
			case 1:
				scene->StartBattle();
				break;
			case 2:
				cout << "게임을 종료합니다!" << endl;
				delete scene;
				return 0;
			default:
				break;
		}
	}
	
	

	
	


	
	
	
	
	return 0;
}


