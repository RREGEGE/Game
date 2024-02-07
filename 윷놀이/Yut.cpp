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
	cout << endl;
}

int Yut::Result() {
	if (sum == 0) {
		result = 5;
		return result;
	}
	else if (sum == 1) {
		result = 1;
		return result;
	}
	else if (sum == 2) {
		result = 2;
		return result;
	}
	else if (sum == 3) {
		result = 3;
		return result;
	}
	else {
		result = 4;
		return result;
	}
	return 0;
}

void Yut::Speak() {
	if (sum == 0) {
		cout << "모" << endl;	
	}
	else if (sum == 1) {
		cout << "도" << endl;	
	}
	else if (sum == 2) {
		cout << "개" << endl;
	}
	else if (sum == 3) {
		cout << "걸" << endl;	
	}
	else {
		cout << "윷" << endl;
	}
}