#include "Yut.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;;

void Yut::Throw() {
	sum = 0;
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		num = rand() % 2;
		if (num == 0) {
			/*cout << "|  |" << endl;
			cout << "|��|" << endl;
			cout << "|  |" << endl;*/
			cout << "��" << " ";
			sum++;
		}
		else {
			cout << "��" << " ";
		}
	}
}

int Yut::Result() {
	if (sum == 0) {
		cout << "��";
		return 5;
	}
	else if (sum == 1) {
		cout << "��";
		return 1;
	}
	else if (sum == 2) {
		cout << "��";
		return 2;
	}
	else if (sum == 3) {
		cout << "��";
		return 3;
	}
	else {
		cout << "��";
		return 4;
	}
}