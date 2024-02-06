#pragma once
#include "Yut.h"
class Stone:public Yut
{
public:
	int Move();
	int Together();
	int Eat();
public:
	int local = 0;
	int turn;
};

