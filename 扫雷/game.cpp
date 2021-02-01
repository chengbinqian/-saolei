#include"game.h"
//初始化棋盘
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char stick)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = stick;
		}
	}
		
}

//打印棋盘
void PrintBoard(char arr[ROWS][COLS], int rows, int cols)
{
	printf("--------------------------------------------------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i <= cols; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= rows; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= cols; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------------------\n");
}

//布置炸弹
void SetBoomb(char arr[ROWS][COLS], int rows, int cols, int count)
{
	while (count)
	{
		int x = rand() % rows + 1;
		int y = rand() % cols + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
//统计XY坐标周围有几个炸弹
int calculate(char arr[ROWS][COLS], int x, int y)
{
	return arr[x - 1][y - 1] +
		arr[x - 1][y] +
		arr[x - 1][y + 1] +
		arr[x][y - 1] +
		arr[x][y + 1] +
		arr[x + 1][y - 1] +
		arr[x + 1][y] +
		arr[x + 1][y + 1] - 8 * '0';

		
}

//找炸弹
void FindBoomb(char arr1[ROWS][COLS],char arr2[ROWS][COLS], int rows, int cols)
{
	int win = 0;
	while (win<rows*cols-EASY)
	{
		printf("请输入你要翻开的坐标位置:>");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= rows&& y >= 1 && y <= cols)
		{
			if (arr1[x][y] == '1')
			{
				printf("原地爆炸!\n");
				PrintBoard(arr1, ROW, COL);
				break;
			}
			else
			{
				int t = calculate(arr1, x, y);
				arr2[x][y] = t + '0';
				PrintBoard(arr2, rows, cols);
				win++;
			}
		}
		else
		{
			printf("坐标非法!\n");
		}
	}
	if (win == rows*cols - EASY)
	{
		printf("你赢了!");
	}
	
}
