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
		printf("请输入 1 开始游戏 输入 0 退出游戏> \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");

		}
	} while (input);
	return 0;
}