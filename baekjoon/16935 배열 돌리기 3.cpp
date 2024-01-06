#include <iostream>
#include <vector>

using namespace std;

void flipTop(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			board[y][x] = copy[height-y-1][x];
		}
	}
}
void flipLeft(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			board[y][x] = copy[y][width-x-1];
		}
	}
}
void turnRight(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	vector<vector<int>>new_board(width, vector<int>(height));
	//좌하단부터 우상으로 올라오면서 읽으면 그게 우측으로 90도
	int index_x;
	int index_y=0;
	for (int x = 0; x < width; x++) {
		index_x = 0;
		for (int y = height - 1; y >= 0; y--) {
			new_board[index_y][index_x] = copy[y][x];
			index_x++;
		}
		index_y++;
	}
	//교체
	board = new_board;
}
void turnLeft(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	vector<vector<int>>new_board(width, vector<int>(height));
	//우상에서 좌하로 이동하면서 읽으면 그게 좌측으로 90도
	int index_x;
	int index_y = 0;
	for (int x = width-1; x >= 0; x--) {
		index_x = 0;
		for (int y = 0; y < height; y++) {
			new_board[index_y][index_x] = copy[y][x];
			index_x++;
		}
		index_y++;
	}
	//교체
	board = new_board;
}
void changeRight(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	//1영역 = 4영역 y값 - height/2
	//2영역 = 1영역 x값 + width/2
	//3영역 = 2영역 y값 + height/2
	//4영역 = 3영역 x값 - width/2
	//코딩할때는 반대로 짜여짐
	int halfWidth = width / 2;
	int halfheight = height / 2;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (y < halfheight && x < halfWidth) {//1영역이면
				board[y][x] = copy[y + halfheight][x];
			}
			else if (y < halfheight && x >= halfWidth) {//2영역이면
				board[y][x] = copy[y][x - halfWidth];
			}
			else if (y >= halfheight && x >= halfWidth) {//3영역이면
				board[y][x] = copy[y - halfheight][x];
			}
			else if (y >= halfheight && x < halfWidth) {//4영역이면
				board[y][x] = copy[y][x + halfWidth];
			}
		}
	}
}
void changeLeft(vector<vector<int>>& board, vector<vector<int>>copy, int height, int width) {
	//1영역 = 2영역 x값 - width/2
	//2영역 = 3영역 y값 - height/2
	//3영역 = 4영역 x값 + width/2
	//4영역 = 1영역 y값 + height/2
	int halfWidth = width / 2;
	int halfheight = height / 2;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (y < halfheight && x < halfWidth) {//1영역이면
				board[y][x] = copy[y][x + halfWidth];
			}
			else if (y < halfheight && x >= halfWidth) {//2영역이면
				board[y][x] = copy[y + halfheight][x];
			}
			else if (y >= halfheight && x >= halfWidth) {//3영역이면
				board[y][x] = copy[y][x - halfWidth];
			}
			else if (y >= halfheight && x < halfWidth) {//4영역이면
				board[y][x] = copy[y - halfheight][x];
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int height;
	int width;
	int num;

	cin >> height;
	cin >> width;
	cin >> num;

	vector<vector<int>>board(height, vector<int>(width, 0));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> board[y][x];
		}
	}

	vector<int> command(num, 0);
	for (int i = 0; i < num; i++) {
		cin >> command[i];
	}

	for (int i = 0; i < num; i++) {
		if (command[i] == 1) {
			flipTop(board, board, height, width);
		}
		else if (command[i] == 2) {
			flipLeft(board, board, height, width);
		}
		else if (command[i] == 3) {
			turnRight(board, board, height, width);
		}
		else if (command[i] == 4) {
			turnLeft(board, board, height, width);
		}
		else if (command[i] == 5) {
			changeRight(board, board, height, width);
		}
		else if (command[i] == 6) {
			changeLeft(board, board, height, width);
		}

		//가로 세로 갱신
		height = board.size();
		width = board[0].size();
	}

	//출력
	//cout << "board.size(): " << board.size()<<endl;
	//cout << "board[y].size(): " << board[0].size()<<endl;

	for (int y = 0; y < board.size(); y++) {
		for (int x = 0; x < board[y].size(); x++) {
			cout << board[y][x]<< " ";
		}
		cout << endl;
	}

	return 0;
}