#include "Stone.h"
#include <iostream>

using namespace std;;

Stone::Stone() : location(0), isTogether(false) {}

Stone::~Stone() {}

int Stone::Move(Yut* yut) {
	location += yut -> result;
	return location;
}

void Stone::SetTogether(bool together) {
	isTogether = together;
}
