#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu() {
	printf("********************\n");
	printf("***    1.start     ***\n");
	printf("***    0.quit      ***\n");
	printf("********************\n");
}

void game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };

	//��ʼ�����̵ĺ���
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisaplayBoard(board, ROW, COL);
	//����
	while (1) {
		PlayerMove(board, ROW, COL);
		DisaplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c') {
			break;
		}
		ComputerMove(board, ROW, COL);
		DisaplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c') {
			break;
		}
	}
	if (ret == '*') {
		printf("���Ӯ\n");
	}
	else if (ret == '#') {
		printf("����Ӯ\n");
	}
	else {
		printf("ƽ��\n");

	}
	


	
}

int main() {
	srand((unsigned int)time(NULL));

	int input = 0;
	do {
		menu();	//��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}