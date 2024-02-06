#pragma once
#include"setting.h"
#include<windows.h>


int main()
{
	set_console();
	while (1)
	{
		title_draw();
		int temp = menu_draw();
		switch (temp)
		{
		case 1:
			game_start();
			break;
		case 2:
			game_info();
			break;
		case 0:
			game_exit();
			break;
		default:
			break;
		}
		system("cls");

	}

	return 0;

}