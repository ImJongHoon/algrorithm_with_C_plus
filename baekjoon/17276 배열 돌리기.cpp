#include <iostream>
#include <vector>

using namespace std;

//반시계-하우상좌
int dy1[] = {1, 0, -1, 0};
int dx1[] = {0, 1, 0, -1};
//시계-우하좌상
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

int main() {
	int testcase;
	int start_interval;//시작간격
	int rotate_num = 0;
	int interval;
	int ny, nx;
	int temp1, temp2;
	vector<vector<vector<int>>> board;//pushback으로 입력하기

	cin >> testcase;

	vector<int> size(testcase);
	vector<int> rotation_deg(testcase);

	//모든 input 받기
	for (int i = 0; i < testcase; i++) {
		cin >> size[i];
		cin >> rotation_deg[i];

		board.push_back(vector<vector<int>>(size[i], vector<int>(size[i], 0)));
		for (int y = 0; y < size[i]; y++) {
			for (int x = 0; x < size[i]; x++) {
				cin >> board[i][y][x];
			}
		}
	}

	//돌림연산
	for (int i = 0; i < testcase; i++) {//테스트케이스 한번당
		start_interval = (size[i] - 1) / 2;
		if (rotation_deg[i] < 0) {//반시계
			rotate_num = -(rotation_deg[i] / 45);//몇번 돌아가는가
		}
		else if (rotation_deg[i] >= 0) {//시계
			rotate_num = rotation_deg[i] / 45;
		}
		for (int j = 0; j < rotate_num; j++) {//회전 총 반복수
			interval = (size[i]-1) / 2;
			for (int k = 0; k < size[i] / 2; k++) {//깊이. 깊을수록 간격 좁아짐
				//시작 좌표가 board[k][k]
				ny = k;
				nx = k;
				temp1 = board[i][ny][nx];
				if (rotation_deg[i] < 0) {//반시계
					for (int l = 0; l < 4; l++) {
						for (int m = 0; m < 2; m++) {
							ny = ny + (dy1[l]) * interval;
							nx = nx + (dx1[l]) * interval;

							temp2 = board[i][ny][nx];
							board[i][ny][nx] = temp1;
							temp1 = temp2;
						}
					}
				}
				else if (rotation_deg[i] >= 0) {//시계
					for (int l = 0; l < 4; l++) {
						for (int m = 0; m < 2; m++) {
							ny = ny + (dy2[l]) * interval;
							nx = nx + (dx2[l]) * interval;

							temp2 = board[i][ny][nx];
							board[i][ny][nx] = temp1;
							temp1 = temp2;
						}
					}
				}
				interval--;
			}
		}
	}

	//for 출력
	for (int i = 0; i < testcase; i++) {
		for (int y = 0; y < size[i]; y++) {
			for (int x = 0; x < size[i]; x++) {
				cout << board[i][y][x]<< " ";
			}
			cout << endl;
		}
	}

	return 0;
}