#pragma once
#include <vector>
#include <iostream>
#include "Stone.h"

using namespace std;

class Player
{
public:
	void Make_stone();
	void Throw_yut(Yut&);
public:
	vector<Stone*> life[3]{};
	Yut one;
};

