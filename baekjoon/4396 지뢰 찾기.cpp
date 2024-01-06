#include <iostream>
#include <vector>

using namespace std;

//상하좌우대각선이며 out of range 검사 잊이
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int num;
	int gameover = 0;
	int ny;
	int nx;
	int count;

	cin >> num;

	vector<vector<char>> mine(num, vector<char>(num, '.'));
	vector<vector<char>> input(num, vector<char>(num, '.'));
	vector<vector<char>> result(num, vector<char>(num, '.'));//출력할 정답판


	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			cin >> mine[y][x];
		}
	}
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			cin >> input[y][x];
		}
	}

	//게임 오버 카운팅은 숫자 출력해주면서 찾기
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			if (input[y][x] == '.') {
				result[y][x] = '.';
			}
			else if (input[y][x] == 'x') {
				if (mine[y][x] == '*') {
					gameover = 1;
				}

				count = 0;
				for (int i = 0; i < 8; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					//out of range 검사
					if (ny<0 || nx<0 || ny >= num || nx >= num) {
						continue;
					}
					if (mine[ny][nx] == '*') {
						count++;
					}
				}
				result[y][x] = (char) (count + '0');
			}
		}
	}
	
	//지뢰 표시해주기
	if (gameover == 1) {
		for (int y = 0; y < num; y++) {
			for (int x = 0; x < num; x++) {
				if (mine[y][x] == '*') {
					result[y][x] = '*';
				}
			}
		}
	}

	//출력
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			cout << result[y][x];
		}
		cout << endl;
	}

	return 0;
}
//지뢰에 걸린 경우, 걸리지 않은 경우 나눠서 출력한다.