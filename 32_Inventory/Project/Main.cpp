#include "Framework.h"

int main()
{
	GameManager gm;

	while (true)
	{
		int input;

		cout << "메뉴를 선택하세요! 1. 상점방문 2. 플레이어 관리 3. 게임종료" << endl;

		cin >> input;

		switch (input)
		{
		case 1:
			gm.ManageStore();
			break;
		case 2:
			gm.ManagePlayer();
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}


	


	//rfor로 intellisense 호출

	/*auto a = 0;
	auto b = 0.0;
	auto c = 0.0f;
	auto d = 0l;
	auto e = new Player();

	for (auto& i : {0,1,2,23})
	{
		cout << i << endl;
	}*/




	return 0;
}