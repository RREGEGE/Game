#include <iostream>
#include "Yut.h"
#include "Player.h"
#include "Stone.h"

using namespace std;;

int turn = 0;

void Run(Player* player, Player* opponent) {
	Yut a;
	int stone_num;
	int count = 0;
	int j = 0;
	cout << player->_name << "님 턴입니다." << endl;
	a.Throw();
	a.Speak();
	a.Result();
	cout << "움직일 말을 고르세요.(0,1,2 중에) :";
	cin >> stone_num;
	while(stone_num > 2){
		cout << "잘못 입력하셨습니다. 다시 입력하세요: ";
		cin >> stone_num;
	}
	player->life[stone_num]->Move(&a);
	player->Location_share(stone_num);
	player->Together();
	player->Eat(opponent);
	for (Stone* i : player->life) {
		cout << j << "번째 돌의 위치: " << i->location << endl;
		j++;
	}
	if (a.Result() == 5 || a.Result() == 4 || player->check == 1) {
		if (a.Result() == 5 && player->Eat(opponent) || a.Result() == 5 && player->Eat(opponent)) {
			count += 2;
		}
		else {
			count++;
		}
	}
	while (count != 0) {
		int j = 0;
		cout << "한번 더 던집니다.";
		a.Throw();
		a.Speak();
		a.Result();
		cout << "움직일 말을 고르세요.(0,1,2 중에) :";
		cin >> stone_num;
		player->life[stone_num]->Move(&a);
		player->Location_share(stone_num);
		player->Together();
		player->Eat(opponent);
		for (Stone* i : player->life) {
			cout << j << "번째 돌의 위치: " << i->location << endl;
			j++;
		}
		
		if (a.Result() == 5 || a.Result() == 4 || player->check == 1) {
			if (a.Result() == 5 && player->Eat(opponent) || a.Result() == 5 && player->Eat(opponent)) {
				count += 2;
			}
			else {
				count++;
			}
		}
		count--;
	}
	turn++;
}

int main()
{

	Player A;
	Player B;
	Stone blue;
	Stone blue_1;
	Stone blue_2;
	Stone red;
	Stone red_1;
	Stone red_2;

	A.Make_stone(&blue);
	B.Make_stone(&red);
	A.Make_stone(&blue_1);
	B.Make_stone(&red_1);
	A.Make_stone(&blue_2);
	B.Make_stone(&red_2);

	while (true) {
		int num;	
		Run(&A, &B);
			
		

	}
	return 0;
}


