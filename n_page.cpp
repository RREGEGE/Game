#include "n_page.h"
#include<iostream>
#include<Windows.h>
#include"setting.h"
#include<iomanip>

char board[11][11];//���� �迭 
int ctn = 48;//�ӽ� ��
int pre_x = 0;//���� ��ġ ����� ����
int pre_y = 0;
#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void set_board()//�� ���� 
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if ((i % 2 == 0) && (j % 2 == 0))//�ش�����
			{
				board[i][j] = '��';
			}
			if (i == 5 && j == 5)
			{
				board[i][j] = '��';
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

}
void print_board()//�� ��� �ϴ� �Ź� �ϴ���
{
	for (int i = 0; i < 11; i++)
	{
		gotoxy(40, 15 + i);
		for (int j = 0; j < 11; j++)
		{
			if (board[i][j] == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << board[i][j] << " " ;
			}
		}
		cout << "\n\n";
	}
}

void game_start()
{
	Stone s;
	system("cls");
	cout << "���ӽ���";
	set_board();
	print_board();
	move_piece(s);
	Sleep(30000);
	return;
}
void game_info()
{
	system("cls");
	cout << "���� ���� : ������ ����";
	Sleep(3000);
	return;
}
void game_exit()
{
	system("cls");
	cout << "���� ����";
	Sleep(3000);
	return;
}



void move_piece(Stone& s)
{
	int next = 0;
	while (1)
	{
		int value = 0;
		if (s._area == 6)//���Ƿ� ���� ����
		{
			cout << "���� ��¼��� ���!";
			break;
		}std::cout << "�������� : ";
		std::cin >> value;
		dice(value);
		next = value + s._number;//���� ��ġ�� �� ���� �� ���� ��(���Ե� ��)

		switch (s._area)
		{
		case 0://0 �ܰ�
		{
			if (next == 5)//���� ��ġ�� 0�ܰ� 5��°(�ڳ�)
			{
				//std::cout << "5�ܰ��";
				s._area = 5;
				s._number = 0;

				break;
			}
			else if (next > 5)//5 �ʰ��� 1�ܰ�
			{
				//std::cout << "1�ܰ��";
				s._area = 1;
				s._number = next - 5;

				break;
			}
			else // 5 �̸��� 0�ܰ� �ܷ�
			{
				//std::cout << "0�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 1:
		{
			if (next == 5)//���� ��ġ�� 1�ܰ� 5��°(�ڳ�)
			{
				//std::cout << "4�ܰ��";
				s._area = 4;
				s._number = 0;
				break;
			}
			else if (next > 5)//5 �ʰ��� 2�ܰ�
			{
				//std::cout << "2�ܰ��";
				s._area = 2;
				s._number = next - 5;
				break;
			}
			else // 5 �̸��� 0�ܰ� �ܷ�
			{
				//std::cout << "1�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 2:
		{
			if (next >= 5)//5 �ʰ��� 3�ܰ�
			{
				//std::cout << "3�ܰ��";
				s._area = 3;
				s._number = next - 5;
				break;
			}
			else // 5 �̸��� 2�ܰ� �ܷ�
			{
				//std::cout << "2�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 3:
		{
			if (next > 5)//5 �ʰ��� ����
			{
				//std::cout << "����";
				s._area = 6;
				break;
			}
			else // 5 ���Ͻ� 3�ܰ� �ܷ�
			{
				//std::cout << "3�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 4:
		{
			if (next > 6)//6 �ʰ��� ����
			{
				//std::cout << "����";
				s._area = 6;
				break;
			}
			else // 6 ���Ͻ� 4�ܰ� �ܷ�
			{
				//std::cout << "4�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 5:
		{
			if (next == 3)//3 ��ġ�� 4�ܰ�(�ڳ�)
			{
				//std::cout << "4�ܰ��";
				s._area = 4;
				s._number = 3;
				break;
			}
			else if (next >= 6)// 6 �̻�� 3�ܰ��
			{
				//std::cout << "3�ܰ��";
				s._area = 3;
				s._number = 0;
				break;
			}
			else
			{
				//std::cout << "5�ܰ��ܷ�";//3�ƴϰ� 6�̸��� 5�ܰ� �ܷ�
				s._number = next;
				break;
			}
		}
		default:
			break;
		}
		piece_location(s,board);//��ġ�� �������
	}
}

void piece_location(Stone& s,char arr[][11])
{
	if(ctn>48)	arr[pre_x][pre_y] = '��';//���� �� ����
	switch (s._area)
	{
	case 0://�� ���̽��� �°� x,y ����
	{
		int x = 10 - (2 * (s._number));
		int y = 10;
		arr[x][y] = ++ctn;
		pre_x = x;//���� �� ����ϱ� ����
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	case 1:
	{
		int x = 0;
		int y = 10 - (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 2:
	{
		int x = (2 * (s._number));
		int y = 0;
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 3:
	{
		int x = 10;
		int y = (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 4:
	{
		int x = (2 * (s._number));
		int y = (2 * (s._number));
		if (s._number > 3)
		{
			x = x - 2;
			y = y - 2;
		}
		else if (s._number == 3)
		{
			x = x - 1;
			y = y - 1;
		}
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 5:
	{
		int x = (2 * (s._number));
		int y = 10 - (2 * (s._number));
		if (s._number > 3)
		{
			x = x - 2;
			y = y + 2;
		}
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	default:
		break;
	}
	print_board();
	
}

void dice(int value)

{
	gotoxy(0, 15);
	switch (value)
	{
	case 1:
	{
		cout << "���� ���� ���� ����\n";
		cout << "���� �᡿�� �᡿�� �᡿��\n";
		cout << "���� �᡿�� �᡿�� �᡿��\n";
		cout << "���� �᡿�� �᡿�� �᡿��\n";
		cout << "���� ���� ���� ����\n";
		break;
	}
	case 2:
	{
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� �᡿�� �᡿��\n";
		cout << "���� ���� �᡿�� �᡿��\n";
		cout << "���� ���� �᡿�� �᡿��\n";
		cout << "���� ���� ���� ����\n";
		break;

	}
	case 3:
	{
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� ���� �᡿��\n";
		cout << "���� ���� ���� �᡿��\n";
		cout << "���� ���� ���� �᡿��\n";
		cout << "���� ���� ���� ����\n";
		break;

	}
	case 4:
	{
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� ���� ����\n";
		cout << "���� ���� ���� ����\n";
		break;

	}
	case 5: 
	{
		cout << "���� ���� ���� ����\n";
		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
		cout << "���� ���� ���� ����\n";
		break;

	}
	default:
		break;
	}
	

}