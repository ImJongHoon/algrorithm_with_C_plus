#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

//감소함
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

//해당 좌표 찾는 함수
int find(int y, int x, int length, int start_value) {
	int ny = length/2;
	int nx = length/2;

	if (y == 0 && x == 0) {
		return 1;
	}

	//board[y][x] 좌표 값을 결국 구하는 거다
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < length - 1; j++) {
			if (y == ny && x == nx) {
				return start_value;
			}
			ny = ny + dy[i];
			nx = nx + dx[i];
			start_value = start_value - 1;
		}
	}
	return 0;
}

int main() {
	int y1, x1, y2, x2;
	cin >> y1;
	cin >> x1;
	cin >> y2;
	cin >> x2;

	//y가 음수의 영역이면 줄어들고 양수의 영역이면 늘어난다
	//양수, 양수로 만들고 좌표 읽기
	//0이면 1의 제곱 1이면 3^2, 2이면 5^2, 3이면 7^2

	/*
	if (abs(y1) >= abs(x1)) {
		value1 = find(y1, x1, abs(y1) * 2 + 1, pow(abs(y1)*2 + 1, 2));
	}
	else if (abs(y1) < abs(x1)) {
		value1 = find(y1, x1, abs(x1) * 2 + 1, pow(abs(x1) * 2 + 1, 2));
	}

	if (abs(y2) >= abs(x2)) {
		value2 = find(y2, x2, abs(y2) * 2 + 1, pow(abs(y2) * 2 + 1, 2));
	}
	else if (abs(y2) < abs(x2)) {
		value2 = find(y2, x2, abs(x2) * 2 + 1, pow(abs(x2) * 2 + 1, 2));
	}
	*/
	vector<vector<int>> board(y2 - y1 + 1, vector<int>(x2 - x1 + 1));
	int y0 = 0;
	int x0 = 0;
	for (int y = y1; y <= y2; y++) {
		x0 = 0;
		for (int x = x1; x <= x2; x++) {
			if (abs(y) >= abs(x)) {
				board[y0][x0] = find(y, x, abs(y) * 2 + 1, pow(abs(y) * 2 + 1, 2));
			}
			else if (abs(y) < abs(x)) {
				board[y0][x0] = find(y, x, abs(x) * 2 + 1, pow(abs(x) * 2 + 1, 2));
			}
			x0++;
		}
		y0++;
	}

	int maxValue = 0;
	maxValue = max(maxValue, board[0][0]);
	maxValue = max(maxValue, board[y2 - y1][0]);
	maxValue = max(maxValue, board[0][x2 - x1]);
	maxValue = max(maxValue, board[y2 - y1][x2 - x1]);

	//자릿수 측정
	int count = 0;
	while (maxValue != 0) {
		maxValue = maxValue / 10;
		count++;
	}

	//출력
	int digit;
	int temp;
	for (int y = 0; y < y2 - y1 + 1; y++) {
		for (int x = 0; x < x2 - x1 + 1; x++) {
			digit = 0;
			temp = board[y][x];
			while (temp != 0) {
				temp = temp / 10;
				digit++;
			}
			for (int i = 0; i < count - digit; i++) {
				cout << " ";
			}
			cout << board[y][x] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}