#include <iostream>
#include <vector>

using namespace std;
struct info {
	int x;
	int y;
};

//우하좌상
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
	int ny;
	int nx;
	int num;
	cin >> num;
	info strat_point;
	//변의 길이
	int size = 4 * (num - 1) + 1;
	int temp_size = size;
	//시작지점, 얼마의 크기만큼 변을 그리는가, 몇번이나 안으로 들어가는가
	//별을 하나 찍어야하는 경우 -> 시작지점만 찍고 변의 길이는 4씩 줄어들어서 1만 찍는 경우

	vector<vector<char>>board(size, vector<char>(size, ' '));

	//밖의 for문 한번당 사각형 하나
	for (int i = 0; i < num; i++) {
		//시작지점 인덱스
		strat_point.y = i * 2;
		strat_point.x = i * 2;
		ny = strat_point.y;
		nx = strat_point.x;
		board[ny][nx] = '*';//시작지점에 하나 찍어주고
		
		for (int j = 0; j < 4; j++) {
			//이동 횟수이므로 변의 길이 -1 만큼한다
			for (int resize = temp_size - 1; resize > 0; resize--) {
				ny = ny + dy[j];
				nx = nx + dx[j];
				board[ny][nx] = '*';
			}
		}
		temp_size = temp_size - 4;
	}

	//출력
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			cout << board[y][x];
		}
		cout << "\n";
	}

	return 0;
}