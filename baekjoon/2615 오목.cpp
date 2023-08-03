#include <iostream>
#include <vector>

using namespace std;

struct info {
	int y;
	int x;
};

//우하, 우, 하, 우상으로만 탐색
int dy[] = {1, 0, 1, -1};
int dx[] = {1, 1, 0, 1};

//지금 방식으로 하면 6짜리 처음에만 지나치고 뒤에는 맞았다고 함.
info search_point(vector<vector<int>>& board,int y, int x, int winner) {
	info win_point;
	win_point.y = -1;
	win_point.x = -1;
	//시작 지점이 y,x이다.
	int ny = y;
	int nx = x;
	int count = 0;

	for (int i = 0; i < 4; i++) {
		//초기 좌표, 카운팅 초기화
		ny = y;
		nx = x;
		count = 0;
		while (winner == board[ny][nx]) {//현재 좌표 검사
			count++;
			ny = ny + dy[i];//다음 좌표 생성
			nx = nx + dx[i];
			//out of range 검사
			if (ny < 0 || ny >= 19 || nx < 0 || nx >= 19) {
				break;
			}
		}
		
		//카운트가 5이면
		if (count == 5) {
			ny = y - dy[i];
			nx = x - dx[i];

			//만일 6이나 그 이상의 선 위에 있는 경우일 뿐이라면
			if (ny < 0 || ny >= 19 || nx < 0 || nx >= 19) {
				//out of range인 경우 제외
			}
			else {
				if (board[ny][nx] == winner) {
					continue;
				}
			}
			win_point.y = y;
			win_point.x = x;
			break;
		}
	}
	return win_point;
}

//여섯알이 연속했을때는 이긴게 아님
//둘이 동시에 이기거나, 여러 장소에서 이기는 경우 없음.
//이긴 장소의 위치도 출력해야 함
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	vector<vector<int>> board(19, vector<int>(19, 0));
	int winner = 0;
	info win_point;

	win_point.y = -1;//아닐때 초기값
	win_point.x = -1;//아닐때 초기값

	//보드판 입력
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {
			cin >> board[y][x];
		}
	}

	//탐색함수(왼쪽에서 오른쪽 부터)
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {
			if (board[y][x] == 0) {//아무것도 안 들어있으면 패스
				continue;
			}
			winner = board[y][x];
			win_point = search_point(board, y, x, winner);
			if (win_point.y != -1) {
				break;
			}
		}
		if (win_point.y != -1) {
			break;
		}
	}

	//결과 출력
	if (win_point.y != -1) {//찾았으면
		cout << winner << "\n" << win_point.y + 1 << " " << win_point.x + 1;
	}
	else {//못찾음
		cout << 0;
	}

	return 0;
}
//특정 돌이 놓인 지점을 기준으로 좌, 좌상, 상, 좌하로 끝까지가서
//해당 지점을 카운팅 시작 지점으로 잡는다.

//위와 같은 알고리즘 없이 그냥 돌 하나당 하나씩 검사.
//탐색을 여덟방향으로 할 필요 없이, 우, 우상, 하, 우하로만 탐색하고,
//시작 지점은 좌->우하 로 탐색해나가면 알아서 왼쪽 최상단의 정답지점이 나옴