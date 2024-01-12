#include <iostream>
#include <vector>
#include <queue>

//검사해야하는 위치까지 큐로 저장해서 시간복잡도를 최소화하였으나.
//이분법을 사용하지 않아 시간초과를 해결할 수 없었음.

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct info {
	int y;
	int x;
};

int BFS(int y, int x, vector<vector<char>> board, vector<vector<char>>& next_board, vector<vector<int>>& visited, int R, int C, info end) {
	queue<info> q;
	q.push({ y, x });
	visited[y][x] = 1;

	int res = 0;

	info current;

	int ny, nx;

	while (!q.empty()) {
		current = q.front();

		if (current.y == end.y && current.x == end.x) {
			res = 1;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = current.y + dy[i];
			nx = current.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] == 1) {
				continue;
			}
			if (board[ny][nx] == 'X') {
				//다음 board에 얼음이 녹았도록 처리.
				next_board[ny][nx] = '.';
				continue;
			}
			

			q.push({ ny, nx });
			//push하자마자 방문처리를 해주는가?
			//그렇다면 
			visited[ny][nx]=1;
		}
	}

	return res;
}

int main() {
	//1500x1500 = 225만
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int R, C;

	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	vector<vector<char>> next_board(R, vector<char>(C));

	
	vector<vector<int>> visited(R, vector<int>(C, 0));

	info start = {-1, -1};
	info end = { -1, -1 };

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];

			if (board[y][x] == 'L' && start.y == -1) {
				start = { y, x };
			}
			else if (board[y][x] == 'L' && start.y != -1) {
				end = { y, x };
			}
		}
	}

	//일단 값 복사
	next_board = board;
	
	int isMeet = 0;
	int count = -1;

	queue<info> startPoint;
	queue<info> tempQueue;

	while (isMeet == 0) {

		//상태 출력해보기
		/*for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cout << board[y][x];
			}
			cout << '\n';
		}*/
		
		//만날 수 있는가? -> BFS or DFS 사용
		isMeet = BFS(start.y, start.x, board, next_board, visited, R, C, end);
		count++;
		//얼음이 얼마나 녹는가? BFS중 X에 막혀서 진행하지 못하는 부분이 전부 녹는 것.
		if (isMeet == 1) {
			break;
		}

		//방문처리 초기화
		visited = vector<vector<int>>(R, vector<int>(C, 0));

		//얼음 녹이기
		//여기가 일일이 검사해서 시간 초과인듯 하니, 맨 처음에 얼음이 녹아있는 구역만 구해서 queue에 추가하는 방식으로 만들기.
		if (count == 0) {
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					if (visited[y][x] == 1 || board[y][x] == 'X') {
						continue;
					}
					startPoint.push({y, x});
					BFS(y, x, board, next_board, visited, R, C, end);
				}
			}
		}
		else {
			while (!startPoint.empty()) {
				BFS(startPoint.front().y, startPoint.front().x, board, next_board, visited, R, C, end);
				tempQueue.push(startPoint.front());
				startPoint.pop();
			}

			//queue 다시 복사
			startPoint = tempQueue;
		}

		//방문처리 초기화
		visited = vector<vector<int>>(R, vector<int>(C, 0));
		//다음 board로 변경
		board = next_board;
	}
	
	
	cout << count;

	return 0;
}