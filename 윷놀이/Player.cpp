#include "Player.h"
Player::Player() {
	string name;
	cout << "이름을 입력해주세요.";
	cin >> name;
	_name = name;
}
Player::~Player() {}

void Player::Make_stone(Stone* stone) {
	life.push_back(stone);
	isTogether.push_back(false);
}

//void Player::Together() {
//	for (int i = 0; i < life.size(); i++) {
//		for (int j = i + 1; j < life.size(); j++) {
//			if (life[i]->location != 0 && life[j]->location != 0 && life[i]->location == life[j]->location) {
//				cout << "업기!" << endl;
//
//				life[i]->SetTogether(true);
//				life[j]->SetTogether(true);
//
//			}
//		}
//	}
//}
void Player::Together() {
	for (int i = 0; i < life.size(); i++) {
		if (isTogether[i]) {
			continue; // 이미 업기 상태인 돌은 비교하지 않음
		}
		for (int j = i + 1; j < life.size(); j++) {
			if (life[i]->location != 0 && life[j]->location != 0 && life[i]->location == life[j]->location) {
				cout << "업기!" << endl;

				isTogether[i] = true; // 업기 상태로 변경
				isTogether[j] = true; // 업기 상태로 변경
			}
			/*else {
				isTogether[i] = false; 
				isTogether[j] = false;
			}*/
		}
	}
	for (bool i : isTogether) {
		cout << i << " ";
	}
	cout << endl;
}
void Player::Location_share(int num) {
	for (int i = 0; i < life.size(); i++) {
			if (isTogether[i] == true && isTogether[num] == true) {
				life[i]->location == life[num]->location;
		}
	}
}

int Player::Eat(Player* opponent) {
	check = 0;
	for (int i = 0; i < life.size(); i++) {
		for (int j = 0; j < opponent->life.size(); j++) {
			if (opponent->life[j]->location != 0 && life[i]->location == opponent->life[j]->location) {
				cout << "잡기!" << endl;
				// 상대방의 돌과 겹칠 경우
				opponent->life[j]->location = 0; // 상대방의 돌의 위치를 0으로 만듭니다.
				check = 1;
				return 1;
			}
		}
	}
	return 0; // 겹치는 돌이 없는 경우 0을 반환
}

