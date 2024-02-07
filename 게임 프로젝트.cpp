#pragma once
#include"setting.h"
#include"n_page.h"
#include<windows.h>
#include <iostream>
#include "Yut.h"
using namespace std;;

int main()
{
	set_console();//콘솔 창 세팅
	while (1)
	{
		title_draw();//윷놀이 크게 띄우기 위함
		int temp = menu_draw();//1.2.3 선택지
		switch (temp)
		{
		case 1:
			game_start();//게임 시작
			break;
		case 2:
			game_info();//게임 정보
			break;
		case 0:
			game_exit();//게임 종료
			break;
		default:
			break;
		}
		system("cls");
		if (temp == 0) break;
	}

	return 0;
}