#pragma once
#include <vector>
#include <iostream>
#include "Stone.h"

using namespace std;

class Player
{
public:
<<<<<<< HEAD:심상범/Player.h
	Player();
	~Player();
	void Make_stone(Stone* stone);
	void Together();
	void Eat(Player* opponent);
public:
	vector<Stone*> life;
	string _name;
=======
	void Make_stone();
	void Throw_yut(Yut&);
public:
	vector<Stone*> life[3]{};
	Yut one;
>>>>>>> 8e04d834136383092cbde8c1b8b63eaa1c419aa8:Player.h
};

