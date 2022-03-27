#include "game.h"

void menu(){
	printf("***************************\n");
	printf("*******  1.PLAY  ********\n");
	printf("*******  2.EXIT  ********\n");
	printf("***************************\n");
}

void game(){
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	DisplayBoard(show, ROW, COL);
	
	SetMine(mine, ROW, COL, EASY_COUNT);

	FindMine(mine, show, ROW, COL);
}

int main(){
	int input;
	srand((unsigned int)time(NULL));
	do
	{

		menu();
		printf("������ 1 ��ʼ��Ϸ ���� 0 �˳���Ϸ> \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");

		}
	} while (input);
	return 0;
}