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

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	PrintBoard(show,ROW,COL);
	//��ը��
	SetBoomb(mine, ROW, COL, EASY);
	//��ը��
	FindBoomb(mine,show, ROW, COL);
	//PrintBoard(mine, ROW, COL);
	//�ж��Ƿ�����
	//�Ƿ�����ߵ��ף�Ӯ��Ϸ
}

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("���˳�!\n");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}

	} while (input);
	return 0;
}