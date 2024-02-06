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
			cout << "|앞|" << endl;
			cout << "|  |" << endl;*/
			cout << "앞" << " ";
			sum++;
		}
		else {
			cout << "뒤" << " ";
		}
	}
}

int Yut::Result() {
	if (sum == 0) {
		cout << "모";
		return 5;
	}
	else if (sum == 1) {
		cout << "도";
		return 1;
	}
	else if (sum == 2) {
		cout << "개";
		return 2;
	}
	else if (sum == 3) {
		cout << "걸";
		return 3;
	}
	else {
		cout << "윷";
		return 4;
	}
}