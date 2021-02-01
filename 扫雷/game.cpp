#include"game.h"
//��ʼ������
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

//��ӡ����
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

//����ը��
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
//ͳ��XY������Χ�м���ը��
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

//��ը��
void FindBoomb(char arr1[ROWS][COLS],char arr2[ROWS][COLS], int rows, int cols)
{
	int win = 0;
	while (win<rows*cols-EASY)
	{
		printf("��������Ҫ����������λ��:>");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= rows&& y >= 1 && y <= cols)
		{
			if (arr1[x][y] == '1')
			{
				printf("ԭ�ر�ը!\n");
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
			printf("����Ƿ�!\n");
		}
	}
	if (win == rows*cols - EASY)
	{
		printf("��Ӯ��!");
	}
	
}
