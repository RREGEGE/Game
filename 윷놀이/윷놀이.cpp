#include <iostream>
#include "Yut.h"
#include "Player.h"
#include "Stone.h"

using namespace std;;

int turn = 0;

void Run(Player* player) {
	Yut a;
	int stone_num;
	cout << player->_name << "님 턴입니다." << endl;
	a.Throw();
	a.Result();
	if (a.Result() == 5 || a.Result() == 4) {
		while (a.Result() == 5 || a.Result() == 4) {
			cout << "한번 더 던집니다.";
			a.Throw();
			a.Result();
			cout << "움직일 말을 고르세요.(1,2,3 중에) :";
			cin >> stone_num;
			player->life[stone_num]->Move(&a);
		}
	}
	else {
		cout << "움직일 말을 고르세요.(1,2,3 중에) :";
		cin >> stone_num;
		player->life[stone_num]->Move(&a);
	}
	cout << player->life[stone_num]->location << endl;
	turn++;
}

int main()
{
	
	Yut a;
	Player A;
	Player B;
	Stone blue;
	Stone red;
	for (int i = 0; i < 3; i++) {
		A.Make_stone(&blue);
		B.Make_stone(&red);
	}
	while (true) {
		int num;
		cout << "번호 입력: ";
		cin >> num;
		if (num == 0) {
			break;
		}
		if (num == 1) {
			if (turn %2== 0) {
				Run(&A);
			}
			else {
				Run(&B);
			}
		}
			
	}
	return 0;
}
	

