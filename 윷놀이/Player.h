#pragma once
#include <vector>
#include <iostream>
#include "Stone.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void Make_stone(Stone* stone);
	void Together();
	void Eat(Player* opponent);
public:
	vector<Stone*> life;
	string _name;
	
};

