//시작 14:46
// 시도1 15:48
//재시도 16:49
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void turn(vector<vector<int>>& board, vector<vector<int>>copy,
	int start_x, int end_x, int start_y, int end_y, int repeatNum) {
	//repaetNum은 한바퀴를 초과하지 않음.
	vector<int> temp;
	for (int y = start_y; y < end_y; y++) {
		temp.push_back(board[y][start_x]);
	}
	for (int x = start_x; x < end_x; x++) {
		temp.push_back(board[end_y][x]);
	}
	for (int y = end_y; y > start_y; y--) {
		temp.push_back(board[y][end_x]);
	}
	for (int x = end_x; x > start_x; x--) {
		temp.push_back(board[start_y][x]);
	}
	vector<int> temp2(temp.size());
	for (int i = 0; i < temp.size(); i++) {
		temp2[(i + repeatNum) % temp.size()] = temp[i];
	}

	//다시 집어넣기
	int count = 0;
	for (int y = start_y; y < end_y; y++) {
		board[y][start_x] = temp2[count++];
	}
	for (int x = start_x; x < end_x; x++) {
		board[end_y][x] = temp2[count++];
	}
	for (int y = end_y; y > start_y; y--) {
		board[y][end_x] = temp2[count++];
	}
	for (int x = end_x; x > start_x; x--) {
		board[start_y][x] = temp2[count++];
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int width;
	int height;
	int num;
	cin >> height;
	cin >> width;
	cin >> num;

	vector<vector<int>> board(height, vector<int>(width));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> board[y][x];
		}
	}
	
	//안으로 들어갈수록 회전 횟수가 8씩 줄어든다
	// 12 4
	// 14 6
	// 22 14 6
	int repaetNum;
	int turnNum = 2 * (width + height) - 4;
	for (int j = 0; j < min(width, height) / 2; j++) {
		repaetNum = num % (turnNum - (j * 8));
		turn(board, board, j, width - j - 1, j, height - j - 1, repaetNum);
		
		//cout << i << "번째에 " << j << "까지 내려가서 돌리기" << '\n';
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << board[y][x] << " ";
		}
		cout << '\n';
	}
	return 0;
}