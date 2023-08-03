#include <iostream>
#include <vector>

using namespace std;

struct Map {
	int num;
	int check=0;
};

struct info {
	int y;
	int x;
};

//보드 탐색해서 체크까지 해줌. 좌표 반환
void search_board(vector<vector<Map>>& board, int call_num) {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (board[y][x].num == call_num) {
				board[y][x].check = 1;
			}
		}
	}
}

//좌표 받고 해당 좌표에 따른 빙고 카운트?? 아니지. 전부 카운팅해야 의미가 있지.
int check_bingo(vector<vector<Map>>& board) {
	int count = 0;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (board[y][x].check == 0) {
				break;
			}
			if (x == 4) {
				count++;
			}
		}
	}
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (board[y][x].check == 0) {
				break;
			}
			if (y == 4) {
				count++;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (board[i][i].check == 0) {
			break;
		}
		if (i == 4) {
			count++;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (board[i][4 - i].check == 0) {
			break;
		}
		if (i == 4) {
			count++;
		}
	}

	if (count >= 3) {
		return 1;
	}

	return 0;
}


int main() {
	vector<vector<Map>> board(5, vector<Map>(5));
	int call_num[25];
	int is_bingo = 0;
	int count = 0;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> board[y][x].num;
		}
	}

	for (int i = 0; i < 25; i++) {
		cin >> call_num[i];
	}

	for (int i = 0; i < 25; i++) {
		search_board(board, call_num[i]);
		is_bingo = check_bingo(board);

		count++;
		/*
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				cout << board[y][x].check << " ";
			}
			cout << "\n";
		}
		*/

		if (is_bingo == 1) {
			break;
		}
	}
	
	cout << count;

	return 0;
}