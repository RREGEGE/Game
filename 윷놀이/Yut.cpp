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
		cout << "��" << endl;	
	}
	else if (sum == 1) {
		cout << "��" << endl;	
	}
	else if (sum == 2) {
		cout << "��" << endl;
	}
	else if (sum == 3) {
		cout << "��" << endl;	
	}
	else {
		cout << "��" << endl;
	}
}