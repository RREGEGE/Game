#include "Player.h"
Player::Player() {
	string name;
	cout << "�̸��� �Է����ּ���.";
	cin >> name;
	_name = name;
}
Player::~Player() {}

void Player::Make_stone(Stone* stone) {
	life.push_back(stone);
}

void Player::Together() {
	for (int i = 0; i < life.size(); i++) {
		for (int j = i + 1; j < life.size(); j++) {
			if (life[i]->location != 0 && life[j]->location != 0 && life[i]->location == life[j]->location) {
				cout << "����!" << endl;

				life[i]->SetTogether(true);
				life[j]->SetTogether(true);

			}
		}
	}
}
void Player::Eat(Player* opponent) {
	for (int i = 0; i < life.size(); i++) {
		for (int j = 0; j < opponent->life.size(); j++) {
			if (opponent->life[j]->location != 0 && life[i]->location == opponent->life[j]->location) {
				cout << "���" << endl;
				// ������ ���� ��ĥ ���
				opponent->life[j]->location = 0; // ������ ���� ��ġ�� 0���� ����ϴ�.
			}
		}
	}
}

