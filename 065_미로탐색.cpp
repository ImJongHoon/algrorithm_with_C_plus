#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(7, vector<int>(7, 0));
vector<vector<int>> visited(7, vector<int>(7, 0));

int cnt = 0;

int dy[] = {0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0 };

//y와 x는 인자로서 다음 좌표를 받는다.
//사용되는건 현재의 좌표로 사용되고.
void dfs(int y, int x) {
	if (y == 6 && x == 6) {
		cnt++;
	}
	else {
		int ny;
		int nx;

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 7 || nx >= 7 || map[ny][nx] == 1 || visited[ny][nx] == 1) {

			}
			else {
				visited[ny][nx] = 1;
				dfs(ny, nx);
				visited[ny][nx] = 0;
			}
			
		}
	}
}

int main() {
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			cin >> map[y][x];
		}
	}

	visited[0][0] = 1;
	dfs(0, 0);

	cout << cnt;

	return 0;
}