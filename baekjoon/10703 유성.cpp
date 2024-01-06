//시작 13시 50분
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	//똥피하기 결과 구현한다고 생각하기
	int height;
	int width;
	
	cin >> height;
	cin >> width;

	vector<vector<char>> board(height, vector<char>(width, '.'));
	//입력
	//의문: 입력 값이 whitespace로 구분이 안 되어있어도 char형이면 알아서 입력 되나?
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> board[y][x];
		}
	}

	int min_dist = 3000;//최소한 내려오는 거리. x를 고정해두고 구하기
	int temp_dist = 0;
	int start_index = -1;
	int end_index = -1;
	for (int x = 0; x < width; x++) {
		start_index = -1;//운석의 끝
		end_index = -1;//땅의 시작
		for (int y = 0; y < height; y++) {
			if (board[y][x] == 'X') {//나올때마다 갱신
				start_index = y;
			}
			//땅은 나오자마자 갱신
			if (board[y][x] == '#' && end_index == -1) {
				end_index = y;
			}
		}
		if (start_index != -1) {//운석이 있는 부분이면
			temp_dist = end_index - start_index - 1;
			min_dist = min(min_dist, temp_dist);
		}
	}

	vector<vector<char>> answer(height, vector<char>(width, '.'));
	int count;
	int new_y = height - 1;
	int land_end_index;
	for (int x = 0; x < width; x++) {
		count = 0;
		new_y = height - 1;
		//땅 시작 y좌표 구해두기
		for (int i = 0; i < height; i++) {
			if (board[i][x] == '#') {
				land_end_index = i;
				break;
			}
		}
		for (int y = height-1; y >= 0; y--) {//덜 덮어 씌워줌
			//배열을 아래에서부터 복사. 복사하는 과정에서 생략
			if (y<land_end_index && count < min_dist) {
				count++;
				continue;//복사 안 해주고 넘어가기
			}
			answer[new_y][x] = board[y][x];
			new_y--;
		}
	}

	//출력
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << answer[y][x];
		}
		cout << endl;
	}
	return 0;
}