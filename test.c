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

	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisaplayBoard(board, ROW, COL);
	//下棋
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
		printf("玩家赢\n");
	}
	else if (ret == '#') {
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");

	}
	


	
}

int main() {
	srand((unsigned int)time(NULL));

	int input = 0;
	do {
		menu();	//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}