#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DisaplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	while (1) {
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用，请重新输入\n");
			}
		}
		else {
			printf("坐标非法，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("电脑下棋:>\n");

	int x = 0;
	int y = 0;

	while (1) {
		x = rand() % row;	//0~2
		y = rand() % col;	//0~2

		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}

}

int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	
	}
	
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
	//三点一线
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ') {
				return board[i][j];
			}
			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ') {
				return board[i][j];
			}
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ') {
				return board[i][j];
			}
		}
	}

	//平局
	if (IsFull(board, row, col)) {
		return 'q';
	}

	//游戏继续
	return 'c';

}