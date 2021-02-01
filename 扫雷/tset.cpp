#include"game.h"

void menu()
{
	printf("*************** ******\n");
	printf("*****1. p l a y*** ***\n");
	printf("*****0. e x i t*******\n");
	printf("****************** ***\n");

}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	PrintBoard(show,ROW,COL);
	//埋炸弹
	SetBoomb(mine, ROW, COL, EASY);
	//找炸弹
	FindBoomb(mine,show, ROW, COL);
	//PrintBoard(mine, ROW, COL);
	//判断是否引爆
	//是否可以走到底，赢游戏
}

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出!\n");
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}

	} while (input);
	return 0;
}