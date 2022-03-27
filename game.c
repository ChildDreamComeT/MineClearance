#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	for (int i = 1; i <= rows - 2; i++){
		for (int j = 1; j < cols - 2; j++){
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col){
	printf("-------------扫雷游戏-------------\n");
	for (int i = 0; i <= col; i++){
		printf("%d", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++){
		printf("%d", i);
		for (int j = 1; j <= col; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------扫雷游戏-------------\n");
}

void SetMine(char mine[ROW][COL], int row, int col, int count){
	while (count){
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == "0"){
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y){
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (mine[i][j] == '1'){
				count++;
			}
		}
	}
	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	int win = 0;
	while (win < row*col - EASY_COUNT){
		int x;
		int y;
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col){
			if (mine[x][y] == '1'){
				printf("很遗憾，你被炸死了！！！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else{
			printf("坐标非法，请重新输入!!!\n");
		}
	}
	if (row*col - EASY_COUNT == win){
		printf("恭喜你，你赢了，扫雷成功!!!\n");
		printf("雷的布局为：\n");
		DisplayBoard(show, row, col);
	}
}
