#pragma once
using namespace std;;
void set_board();
void print_board();
void game_start();
void game_info();
void game_exit();
void dice(int);
class Stone
{
public:
	Stone() :_area(0), _number(0)
	{

	}
	~Stone() {}
public:
	int _area;
	int _number;
};

void move_piece(Stone&);

void piece_location(Stone&,char arr[][11]);
