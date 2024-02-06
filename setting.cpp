#pragma once
#include"setting.h"
#include<iostream>
#include<cstdlib>
#include<windows.h>
#include <conio.h>
#include"setting.h"

int board[11][11];

void draw_board()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if ((i % 2 == 0) && (j % 2 == 0))//해당조건
			{
				board[i][j] = 1;
			}
			if (i == 5 && j == 5)
			{
				board[i][j] = 1;
			}
		}
		cout << endl;
	}
	board[2][4] = 0;
	board[2][6] = 0;
	board[4][2] = 0;
	board[6][2] = 0;
	board[8][4] = 0;
	board[8][6] = 0;
	board[4][8] = 0;
	board[6][8] = 0;

	for (int i = 0; i < 11; i++)
	{
		gotoxy(30, 15 + i);
		for (int j = 0; j < 11; j++)
		{
			if (board[i][j] != 0)
			{
				cout << board[i][j] << "  ";
			}
			else cout << "   ";
		}
		cout << "\n\n";
	}

}

//콘솔 창의 크기와 제목을 지정하는 함수
void set_console() {
	system("title 윷놀이 게임"); // 콘솔창 이름 설정
	system("mode con:cols=74 lines=30"); // 콘솔창 크기설정;

}
//제목 그리기
void title_draw()
{
	cout << "\n";
	cout << "□□□■■■■■■■□□□□□■□□□□□□□□□□□□□□□□□□□■□\n";
	cout << "□□■■□□□□□■■□□□□■□□□□□□□□□□□■■■■□□□□■□\n";
	cout << "□□■■□□□□□■■□□□□■□□□□□□□□□□■■□□■■□□□■□\n";
	cout << "□□□■■■■■■■□□□□□■■■■■■■■■□□■□□□□■□□□■□\n";
	cout << "□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□■□□□■□\n";
	cout << "■■■■■■■■■■■■■□■■■■■■■■■■■□■□□□□■□□□■□\n";
	cout << "□□□■■□□□■■□□□□□□□□□□□□□□□□■□□□□■□□□■□\n";
	cout << "□□□□■□■□■□□□□□□■■■■■■■■□□□■■□□■■□□□■□\n";
	cout << "□□■■■■■■■■■□□□□□□□□□□□■□□□□■■■■□□□□■□\n";
	cout << "□□□□□■■■□□□□□□□■■■■■■■■□□□□□□□□□□□□■□\n";
	cout << "□□□□■■□■■□□□□□□■□□□□□□□□□□□□□□□□□□□■□\n";
	cout << "□□■■■□□□■■■□□□□■■■■■■■■■□□□□□□□□□□□■□\n";

}



void dice()
{
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□\n";
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□\n";
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□\n";
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□\n";

}
//커서 이동
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur{};
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(consoleHandle, Cur);
}

//메뉴 그리기 1.게임시작 2.게임정보 3.게임종료
int menu_draw()
{
	int x = (74 / 2) - 7;
	int y = (30 / 2) + 2;
	int temp;
	gotoxy(x - 2, y);
	cout << "> 1. 게임 시작";
	gotoxy(x, y + 1);
	cout << "2. 게임 정보";
	gotoxy(x, y + 2);
	cout << "0. 게임 종료  \n";
	cin >> temp;
	return temp;
}

void game_start()
{
	system("cls");
	cout << "게임시작";
	draw_board();
	Sleep(30000);
	return;
}
void game_info()
{
	system("cls");
	cout << "게임 정보";
	Sleep(3000);
	return;
}
void game_exit()
{
	system("cls");
	cout << "게임 종료";
	Sleep(3000);
	return;
}

void set_color(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

