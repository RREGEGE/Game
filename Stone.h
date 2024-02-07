#pragma once
#include "Yut.h"
class Stone:public Yut
{
public:
	int Move();
	void Together();
	void Eat();
public:
	int local = 0;
	int turn;
};

